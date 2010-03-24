/* -*- C++ -*-
 * mu_state.C
 * @(#) Auxiliary routines related to states in the verifier
 *
 * Copyright (C) 1992 - 1999 by the Board of Trustees of              
 * Leland Stanford Junior University.
 *
 * License to use, copy, modify, sell and/or distribute this software
 * and its documentation any purpose is hereby granted without royalty,
 * subject to the following terms and conditions:
 *
 * 1.  The above copyright notice and this permission notice must
 * appear in all copies of the software and related documentation.
 *
 * 2.  The name of Stanford University may not be used in advertising or
 * publicity pertaining to distribution of the software without the
 * specific, prior written permission of Stanford.
 *
 * 3.  This software may not be called "Murphi" if it has been modified
 * in any way, without the specific prior written permission of David L.
 * Dill.
 *
 * 4.  THE SOFTWARE IS PROVIDED "AS-IS" AND STANFORD MAKES NO
 * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, BY WAY OF EXAMPLE,
 * BUT NOT LIMITATION.  STANFORD MAKES NO REPRESENTATIONS OR WARRANTIES
 * OF MERCHANTABILITY OR FITNESS FOR ANY PARTICULAR PURPOSE OR THAT THE
 * USE OF THE SOFTWARE WILL NOT INFRINGE ANY PATENTS, COPYRIGHTS
 * TRADEMARKS OR OTHER RIGHTS. STANFORD SHALL NOT BE LIABLE FOR ANY
 * LIABILITY OR DAMAGES WITH RESPECT TO ANY CLAIM BY LICENSEE OR ANY
 * THIRD PARTY ON ACCOUNT OF, OR ARISING FROM THE LICENSE, OR ANY
 * SUBLICENSE OR USE OF THE SOFTWARE OR ANY SERVICE OR SUPPORT.
 *
 * LICENSEE shall indemnify, hold harmless and defend STANFORD and its
 * trustees, officers, employees, students and agents against any and all
 * claims arising out of the exercise of any rights under this Agreement,
 * including, without limiting the generality of the foregoing, against
 * any damages, losses or liabilities whatsoever with respect to death or
 * injury to person or damage to property arising from or out of the
 * possession, use, or operation of Software or Licensed Program(s) by
 * LICENSEE or its customers.
 *
 * Read the file "license" distributed with these sources, or call
 * Murphi with the -l switch for additional information.
 * 
 */

/* 
 * Original Author: Ralph Melton
 * Extracted from mu_epilog.inc and mu_prolog.inc
 * by C. Norris Ip
 * Created: 21 April 93
 *
 * Update:
 *
 */

/****************************************
  There are 3 groups of implementations:
  1) bit vector
  2) class StatePtr and state related stuff
  3) state queue and stack
  4) state set
  ****************************************/

#include "mu_log.h"

/* IM<b> */
#define SSQ_PAGING_FILE_TOP "SSQ_PAGING_FILE_1"
#define SSQ_PAGING_FILE_BOTTOM "SSQ_PAGING_FILE_2"
/* IM<e> */

void
state::print ()
{
  theworld.print ();
};

/****************************************
  Bit vector - copied straight from Andreas. 
  ****************************************/
dynBitVec::dynBitVec (unsigned long nBits)
  :
numBits (nBits)
{
  v = new unsigned char[NumBytes ()];	/* Allocate and clear vector. */
  ErrAlloc (v);
  memset (v, 0, NumBytes ());
};

dynBitVec::~dynBitVec ()
{
  delete[OLD_GPP (NumBytes ())]v;	// should be delete[].
}


/****************************************
  class StatePtr and state related stuff.
  ****************************************/

inline void
StatePtr::sCheck ()
{
#ifdef HASHC
/* IM<b> */
#ifdef HASHC_TRACE
/* IM<e> */
  if (args->trace_file.value)
    Error.Notrace ("Internal: Illegal Access to StatePtr.");
/* IM<b> */
#endif
/* IM<e> */
#endif
}

inline void
StatePtr::lCheck ()
{
#ifdef HASHC
/* IM<b> */
#ifdef HASHC_TRACE
/* IM<e> */
  if (!args->trace_file.value)
    Error.Notrace ("Internal: Illegal Access to StatePtr.");
/* IM<b> */
#endif
/* IM<e> */
#endif
}

/* IM<b> */
/*StatePtr::StatePtr (state * s)
{
  sCheck ();
  sp = s;
}
StatePtr::StatePtr (unsigned long l)
{
  lCheck ();
  lv = l;
}

void
StatePtr::set (state * s)
{
  sCheck ();
  sp = s;
}

void
StatePtr::set (unsigned long l)
{
  lCheck ();
  lv = l;
}

void
StatePtr::clear ()
{
#ifdef HASHC
  if (args->trace_file.value)
    lv = 0;
  else
#endif
    sp = NULL;
}*/

StatePtr::StatePtr (unsigned long l, int rank)
{
  lCheck ();
  lv = l;
  this->rank = rank;
}

void
StatePtr::set (unsigned long l, int rank)
{
  lCheck ();
  lv = l;
  this->rank = rank;
}

void
StatePtr::clear (int rank)
{
#ifdef HASHC
/* IM<b> */
#ifdef HASHC_TRACE
/* IM<e> */
  if (args->trace_file.value) {
    lv = 0;
    this->rank = rank;
  }
/* IM<b> */
#endif
/* IM<e> */
#endif
}

/* IM<e> */

state *
StatePtr::sVal ()
{
  sCheck ();
  return sp;
}
unsigned long
StatePtr::lVal ()
{
  lCheck ();
  return lv;
}

StatePtr
StatePtr::previous ()
{				// return StatePtr to previous state
#ifdef HASHC
/* IM<b> */
#ifdef HASHC_TRACE
/* IM<e> */
  if (args->trace_file.value)
    /* IM<b> */
    /*return TraceFile->read (lv)->previous;*/
    return StatePtr(TraceFile->read (lv, rank)->previous, TraceFile->read (lv, rank)->rank);
    /* IM<e> */
  else
/* IM<b> */
#endif
/* IM<e> */
#endif
    /* IM<b> */
    /*return sp->previous.sp;*/
    ;
    /* IM<e> */
}

bool
StatePtr::isStart ()
{				// check if I point to a startstate
#ifdef HASHC
/* IM<b> */
#ifdef HASHC_TRACE
/* IM<e> */
  if (args->trace_file.value) {
    /* IM<b> */
    /*if (TraceFile->read (lv)->previous == 0)*/
    if (TraceFile->read (lv, rank)->previous == 0)
    /* IM<e> */
      return TRUE;
    return FALSE;
  }
  else
/* IM<b> */
#endif
/* IM<e> */
#endif
  /* IM<b> */
  /* This will never be executed */
  /* IM<e> */
  {
    if (sp->previous.sp == NULL)
      return TRUE;
    return FALSE;
  }
}

#define BITUNSIGNED 32//sizeof(Unsigned32)*CHAR_BIT

bool
StatePtr::compare (state * s)
{				// compare the state I point to with s
#ifdef HASHC
/* IM<b> */
#ifdef HASHC_TRACE
/* IM<e> */
  if (args->trace_file.value) {
    uint32_t * key;
    if (rank != 0) {
      if (h3_others[rank - 1] == NULL)
	h3_others[rank - 1] = new hash_function (Communicate->GetHashmatrix (rank), BLOCKS_IN_WORLD);
      key = h3_others[rank - 1]->hash (s, FALSE);
    }
    else
      key = h3->hash (s, FALSE);
      /* IM<e> */
#if __WORDSIZE == 32
    unsigned long 
#else
    unsigned int 
#endif
      c1 = key[1] &
#if __WORDSIZE == 32
      ((~0UL) << (args->num_bits.value > BITUNSIGNED? 0UL : BITUNSIGNED - args->num_bits.value));
#else
      ((~0) << (args->num_bits.value > BITUNSIGNED? 0 : BITUNSIGNED - args->num_bits.value));
#endif
#if __WORDSIZE == 32
    unsigned long 
#else
    unsigned int 
#endif
      c2 = key[2] &
      (args->num_bits.value >
#if __WORDSIZE == 32
       BITUNSIGNED ? (~0UL) << (2*BITUNSIGNED - args->num_bits.value) : 0UL);
#else
       BITUNSIGNED ? (~0) << (2*BITUNSIGNED - args->num_bits.value) : 0);
#endif

    /* IM<b> */
    /*return (c1 == TraceFile->read (lv)->c1 && c2 == TraceFile->read (lv)->c2);*/
    return (c1 == TraceFile->read (lv, rank)->c1 && c2 == TraceFile->read (lv, rank)->c2);
    /* IM<e> */
  }
  else
/* IM<b> */
#endif
/* IM<e> */
#endif
    return (StateCmp (sp, s) == 0);
}


void
StateCopy (state * l, state * r)
// Uli: uses default assignment operator
{
  *l = *r;
}

int
StateCmp (state * l, state * r)
{
  int i = BLOCKS_IN_WORLD / 4;
  register int *d = (int *) l->bits, *s = (int *) r->bits;

  while (i--)
    if (*d > *s)
      return 1;
    else if (*d++ < *s++)
      return -1;
  return 0;
}

void
copy_state (state * &s)
{
  state *h;

  if ((h = new state) == NULL)
    Error.Notrace
      ("New failed. Swap space probably too small for state queue.");
  *h = *s;
  s = h;
}

bool
StateEquivalent (state * l, StatePtr r)
{
  return match (l, r);
}

/****************************************
  class state_queue for searching the state space.
  ****************************************/
state_queue::state_queue (unsigned long mas)
:max_active_states (mas), num_elts (0), front (0), rear (0)
{
  /* IM<b> */
  /*stateArray = new state *[max_active_states];

  for (long i = 0; i < max_active_states; i++)	// Uli: avoid bzero
    stateArray[i] = NULL;*/

  stateArray = new struct state_bool[max_active_states];

#ifndef SPLITFILE
  if ((paging_file_top = tmpfile ()) == NULL) {
    Error.Notrace ("Internal: Error creating top paging file.");
  }

  if ((paging_file_bottom = tmpfile ()) == NULL) {
    Error.Notrace ("Internal: Error creating bottom paging file.");
  }
#else
  paging_file_top = new splitFile (SPLITFILE_LEN, false);
  paging_file_bottom = new splitFile (SPLITFILE_LEN, false);

  char basepathname[1024];
  sprintf(basepathname, "%s%s", args->dir_queue_file == NULL? "./" : args->dir_queue_file, SSQ_PAGING_FILE_TOP);
  if (!(paging_file_top->open (paging_file_top->make_unique_filename (basepathname), "w+b"))) {
    Error.Notrace ("Internal: Error creating top paging file for the queue.");
  }

  sprintf(basepathname, "%s%s", args->dir_queue_file == NULL? "./" : args->dir_queue_file, SSQ_PAGING_FILE_BOTTOM);
  if (!(paging_file_bottom->open (paging_file_bottom->make_unique_filename (basepathname), "w+b"))) {
    Error.Notrace ("Internal: Error creating bottom paging file for the queue.");
  }
#endif
  num_elts_head = num_elts_tail = 0;

  head_begin = 0;
  tail_begin = max_active_states / 2;

  head_size = max_active_states / 2;
  tail_size = max_active_states - head_size;

  global_front = global_rear = front = rear = 0;
  /* IM<e> */
};

state_queue::~state_queue ()
{
  delete[OLD_GPP (max_active_states)] stateArray;	// Should be delete[].
/* IM<b> */
#ifndef SPLITFILE
  fclose (paging_file_top);
  fclose (paging_file_bottom);
#else

  paging_file_top->close ();
  paging_file_bottom->close ();

  delete paging_file_top;
  delete paging_file_bottom;
#endif
/* IM<e> */
}

int
state_queue::BytesForOneState (void)
{

#ifdef VER_PSEUDO
  // Pseudo ver: ptr + malloced state + approx. malloc&new overhead.
  return sizeof (state *) + sizeof (state) + 8;
#else
  return sizeof (state *);	/* Full ver: only a ptr to state. */
#endif
}

void
state_queue::Print (void)
{
  /* IM<b> */
  /*unsigned long i;
  unsigned long ind = front;
  for (i = 1; i < num_elts; i++) {
    // convert to print in unsigned long format?
    cout << "State " << i << " [" << ind << "]:\n";
    stateArray[ind]->print ();
    ind = (ind + 1) % max_active_states;
  }*/
  /* IM<e> */
}

void
state_queue::enqueue (state * e)
{
  /* IM<b> */
  assert(false); /* not called any more */
  /* IM<e> */
  if (num_elts < max_active_states) {
    /* IM<b> */
    /*stateArray[rear] = e;*/
    /* IM<e> */
    rear = (rear + 1) % max_active_states;
    num_elts++;
  }
  else {
    Error.Notrace ("Internal Error: Too many active states.");
  }
}

/* IM<b> */
void
state_queue::enqueue (state *&e, bool checked, unsigned long num_cur_state)
{
  mutexes->LockMutex(MUTEX_Q);
  if (num_elts_tail >= tail_size) {	//memory full: reclaim more space by swapping out the current queue
    ReclaimFreeSpace ();
  }
  /*
     at this point, ReclaimFreeSpace has obtained new space in the queue and
     set the offsets (front, rear, ...) accordingly; so we proceed with
     the insertion without checking...
   */
  StateCopy (&stateArray[tail_begin + rear].s, e);
  e = &stateArray[tail_begin + rear].s;
  stateArray[tail_begin + rear].checked = checked;
#ifdef HASHC_TRACE
  stateArray[tail_begin + rear].num_cur_state = num_cur_state;
#endif
  rear++;
  num_elts_tail++;
  mutexes->UnLockMutex(MUTEX_Q);

  /*mutexes->LockMutex(MUTEX_Q);
  if (num_elts < max_active_states) {
    stateArray[rear] = e;
    if (checked) Checked->set(rear);
    else Checked->clear(rear);
    rear = (rear + 1) % max_active_states;
    num_elts++;
  }
  else {
    mutexes->UnLockMutex(MUTEX_Q);
    Error.Notrace ("Internal Error: Too many active states.");
  }
  mutexes->UnLockMutex(MUTEX_Q);*/
}

/* IM<e> */

state *
state_queue::dequeue (void)
{
  /* IM<b> */
  assert(false); /* not called any more */
  /* IM<e> */
  state *retval;
  if (num_elts > 0) {
    /* IM<b> */
    /*retval = stateArray[front];*/
    /* IM<e> */
    front = (front + 1) % max_active_states;
    num_elts--;
  }
  else {
    Error.Notrace ("Internal: Attempt to dequeue from empty state queue.", "",
		   "");
  }
  return retval;
}

/* IM<b> */
state *
state_queue::dequeue (bool &checked)
{
  mutexes->LockMutex(MUTEX_Q);
  state *retval;

  if (num_elts_head <= 0) {
    QueueEmptyFault ();
  }

  retval = &stateArray[head_begin + front].s;
  checked = stateArray[head_begin + front].checked;
  front++;
  num_elts_head--;

  LOG_VERBOSE_LIMIT_FREQUENCY(STATE_QUEUE_ID, 1, " (states) State queue contains %d elements (in dequeue).\n", NumElts());

  mutexes->UnLockMutex(MUTEX_Q);
  return retval;
}

#ifdef HASHC_TRACE
state *
state_queue::dequeue (bool &checked, unsigned long &num_cur_state)
{
  mutexes->LockMutex(MUTEX_Q);
  state *retval;

  if (num_elts_head <= 0) {
    QueueEmptyFault ();
  }

  retval = &stateArray[head_begin + front].s;
  checked = stateArray[head_begin + front].checked;
  num_cur_state = stateArray[head_begin + front].num_cur_state;
  front++;
  num_elts_head--;

  LOG_VERBOSE_LIMIT_FREQUENCY(STATE_QUEUE_ID, 1, " (states) State queue contains %d elements (in dequeue).\n", NumElts());

  mutexes->UnLockMutex(MUTEX_Q);
  return retval;
}

/* hyp: getNumCurState always called immediately after a dequeue */
unsigned long state_queue::getNumCurState () 
{
  unsigned long retval;
  
  mutexes->LockMutex(MUTEX_Q);
  retval = stateArray[head_begin + front - 1].num_cur_state; 
  mutexes->UnLockMutex(MUTEX_Q);
  return retval;
}
#endif
/* IM<e> */

state *
state_queue::top (void)
{
  /* IM<b> */
  assert(false); /* not called any more */
  /* IM<e> */
  if (num_elts > 0) {
    /* IM<b> */
    /*return stateArray[front];*/
    return NULL;
    /* IM<e> */
  }
  else {
    Error.Notrace ("Internal: Attempt to top() empty state queue.", "", "");
    return NULL;
  }
}

/* IM<b> */
/* This is just for completeness, never called */
state *
state_queue::top (bool &checked)
{
  mutexes->LockMutex(MUTEX_Q);
  if (num_elts_head <= 0) {
    QueueEmptyFault ();
  }

  mutexes->UnLockMutex(MUTEX_Q);
  return &stateArray[head_begin + front].s;

  /*mutexes->LockMutex(MUTEX_Q);
  static state *ret = new state;
  if (num_elts > 0) {
    StateCopy(ret, stateArray[front]);
    checked = Checked->get(front);
    mutexes->UnLockMutex(MUTEX_Q);
    return ret;
  }
  else {
    mutexes->UnLockMutex(MUTEX_Q);
    Error.Notrace ("Internal: Attempt to top() empty state queue.", "", "");
    return NULL;
  }*/
}

void
state_queue::ReclaimFreeSpace ()
{

#ifndef SPLITFILE
  global_rear +=
    fwrite (&stateArray[tail_begin], sizeof (struct state_bool), tail_size,
	    paging_file_bottom);
#else
  global_rear +=
    paging_file_bottom->write (&stateArray[tail_begin], sizeof (struct state_bool),
			       tail_size);
#endif
  num_elts_tail = 0;
  rear = 0;
}

void
state_queue::QueueEmptyFault ()
{
#ifndef SPLITFILE
  size_t read =
    fread (&stateArray[head_begin], sizeof (struct state_bool), head_size,
	   paging_file_top);
#else
  size_t read =
    paging_file_top->read (&stateArray[head_begin], sizeof (struct state_bool),
			   head_size);
#endif

  if (read > 0 && global_front >= read) {		//ok, some states are swapped in

    num_elts_head = read;
    global_front -= read;
  }
  else if (read > 0 && global_front > 0 && global_front < read) {
    // same as above, but may have read more than allowed
    num_elts_head = global_front;
    global_front = 0;
  }
  else if (global_rear > 0) {	//paging_file_top is empty, but paging_file_bottom is not
#ifndef SPLITFILE
    fclose (paging_file_top);

    paging_file_top = paging_file_bottom;
    fseek (paging_file_top, 0, SEEK_SET);	//move to the beginning of the queue
    global_front = global_rear;

    if ((paging_file_bottom = tmpfile ()) == NULL) {
      Error.Notrace ("Internal: Error creating bottom paging file.");
    }
    global_rear = 0;		//bottom file is empty

    //now bottom entries are top entries and bottom file is empty. Reload a block!
    size_t read =
      fread (&stateArray[head_begin], sizeof (struct state_bool), head_size,
	     paging_file_top);

    num_elts_head = read;
    global_front -= read;
#else
    splitFile *fswap;
    fswap = paging_file_top;
    paging_file_top = paging_file_bottom;
    paging_file_bottom = fswap;
    paging_file_top->seek (0, SEEK_SET);	//move to the beginning of the queue
    paging_file_bottom->seek (0, SEEK_SET);	//reset bottom queue

    global_front = global_rear;
    global_rear = 0;		//bottom file is empty

    //now bottom entries are top entries and bottom file is empty. Reload a block!
    size_t read =
      paging_file_top->read (&stateArray[head_begin], sizeof (struct state_bool),
			     head_size);

    num_elts_head = read;
    global_front -= read;
#endif
  }
  else if (num_elts_tail > 0) {	//paging_file_top AND paging_file_bottom are empty

    /* the disk queue is ended. this means that the only states we have
       to explore are the ones in the current tail window */
    int swap = tail_begin;
    tail_begin = head_begin;
    head_begin = swap;

    swap = tail_size;
    tail_size = head_size;
    head_size = swap;

    num_elts_head = num_elts_tail;
    num_elts_tail = 0;
    rear = 0;
  }
  else {			//no more states in both swap files, and the memory is empty: why do we call again?
    Error.Notrace ("Internal: Attempt to read an empty state queue.");
  }

  front = 0;
}
/* IM<e> */

void
state_stack::enqueue (state * e)
{
  /* IM<b> */
  assert(false); /* not called any more */
  /* IM<e> */
  if (num_elts < max_active_states) {
    front = front == 0 ? max_active_states - 1 : front - 1;
    /* IM<b> */
    /*stateArray[front] = e;*/
    /* IM<e> */
    nextrule_to_try[front] = 0;
    num_elts++;
  }
  else {
    Error.Notrace ("Internal: Too many active states.");
  }
}

/****************************************   // changes by Uli
  The Stateset implementation for recording all the states found.
  ****************************************/

int
state_set::bits_per_state ()
{
#ifndef HASHC
  return 8 * sizeof (state);
#else
  return args->num_bits.value;
#endif
}

#if __WORDSIZE == 32
state_set::state_set (unsigned long table_size)
:table_size (table_size), num_elts (0), num_elts_reduced (0), num_collisions (0)
/* IM<b> */
 , num_elts_others(0), num_elts_others_d(0.0), is_num_elts_others_double(FALSE),
 num_elts_d(0.0), is_num_elts_double(FALSE)
/* IM<e> */
{
#ifndef HASHC
  table = new state[table_size];
#else
  assert (sizeof (Unsigned32) == 4);	// the implementation is pretty depen-
  // dent on the 32 bits
  unsigned long size =
    (unsigned long) ((double) table_size * args->num_bits.value / 32) + 3;
  // higher precision necessary to avoid overflow
  // two extra elements needed in table
  table = new Unsigned32[size];
  for (unsigned long i = 0; i < size; i++)
    table[i] = 0UL;
#endif
  Full = new dynBitVec (table_size);
}
#else	// 64 bit version
#include <math.h>
state_set::state_set (unsigned long table_size)
:table_size (table_size), num_elts (0), num_elts_reduced (0), num_collisions (0)
{
#ifndef HASHC
  table = new state[table_size];
#else
  assert (sizeof (Unsigned32) == 4);	// the implementation is pretty depen-
                                        // dent on the 32 bits for 1 integer
  unsigned long size =
    (unsigned long) ((double) table_size * args->num_bits.value / BITUNSIGNED) + 3;
  bits_for_size = (unsigned int)floor(log((double)table_size)/log((double)2)) + 1;
  if (args->print_64bit_info.value) {
    /* IM<b> */
    if (Communicate->IsRoot()) {
    /* IM<e> */
    int amount = 3*sizeof(Unsigned32)*CHAR_BIT - bits_for_size;
    printf("With %lu bytes of RAM, you can use at most %d bits (option -b) for the hash compaction\n", 
      args->mem.value, amount > 64? 64 : amount);
    printf("Value for bits_for_size: %d\n", bits_for_size);
    /* copied from Notrace */
#ifdef HASHC_TRACE
    if (TraceFile!=NULL)
      delete TraceFile;
#endif
    /* IM<b> */
    } 
    /* Only one thread here */
    Terminate = TRUE; /* useless */
    if (Algorithm != NULL) delete Algorithm;
    if (Communicate != NULL) delete Communicate;
    if (mutexes != NULL) delete mutexes;
    /* IM<e> */
    exit(1);
  }
  // higher precision necessary to avoid overflow
  // two extra elements needed in table
  if (bits_for_size > 3*sizeof(Unsigned32)*CHAR_BIT - args->num_bits.value)
  // in order to address an hash table entry, we may use the whole first int + what 
  // remains of the other 2 ints when args->num_bits.value bits are subtracted
    /* IM<b> */
    if (Communicate->IsRoot()) {
    /* IM<e> */
    Error.Notrace("Too many bits for the hash compaction (option -b); may be at most %d", 
      3*sizeof(Unsigned32)*CHAR_BIT - bits_for_size);
    /* IM<b> */
    } 
    else {
      /* Only one thread here */
      Terminate = TRUE; /* useless */
      if (Algorithm != NULL) delete Algorithm;
      if (Communicate != NULL) delete Communicate;
      if (mutexes != NULL) delete mutexes;
      exit(1);
    }
    /* IM<e> */
  bits_for_size = bits_for_size <= BITUNSIGNED? BITUNSIGNED : bits_for_size;

  table = new Unsigned32[size];
  for (unsigned long i = 0; i < size; i++)
    table[i] = 0;
#endif
  Full = new dynBitVec (table_size);
}
#endif

state_set::~state_set ()
{
  delete[]table;		// only works for newer g++ versions
  delete Full;
}

// Uli: the two following routines were deleted because they were not called
//      any more and required changes
//void state_set::clear_state_set()
//void copy_state_set( state_set * set1, state_set * set2)

/* IM<b> */
/*bool state_set::simple_was_present (state * &in, bool valid, bool permanent)*/
int state_set::simple_was_present (state * &in, bool valid, bool permanent, bool surely_mine)
/* IM<e> */
/* changes in to point to the first state found with that pattern. */
/* returns true iff the state was present in the hash table;
 * Otherwise, returns false and inserts the state. */
/* Algorithms directly from Andreas\' code. He cites CLR 235, 236. */
// Uli: pitfall: shift operators yield undefined values if the right
//               operand is equal to the length in bits of the left
//               operand (see ARM, pg.74)
// Uli: table_size must be prime
{
#ifndef HASHC
  unsigned long
    key = in->hashkey ();
  unsigned long
    h1 = key % table_size;
  unsigned long
    h2 = 1 + key % (table_size - 1);
  unsigned long
    h = h1;
#else
#if __WORDSIZE == 32
  uint32_t * key;
  unsigned long
    /* IM<b> */
    /*h1 = key[0] % table_size;*/
    h1;
    /* IM<e> */
  unsigned long
    h2;
  register unsigned long
    /* IM<b> */
    /*h = h1;*/
    h;
    /* IM<e> */
  register unsigned long
    num_bits = args->num_bits.value;
  register unsigned long
    mask1 = (~0UL) << (num_bits > 32 ? 0 : 32 - num_bits);
  register unsigned long
    mask2 = num_bits > 32 ? (~0UL) << (64 - num_bits) : 0UL;
  register unsigned long
    addr,
    offset;
  register unsigned long
    /* IM<b> */
    /*c1 = key[1] & mask1;*/
    c1;
    /* IM<e> */
  register unsigned long
    /* IM<b> */
    /*c2 = key[2] & mask2;*/
    c2;
    /* IM<e> */
  register unsigned long
    t1,
    t2;
#else
  /* IM<b> */
  /*unsigned int *key = h3->hash (in, valid);*/
  uint32_t *key;
  unsigned long h1;
  /* IM<e> */
  unsigned long h;
  unsigned long h2;
  register unsigned int num_bits = args->num_bits.value;
  register unsigned int
    mask1 = (~0) << (num_bits > BITUNSIGNED ? 0 : BITUNSIGNED - num_bits);
  register unsigned int
    mask2 = num_bits > BITUNSIGNED ? (~0) << (2*BITUNSIGNED - num_bits) : 0;
  register unsigned long addr, offset;
  /* IM<b> */
  /*register unsigned int c1 = key[1] & mask1;
  register unsigned int c2 = key[2] & mask2;*/
  register unsigned int c1;
  register unsigned int c2;
  /* IM<e> */
  register unsigned int t1, t2;
#endif
#endif

  /* IM<b> */
  unsigned int s_rank;
  if (!surely_mine) {
#ifndef HASHC
    s_rank = key%(uint32_t)Communicate->GetNumProcs();
#else
    // hash compaction
    s_rank = in->hashkey()%(uint32_t)Communicate->GetNumProcs();
#endif // ifndef HASHC

/* Patrick    */if (s_rank != Communicate->GetRank())
      return s_rank;
  }
  /* if it continues, the actual node is the owner */
#ifdef HASHC
  key = h3->hash (in, valid);
  h1 = key[0] % table_size;
  h = h1;
  c1 = key[1] & mask1;
  c2 = key[2] & mask2;
#endif
  /* IM<e> */
/* IM<b> */
/*#ifdef VER_PSEUDO*/
#if 0
/* IM<e> */
  if (is_empty (h)) {
    Full->set (h);
    num_elts++;
    return FALSE;
  }
  return TRUE;

#else
  unsigned long
    probe = 0;

#ifndef HASHC
// no hash compaction, uses double hashing

  bool
    empty,
    equal = FALSE;

  while (!(empty = is_empty (h)) &&
	 !(equal = (*in == table[h])) && (probe < table_size)) {
    h = (h1 + probe * h2) % table_size;	// double hashing
    num_collisions++;
    probe++;
  }
  if (empty) {			/* Go ahead and insert the element. */
    table[h] = *in;
    in = &table[h];
    Full->set (h);
    num_elts++;
    /* IM<b> */
    /*return FALSE;*/
    bool is_num_elts_double_prec = is_num_elts_double;
    if (!is_num_elts_double)
      is_num_elts_double = (num_elts == 0);
    num_elts_d = num_elts_d + 1.0;

    LOG_VERBOSE_LIMIT_FREQUENCY(CLOSED_HASH_TABLE_ID, 1, 
				" (states) Closed hash table contains %d elements (total size %d, %.2f%% full).\n", 
				num_elts, table_size, ((double)(num_elts/(double)table_size))*100);

    return -1;
    /* IM<e> */
  }
  else if (equal) {
    in = &table[h];
    /* IM<b> */
    /*return TRUE;*/
    return !surely_mine? s_rank : Communicate->GetRank();
    /* IM<e> */
  }
  else {
    Error.Notrace ("Closed hash table full.");
    return FALSE;		/* it doesn\'t matter, but it shuts up g++. */
  }

#else
// hash compaction, uses ordered hashing
// the state-insertion is done in two steps: search and insertion

  // search - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#if __WORDSIZE == 32
  h2 = 1 + c1 % (table_size - 1);	// calculation uses compressed value
#else
  if (bits_for_size == BITUNSIGNED) {
    h = key[0] % table_size;
    h2 = 1 + c1 % (table_size - 1);	// calculation uses compressed value
  }
  else { // bits_for_size > BITUNSIGNED 
    /* LSB is at the right
             key[2]   key[1]   key[0]
	    hhzzzzzz hhhhhhhh xxxxxxxx 
       
       h =  00zzzzzzxxxxxxxx 
       (not taking into account % table_size)
    */
    h = ((unsigned long) key[0] + (((unsigned long)(key[2]%(1 << (bits_for_size - BITUNSIGNED)))) << BITUNSIGNED)) % table_size;
    /* LSB is at the right
               c2       c1
	    xx000000 yyyyyyyy
       
       h2 = 000000xxyyyyyyyy
       (not taking into account % (table_size - 1) and the initial 1 +)
    */
    h2 = 1 + (((unsigned long) c1) + (((unsigned long)(c2 >> (2*BITUNSIGNED - num_bits))) << BITUNSIGNED)) % (table_size - 1);	// calculation uses compressed value
  }
#endif

  do {
#if __WORDSIZE == 32
    // calculate address and offset in table
    // 32 bit arithmetic not sufficient and may cause overflow
    // addr = (h*num_bits) / 32
    // offset = (h*num_bits) % 32
    // Thus, h*num_bits is first done on the least 16 bits, and then on the
    // remaining 16 bits; since we have to divide by 32, we ignore the least 5
    // bits of the result
    offset = (h & 0xffffUL) * num_bits;
    addr = (((h >> 16) * num_bits) << 11) + (offset >> 5);
    offset &= 0x1fUL;
#else
    // 64 bit arithmetic should always be sufficient (the limit should be
    // 2^64/2^6 = 2^58, that can address a table with 2^58*2^4 = 2^62 bytes,
    // that is to say 4 EB (exabytes) of RAM!)
    addr = (h*num_bits) / BITUNSIGNED;
    offset = (h*num_bits) % BITUNSIGNED;
#endif

    if (is_empty (h))
      break;			// search unsuccessful

    // read compressed value from table
    t1 =
      (table[addr] << offset |
       (offset == 0 ? 0 : table[addr + 1] >> (32 - offset)))
      & mask1;
    t2 =
      (table[addr + 1] << offset |
       (offset == 0 ? 0 : table[addr + 2] >> (32 - offset)))
      & mask2;

    if (t1 == c1 ? t2 < c2 : t1 < c1)
      break;			// search unsuccessful

    if (t1 == c1 && t2 == c2)
      /* IM<b> */
      /*return TRUE;		// search successful*/
      return Communicate->GetRank(); //Patrick !surely_mine? s_rank : Communicate->GetRank();
      /* IM<e> */

    h = (h + h2) % table_size;
    num_collisions++;
    probe++;
    if (probe == table_size)
      Error.Notrace ("Closed hash table full.");
  } while (TRUE);

/* IM<b> */
#ifdef HASHC_TRACE
/* IM<e> */
  // write trace info
  if (args->trace_file.value)
    /* IM<b> */
    /*TraceFile->write (c1, c2, in->previous.lVal ());*/
    TraceFile->write (c1, c2, in->previous.lVal (), in->previous.GetRank ());
    /* IM<e> */
/* IM<b> */
#endif
/* IM<e> */

  // insertion - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  if (num_elts == table_size)
    Error.Notrace ("Closed hash table full.");

  while (!is_empty (h))		// until empty slot found
  {
    if (t1 == c1 ? t2 < c2 : t1 < c1) {
      table[addr] ^= (c1 ^ t1) >> offset;
      table[addr + 1] ^= (offset == 0 ? 0 : (c1 ^ t1) << (32 - offset))
	| (c2 ^ t2) >> offset;
      table[addr + 2] ^= (offset == 0 ? 0 : (c2 ^ t2) << (32 - offset));
      c1 = t1;
      c2 = t2;
    }

    h = (h + 1 + c1 % (table_size - 1)) % table_size;
#if __WORDSIZE == 32
    offset = (h&0xffffUL)*num_bits;
    addr = (((h>>16)*num_bits)<<11) + (offset>>5);
    offset &= 0x1fUL;
#else
    // 64 bit arithmetic should always be sufficient
    addr = (h*num_bits) / BITUNSIGNED;
    offset = (h*num_bits) % BITUNSIGNED;
#endif
    t1 =
      (table[addr] << offset |
       (offset == 0 ? 0 : table[addr + 1] >> (32 - offset)))
      & mask1;
    t2 =
      (table[addr + 1] << offset |
       (offset == 0 ? 0 : table[addr + 2] >> (32 - offset)))
      & mask2;
  }

  table[addr] |= c1 >> offset;	// insertion
  table[addr + 1] |= (offset == 0 ? 0 : c1 << (32 - offset)) | c2 >> offset;
  table[addr + 2] |= (offset == 0 ? 0 : c2 << (32 - offset));

  /* IM<b> */
  /*copy_state (in);		// make copy of state*/
  /* IM<e> */
  Full->set (h);
  num_elts++;
  if (permanent)
    num_elts_reduced++;
  /* IM<b> */
  /*return FALSE;*/
  if (!is_num_elts_double)
    is_num_elts_double = num_elts == 0;
  num_elts_d = num_elts_d + 1.0;

  LOG_VERBOSE_LIMIT_FREQUENCY(CLOSED_HASH_TABLE_ID, 1,
			      " (states) Closed hash table contains %d elements (total size %d, %.2f%% full).\n", 
			      num_elts, table_size, (double)(num_elts/(double)table_size)*100);
  return -1;
  /* IM<e> */

#endif

#endif
};

/* IM<b> */
/* Assumes in to have the same value of workingstate; workingstate must be
locked before calling this */
/*bool state_set::was_present (state * &in, bool valid, bool permanent)*/
int state_set::was_present (state * &in, bool valid, bool permanent, bool surely_mine)
/* IM<e> */
{
  /* IM<b> */
  if (!surely_mine) {
  /* IM<e> */
  if (args->symmetry_reduction.value)
    in->Normalize ();
  if (args->multiset_reduction.value && !args->symmetry_reduction.value)
    in->MultisetSort ();
  /* IM<b> */
  /*return simple_was_present (in, valid, permanent);*/
  }
  return simple_was_present (in, valid, permanent, surely_mine);
  /* IM<e> */
}

void
state_set::print_capacity (void)
{
  cout <<
    "\t* The memory allocated for the hash table and state queue is\n\t  ";
  if (args->mem.value > 1000000)
    cout << (args->mem.value / 1000000) << " Mbytes.\n";
  else
    cout << (args->mem.value / 1000) << " kbytes.\n";

#ifndef HASHC
  cout << "\t  With two words of overhead per state, the maximum size of\n"
    << "\t  the state space is "
    << table_size << " states.\n"
    << "\t   * Use option \"-k\" or \"-m\" to increase this, if necessary.\n";
#else
  cout << "\t  With states hash-compressed to "
    << args->num_bits.value << " bits, the maximum size of\n"
    << "\t  the state space is "
    << table_size << " states.\n"
    << "\t   * Use option \"-k\" or \"-m\" to increase this, if necessary.\n";
#endif
}

/****************************************
  Modification:
  1) 1 Dec 93 Norris Ip: 
  check -sym option when checking was_present()
  add StateCmp(state l, state r)
  2) 24 Feb 94 Norris Ip:
  added -debugsym option to run two hash tables in parallel
  for debugging purpose
  3) 8 March 94 Norris Ip:
  merge with the latest rel2.6
****************************************/

/********************
  $Log: mu_state.C,v $
  Revision 1.3  1999/01/29 08:28:09  uli
  efficiency improvements for security protocols

  Revision 1.2  1999/01/29 07:49:11  uli
  bugfixes

  Revision 1.4  1996/08/07 18:54:33  ip
  last bug fix on NextRule/SetNextEnabledRule has a bug; fixed this turn

  Revision 1.3  1996/08/07 01:00:18  ip
  Fixed bug on what_rule setting during guard evaluation; otherwise, bad diagnoistic message on undefine error on guard

  Revision 1.2  1996/08/07 00:15:26  ip
  fixed while code generation bug

  Revision 1.1  1996/08/07 00:14:46  ip
  Initial revision

********************/
