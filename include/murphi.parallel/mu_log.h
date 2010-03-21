
#define ENABLE_FILE_LOGGING  // Could also be passed on command line

#if !defined(__MU_LOG_H_) && !defined(ENABLE_FILE_LOGGING)
// Define logging macros to be empty
#  define LOG_INIT(file_name) ;
#  define LOG_VERBOSE(msg ...) ;
#  define LOG_VERBOSE_LIMIT_FREQUENCY(id, msg ...);
#  define LOG_WARNING(msg ...) ;
#  define LOG_FATAL(msg ...) ;

#elif !defined(__MU_LOG_H_) && defined(ENABLE_FILE_LOGGING)
#define __MU_LOG_H_

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>

static const unsigned int NUM_WRITES_TILL_TRUNCATE = 40000;
static const unsigned int NUM_WRITES_SETBACK_TRUNCATE = 20000;

class LogFile
{
 public:
  
 LogFile() 
   : m_file(NULL), m_initialized(false), m_numWritesInFile(0), m_numBytesWrittenSinceTruncate(0)
 { 
   m_filename[0] = '\0';
   pthread_mutex_init(&m_mutex, NULL);
 }

  ~LogFile()
    {
      if (m_file != NULL)
	fclose(m_file);
    }

  //
  // initializer - Open the logfile for writing, truncate
  //
  void init(const char* filename)
  {
    m_file = fopen(filename, "w+");

    if (m_file == NULL)
	Error.Notrace("ERROR could not create logfile %s\n", filename);
    else
      m_initialized = true;

    strncpy(m_filename, filename, sizeof(m_filename));
    m_filename[sizeof(m_filename) - 1] = '\0';
  }


  //
  // Main write routine.  First writes prolog (if non-NULL), then the bodyFormatted
  // which can be formatted in printf style.
  void logWrite(const char *prolog, const char *bodyFormatted, va_list argp)
  {
    assert (m_initialized);

    int status;
    int result;

    // Write a time-stamp
    double mpitime = MPI_Wtime();
    char mpiTimeBuf[32];
    snprintf(mpiTimeBuf, sizeof(mpiTimeBuf), "%.2f   ", mpitime);

    pthread_mutex_lock(&m_mutex);

    result = fwrite(mpiTimeBuf, 1, strlen(mpiTimeBuf), m_file);
    if (result == 0)
      Error.Notrace("ERROR fputs writing time in %s\n", __PRETTY_FUNCTION__);
    m_numBytesWrittenSinceTruncate += result;

    // If there is a prolog, write it
    if (prolog != NULL)
      {
	result = fwrite(prolog, 1, strlen(prolog), m_file);
	if (result == 0)
	    Error.Notrace("ERROR fputs in %s\n", __PRETTY_FUNCTION__);
	m_numBytesWrittenSinceTruncate += result;
      }

    // Write the formatted body
    result = vfprintf(m_file, bodyFormatted, argp);
    if (result < 0)
	Error.Notrace("Error fvprintf in %s\n", __PRETTY_FUNCTION__);
    m_numBytesWrittenSinceTruncate += result;

    fflush(m_file);

    m_numWritesInFile++;

    // If this is the first time passing the setback value, reset writes written
    if (m_numWritesInFile == NUM_WRITES_SETBACK_TRUNCATE)
      m_numBytesWrittenSinceTruncate = 0;

    if (m_numWritesInFile >= NUM_WRITES_TILL_TRUNCATE)
      {
	logTruncateFileHead();
	m_numBytesWrittenSinceTruncate = 0;
	m_numWritesInFile = NUM_WRITES_SETBACK_TRUNCATE;
      }
    pthread_mutex_unlock(&m_mutex);
  }

 private:  
  //
  // Perform a "truncate" of the first portion of the logfile, according to the global size parameters.
  //
  void logTruncateFileHead()
  {
    // temp file name
    char newFilename[80];
    snprintf(newFilename, sizeof(newFilename), "%s.temptrunc", m_filename);

    // Open the temp file
    FILE *tempFile = fopen(newFilename, "w+");
    if (tempFile == NULL)
      Error.Notrace("Error with fopen in %s.\n", __PRETTY_FUNCTION__);

    // stat the current log file
    struct stat fileStats;
    if (stat(m_filename, &fileStats) != 0)
      Error.Notrace("Could not stat logfile in %s.\n", __PRETTY_FUNCTION__);

    if (fileStats.st_size < m_numBytesWrittenSinceTruncate)
      {
	// seek to the beginning of the file
	if (fseek(m_file, 0, SEEK_SET) != 0)
	  Error.Notrace("Error in fseek in %s.\n", __PRETTY_FUNCTION__);
      }
    else
      {
	// Otherwise, seek NUM_BYTES... back
	if (fseek(m_file, -1*m_numBytesWrittenSinceTruncate, SEEK_END) != 0)
	  Error.Notrace("Error in fseek in %s.\n", __PRETTY_FUNCTION__);
      }

    // Now the file pointer is in the correct position
    // copy the file contents into the temp file

    fputs("... LOG FILE TRUNCATED ...\n", tempFile);

    char fileBuf[2048];
    int bytesRead = 0;
    int bytesWritten = 0;
    for (int bytesToRead = m_numBytesWrittenSinceTruncate; bytesToRead > 0; bytesToRead -= bytesRead)
      {
	// read from the file
	bytesRead = fread(fileBuf, 1, sizeof(fileBuf), m_file);

	if (bytesRead == 0)
	    break;

	// write to the temp file
	bytesWritten = fwrite(fileBuf, 1, bytesRead, tempFile);

	assert(bytesRead == bytesWritten);
      }

    // Close and delete the current log file
    fclose(m_file);
    if (remove(m_filename) != 0)
      Error.Notrace("Error with remove in %s.\n", __PRETTY_FUNCTION__);

    // Close the temp file
    fclose(tempFile);

    // Rename the temp file to the original log file
    if (rename(newFilename, m_filename) != 0)
      Error.Notrace("Error with rename in %s.\n", __PRETTY_FUNCTION__);

    // Reopen the log file, for reading/writing, set seek to end
    m_file = fopen(m_filename, "a+");
    if (m_file == NULL)
      Error.Notrace("Error reopening log file in %s.\n", __PRETTY_FUNCTION__);
    
    if (fseek(m_file, 0, SEEK_END) != 0)
      Error.Notrace("Error in fseek in %s.\n", __PRETTY_FUNCTION__);
  }

 private:
  char m_filename[64];
  FILE *m_file;
  bool m_initialized;
  int m_numWritesInFile;
  int m_numBytesWrittenSinceTruncate;
  pthread_mutex_t m_mutex;
};


// log file instance
static LogFile _file;


/*  File logging functions */

static inline void LOG_INIT(int rank)
{
  char filename[64];
  snprintf(filename, sizeof(filename), "em.%s.node%d.log", PROTOCOL_NAME, rank);
  _file.init(filename);
}

static inline void LOG_VERBOSE(const char *msg ...)
{
  va_list args;
  va_start(args, msg);

  _file.logWrite(NULL, msg, args);

  va_end(args);
}


// ids for LOG_VERBOSE_LIMIT_FREQUENCE

const unsigned int CLOSED_HASH_TABLE_ID = 0;
const unsigned int WORKER_LOOP_ID = 1;
const unsigned int COMM_LOOP_ID = 2;
const unsigned int STATE_QUEUE_ID = 4;
const unsigned int COMM_QUEUE_ID = 5;
const unsigned int ACTIVE_ID = 6;
const unsigned int COMM_QUEUE_PENDING_ID = 7;

const unsigned int MAX_ID_COUNT = 8;
static time_t g_lastPrintTime[MAX_ID_COUNT] = {0, 0, 0, 0, 0, 0, 0, 0};

// Allows multiple ids for multiple limits
static inline void LOG_VERBOSE_LIMIT_FREQUENCY(int id, int num_seconds, const char *msg ...)
{
  va_list args;
  timeval time;

  assert(id >= 0 && id < MAX_ID_COUNT);  // sanity

  gettimeofday(&time, NULL);

  //
  // If we have printed within num_seconds, return without logging
  //  this is not a precise calculation of a second and that's fine
  if (time.tv_sec - g_lastPrintTime[id] <= num_seconds)
    return;

  g_lastPrintTime[id] = time.tv_sec;

  // Log the message
  va_start(args, msg);
  _file.logWrite(NULL, msg, args);
  va_end(args);
}

static inline bool LOG_LIMIT_AVAIL(int id, int num_seconds)
{
  timeval time;

  assert(id >= 0 && id < MAX_ID_COUNT);

  gettimeofday(&time, NULL);

  //
  // If we have called within num_seconds, return false
  if (time.tv_sec - g_lastPrintTime[id] <= num_seconds)
    return false;

  g_lastPrintTime[id] = time.tv_sec;

  // Otherwise, return true
  return true;
}

static inline void LOG_WARNING(const char *msg ...)
{
  va_list args;
  va_start(args, msg);

  _file.logWrite("WARNING: ", msg, args);

  va_end(args);
} 

static inline void LOG_FATAL(const char *msg ...)
{
  va_list args;
  va_start(args, msg);

  _file.logWrite("FATAL ERROR: ", msg, args);

  va_end(args);
}


#endif
