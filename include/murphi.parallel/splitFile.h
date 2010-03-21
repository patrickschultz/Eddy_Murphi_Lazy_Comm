/* -*- C++ -*- 
 * splitFile.h
 * @(#) header for large file handling class
 *
 * Copyright (C) 2001 - 2003 by Giuseppe Della Penna              
 * Universita' degli Studi di L'Aquila
 * 
 * Read the file "license" distributed with these sources, or call
 * Murphi with the -l switch for additional information.
 * 
 */

/* 
 * Original Author: G. Della Penna
 * Created: 01 Oct 2001
 * Released: 30 Jan 2003
 *       
 */

/*
 * This file handling class was designed to fix a problem with
 * Linux EXT2 filesystem, that does not handle by default files
 * larger that 1Gb. This problem could also appear on other
 * filesystems, so I decided to write a file class that handles
 * very large "virtual" files storing them on many smaller files.
 * The splitFile class has methods to handle all the normal file
 * operations. Moreover, all the disk-access routines specify
 * lengths (i.e. number of bytes to read, position to seek...)
 * using two unsigned long integers: size and count. The number
 * of bytes requested, e.g. the position to seek to in the file,
 * is size*count.
 *
 * WARNING: the class has been tested in disk murphi only.
 * Some minor functions can still contain bugs.
 * 
 */

#ifndef _SPLITFILE_
#define _SPLITFILE_

#define DEFAULTDIR 0
#define FORWARD 1
#define BACKWARD 2

class splitFile
{
public:
  splitFile (unsigned long splitsize, bool permanent = true);
   ~splitFile ();
  bool open (char *filename, char *access);
  void close ();
  unsigned long read (void *buffer, unsigned long size, unsigned long count);
  unsigned long write (void *buffer, unsigned long size, unsigned long count);
  unsigned long tell (unsigned long size = 1);
  void seek (unsigned long size, unsigned long count, int from,
	     int direction = DEFAULTDIR);
  void seek (unsigned long count, int from);
  bool eof ();
  char *getBaseFileName ()
  {
    return _filename;
  }
  void setPermanent (bool perm)
  {
    _permanent = perm;
  }
  char *make_unique_filename (char *basepathname, bool with_protocol_name = true);

protected:
  void CreateNextPart ();
  bool OpenNextPart ();
  bool GotoNextPart (bool write_mode);
  inline unsigned long curfilepos ();
  inline unsigned long getpartsize (int npart);
  unsigned long writebytes (void *buffer, unsigned long size);
  unsigned long readbytes (void *buffer, unsigned long size);
  bool seekbytes (unsigned long size, int direction, int &part,
		  unsigned long &skip);

private:
  char _access[10];
  char _filename[1020];
  bool _permanent;
  FILE *parts[100];
  unsigned long partsize[100];
  int maxpart, curpart;
  unsigned long _splitsize;
  bool _eof;

  /* check for type size invariants only once */
  static bool sizechecks;
};


#endif

/********************
  $Log: mu_splitFile.C,v $

  Revision 3.0  2003/02/13 13:34:40  giuseppe 
  unaligned block operation bug fix (VERY important!)

  Revision 2.0  2003/01/10 17:06:12  giuseppe 
  disk extension - final release

  Revision 1.2  2001/10/28 21:50:00  giuseppe 
  disk algorithm complete - start testing

  Revision 1.1  2001/10/01 18:41:14  giuseppe 
  Initial revision

********************/
