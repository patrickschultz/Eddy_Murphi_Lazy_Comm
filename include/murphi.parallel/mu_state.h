/* -*- C++ -*- 
 * mu_state.h
 * @(#) header for routines related to states in the verifier
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

#ifndef _STATE_
#define _STATE_

/****************************************
  There are three different declarations:
  1) state
  2) dynBitVec
  3) state queue
  4) state set
 ****************************************/

/****************************************
  The record for a single state.
  require : BITS_IN_WORLD in parameter file
 ****************************************/

/* BITS_IN_WORLD gets defined by the generated code. */
/* The extra addition is there so that we round up to the greater block. */

/****************************************
  Bit vector - copied straight from Andreas. 
 ****************************************/
class dynBitVec
{
  // data
  unsigned long numBits;
  unsigned char *v;

  // Inquiries
  inline unsigned int Index (unsigned long index)
  {
    return index / 8;
  }
  inline unsigned int Shift (unsigned long index)
  {
    return index % 8;
  }

public:
  // initializer
  dynBitVec (unsigned long nBits);
  // destructor
  virtual ~ dynBitVec ();

  // interface
  inline int NumBits (void)
  {
    return numBits;
  }
  inline int NumBytes (void)
  {
    return 1 + (numBits - 1) / 8;
  }
  inline void clear (unsigned long i)
  {
    v[Index (i)] &= ~(1 << Shift (i));
  }
  inline void set (unsigned long i)
  {
    v[Index (i)] |= (1 << Shift (i));
  }
  inline int get (unsigned long i)
  {
    return (v[Index (i)] >> Shift (i)) & 1;
  }
};

class statelist
{
  state *s;
  statelist *next;
public:
    statelist (state * s, statelist * next)
  : s (s), next (next)
  {
  };
};

/****************************************
  The state queue.
 ****************************************/
class state_queue
{
protected:
  /* IM<b> */
  /*state ** stateArray;*/		/* The actual array. */
  struct state_bool {
    state s;
    char checked;
#ifdef HASHC_TRACE
    unsigned long num_cur_state;
#endif
  };
  struct state_bool * stateArray;		/* The actual array. */
  /* IM<e> */
  const unsigned long max_active_states;	/* max size of queue */
  unsigned long front;		/* index of first active state. */
  unsigned long rear;		/* index of next free slot. */
  unsigned long num_elts;	/* number of elements. */
  /* IM<b> */
  unsigned long global_rear, global_front;
  unsigned long num_elts_head, num_elts_tail;
  unsigned long head_begin, tail_begin;
  unsigned long head_size, tail_size;

#ifndef SPLITFILE
  FILE *paging_file_top, *paging_file_bottom;
#else
  splitFile *paging_file_top, *paging_file_bottom;
#endif
  /* IM<e> */

public:
  // initializers
    state_queue (unsigned long mas);

  // destructor
    virtual ~ state_queue ();

  // information interface
  inline unsigned long MaxElts (void)
  {
    return max_active_states;
  }
  /* IM<b> */
  /*unsigned long NumElts (void)
  {
    return num_elts;
  }*/
  unsigned long NumElts (void) /* Locked when called (only in mu_io.C) */
  {
    return num_elts_head + num_elts_tail + global_rear + global_front;
  }
  /* IM<e> */
  inline static int BytesForOneState (void);
  /* IM<b> */
  /*inline bool isempty (void)
  {
    return num_elts == 0;
  }*/
  inline bool isempty (void)
  {
    mutexes->LockMutex(MUTEX_Q);
    bool retVal = num_elts_head + num_elts_tail + global_rear + global_front == 0;
    mutexes->UnLockMutex(MUTEX_Q);
    return retVal;
  }
  /* IM<e> */

  // storing and removing elements
  virtual void enqueue (state * e);
  virtual state *dequeue (void);
  virtual state *top (void);

  /* IM<b> */
  virtual void enqueue (state * &e, bool, unsigned long = 0);
  virtual state *dequeue (bool &);
#ifdef HASHC_TRACE
  virtual state *dequeue (bool &, unsigned long &);
  virtual unsigned long getNumCurState ();
#endif
  virtual state *top (bool &);
  virtual void ReclaimFreeSpace ();
  virtual void QueueEmptyFault ();
  /* IM<e> */

  virtual unsigned NextRuleToTry ()	// Uli: unsigned short -> unsigned
  {
    Error.
      Notrace
      ("Internal: Getting next rule to try from a state queue instead of a state stack.");
    return 0;
  }
  virtual void NextRuleToTry (unsigned r)
  {
    Error.
      Notrace
      ("Internal: Setting next rule to try from a state queue instead of a state stack.");
  }

  // printing routine
  void Print (void);
  virtual void print_capacity (void)
  {
    cout << "\t* Capacity in queue for breadth-first search: "
      << max_active_states << " states.\n"
      << "\t   * Change the constant gPercentActiveStates in mu_prolog.inc\n"
      << "\t     to increase this, if necessary.\n";
  }
};

class state_stack:public state_queue
{
  unsigned *nextrule_to_try;

public:
  // initializers
    state_stack (unsigned long mas)
  : state_queue (mas)
  {
    unsigned long i;
      nextrule_to_try = new unsigned[mas];
    for (i = 0; i < mas; i++)
        nextrule_to_try[i] = 0;
  };

  // destructor
  virtual ~ state_stack () {
    delete[OLD_GPP (max_active_states)] nextrule_to_try;	// Should be delete[].
  };

  virtual void print_capacity (void)
  {
    cout << "\t* Capacity in queue for depth-first search: "
      << max_active_states << " states.\n"
      << "\t   * Change the constant gPercentActiveStates in mu_prolog.inc\n"
      << "\t     to increase this, if necessary.\n";
  }
  virtual void enqueue (state * e);

  virtual unsigned NextRuleToTry ()
  {
    return nextrule_to_try[front];
  }
  virtual void NextRuleToTry (unsigned r)
  {
    nextrule_to_try[front] = r;
  }

#ifdef partial_order_opt
  // special interface with sleepset
  virtual void enqueue (state * e, sleepset s);
#endif
};

/****************************************
  The state set
  represented as a large open-addressed hash table.
 ****************************************/

#include <stdint.h> /* needed for __WORDSIZE, not included by <limits.h> in a
64-bit architecture if gcc >= 2 */

class state_set
{
#ifdef HASHC
#if __WORDSIZE == 32
  typedef unsigned long Unsigned32;    // basic building block of the hash 
                                       // table, slots may have different size
#else
  typedef unsigned int Unsigned32;
#endif
#endif

  // data
  unsigned long table_size;	/* max size of the hash table */
#ifndef HASHC
  state *table;			/* pointer to the hash table */
#else
#if __WORDSIZE == 64
  unsigned int bits_for_size;   /* number of bits to address the whole table */
#endif
  Unsigned32 *table;
#endif
  dynBitVec *Full;		/* whether element table[i] is used. */
  unsigned long num_elts;	/* number of elements in table */
  unsigned long num_elts_reduced;	// Uli
  unsigned long num_collisions;	/* number of collisions in hashing */
  /* IM<b> */
  unsigned long num_elts_others;/* number of elements in the other nodes (if I am root). */
  double num_elts_others_d;	/* double counterpart (for state spaces with more than 4*10^9 states on 32 bit machines) */
  bool is_num_elts_others_double;
  double num_elts_d;
  bool is_num_elts_double;
  /* IM<e> */

  // internal routines
  bool is_empty (unsigned long i) /* MUTEX_H always already locked when this is called */
  {				/* check if element table[i] is empty */
    return Full->get (i) == 0;
  };

public:
  // constructors
  state_set (unsigned long table_size);
  state_set (void);

  friend void copy_state_set (state_set * set1, state_set * set2);

  void clear_state_set ();

  // destructor
  virtual ~ state_set ();

  /* IM<b> */
  // checking the presence of state "in"
  /*bool simple_was_present (state * &in, bool, bool);*/
  /* old was_present without checking -sym */
  /*bool was_present (state * &in, bool, bool);*/
  /* checking -sym before calling simple_was_present() */
  int simple_was_present (state * &in, bool, bool, bool);
  int was_present (state * &in, bool, bool, bool);
  inline void IncrNumEltsOthers(unsigned long add) { 
    if (add && !is_num_elts_others_double) /* once it is set, is set */ {
      is_num_elts_others_double = (num_elts_others + add <= num_elts_others);
      if (!is_num_elts_others_double)
	num_elts_others += add;
    }
    num_elts_others_d += (double)add;
  };
  inline void IncrNumEltsOthers(double add) { 
    is_num_elts_others_double = TRUE;
    num_elts_others_d += add;
  };
  unsigned long NumEltsOthers() {return num_elts_others;};
  double NumEltsOthers_d() { return num_elts_others_d;};
  bool IsNumEltsOthersDouble() { return is_num_elts_others_double; };
  double NumElts_d() { return num_elts_d;};
  bool IsNumEltsDouble() { return is_num_elts_double; };
  /* IM<e> */

  // get the size of each state entry
#ifndef VER_PSEUDO
  static int bits_per_state (void);
#endif

  // get the number of elts in the state set
  inline unsigned long NumElts ()
  {
    return num_elts;
  };

  inline unsigned long NumEltsReduced ()
  {
    return num_elts_reduced;
  };				// Uli

  // printing information
  void print_capacity (void);

  // print hashtable       
  void print ()
  {
    for (unsigned long i = 0; i < table_size; i++)
      if (!is_empty (i)) {
	cout << "State " << i << "\n";
#ifdef HASHC
	cout << "... compressed\n";
#else
	StateCopy (workingstate, &table[i]);
	theworld.print ();
#endif
	cout << "\n";
      }
  }
};

/****************************************
  1) 1 Dec 93 Norris Ip: 
  check -sym option when checking was_present()
  add Normalize() declaration in class state
  add friend StateCmp to class state
  2) 24 Feb 94 Norris Ip:
  added -debugsym option to run two hash tables in parallel
  for debugging purpose
  3) 8 March 94 Norris Ip:
  merge with the latest rel2.6
****************************************/

/********************
  $Log: mu_state.h,v $
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

#endif
