/* -*- C++ -*-
 * mu_system.C
 * @(#) procedure for anaylsing the system 
 *      to be simulated or verified
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
 * Original Author: C. Norris Ip 
 * Created: 19 Oct 94
 *
 * Update:
 *
 */

#include "mu_log.h"
#include "malloc_extension.h"

/************************************************************/
/* StateManager */
/************************************************************/
StateManager::StateManager (bool createqueue, unsigned long NumStates)
  :
NumStates (NumStates),
statesCurrentLevel (0),
statesNextLevel (0),
currentLevel (0),
pno (1.0)
{
#if __WORDSIZE == 64
  if (!args->print_64bit_info.value) {
#endif
  if (createqueue) {
    /* IM<b> */
    /*queue =
      new state_queue ((unsigned long) (gPercentActiveStates * NumStates));*/
    unsigned long qsize = (unsigned long) (gPercentActiveStates *
			     (((double) sizeof (state *)) /
			      ((double) (sizeof (state) + sizeof(char)))) * NumStates);

    if (qsize >= 10)
      queue = new state_queue (qsize);
    else
      queue = new state_queue (10);
    /* IM<e> */
  }
  else {
    queue =
      new state_stack ((unsigned long) (gPercentActiveStates * NumStates));
  }
#if __WORDSIZE == 64
  }
#endif
  the_states = new state_set (NumStates);
}

StateManager::~StateManager ()
{
  if (queue != NULL)
    delete queue;
  if (the_states != NULL)
    delete the_states;
}

/* IM<b> */
int
StateManager::AddMultiple(char* qline, int length)
{
  int retVal = 0;
  int i = 0;
  static state *s = new state, *s_tmp = s;

  assert(length%sizeof(class state) == 0);
  for(i = 0; i < length/sizeof(class state); ++i){
    s = s_tmp; /* needed since enqueue modifies s */
    memcpy((char *)s, qline + sizeof(class state)*i, sizeof(class state));

    retVal = 1; /* quite useless now... */
    queue->enqueue (s, false);
  }

  LOG_VERBOSE(" (states) Added %d states to queue, %d currently in queue, %d states processed so far.\n", length/sizeof(class state), QueueNumElts(), NumElts());

  return retVal;
}
/* IM<e> */

bool
StateManager::Add (state * s, bool valid, bool permanent)
{
  /* IM<b> */
  /*if (!the_states->was_present (s, valid, permanent)) {
    // Uli: invariant check moved here
    if (!Properties->CheckInvariants ()) {
      curstate = s;
#ifdef HASHC
      if (args->trace_file.value)
	NumCurState = TraceFile->numLast ();
#endif
      Error.Deadlocked ("Invariant \"%s\" failed.",
			Properties->LastInvariantName ());
    }

    if (args->trace_all.value)
      Reporter->print_trace_all ();

    statesNextLevel++;
    queue->enqueue (s);
    Reporter->print_progress ();
    return TRUE;
  }
  else*/
  assert(0);
  /* IM<e> */
    return FALSE;
}

/* IM<b> */
bool
StateManager::SimpleWasPresent (state * s)
{
  /* check if valid is ok */
  bool retVal;
  StateCopy(workingstate, s);
  if (the_states->was_present (s, TRUE, TRUE, TRUE) == -1)
    retVal = FALSE;
  else
    retVal = TRUE;
  return retVal;
}

bool
StateManager::Add (state * s, bool valid, bool permanent, bool mayEnqueue)
{
  mutexes->LockMutex(MUTEX_RSLT);
  if (result != 'y') {
    mutexes->UnLockMutex(MUTEX_RSLT);
    return FALSE;
  }
  mutexes->UnLockMutex(MUTEX_RSLT);

  int res = the_states->was_present (s, valid, permanent, FALSE);
  /* res == -1: s is mine and has not been already visited (s has been already inserted in the hash table) */
  /* res == my rank: s is mine and it is already present */
  /* otherwise, res is the rank of the node to whom s belongs */

  if (res == -1 || res != Communicate->GetRank()) {
    if (!Properties->CheckInvariants ()) {
      curstate = s;
#ifdef HASHC
#ifdef HASHC_TRACE
      if (args->trace_file.value) {
	if (res != Communicate->GetRank())
	  /* this is to force writing the error state on the trace file (note that surely_mine == TRUE is a lie...) */
	  the_states->was_present (s, valid, permanent, TRUE);
	NumCurState = TraceFile->numLast ();
      }
#endif
#endif
      mutexes->LockMutex(MUTEX_RSLT);
      result = 'n';
      mutexes->UnLockMutex(MUTEX_RSLT);
      Error.Deadlocked ("Invariant \"%s\" failed.",
			Properties->LastInvariantName ());
      return FALSE; /* never executed */
    }
  }
  if (res == -1) {
    if (args->trace_all.value)
      Reporter->print_trace_all ();

    statesNextLevel++;
    if (mayEnqueue) /* it seems to be always true, I cannot remember why it is (was?) useful */
#ifdef HASHC_TRACE
      if (args->trace_file.value)
	queue->enqueue (s, true, TraceFile->numLast ());
      else
	queue->enqueue (s, true);
#else
      queue->enqueue (s, true);
#endif
    Reporter->print_progress ();
    return TRUE;
  }
  else {
    if (res != Communicate->GetRank()) {
        //s owns to someone else (whose index is in res)
      res = Communicate->PushState((char*)s, res);
      if(res == CATASTROPHIC_FAILURE)
	Error.Notrace("Catastrophic Failure in PushState()\n");
      return TRUE;
    }
    else
       //return value changed (never mind, since it was unused)
      return TRUE;
  }

}
/* IM<e> */

bool
StateManager::QueueIsEmpty ()
{
  return queue->isempty ();
}

/* IM<b> */
bool
StateManager::ParTerminate ()
{
  bool ret = FALSE;
  mutexes->LockMutex(MUTEX_TERMINATE);
  if (Terminate) {
    mutexes->UnLockMutex(MUTEX_TERMINATE);
    ret = TRUE;
  }
  else {
    mutexes->UnLockMutex(MUTEX_TERMINATE);
    if (QueueIsEmpty ()) {
      Communicate->CheckStableCondition();
      mutexes->LockMutex(MUTEX_TERMINATE);
      if (Terminate)
	ret = TRUE;
      else
	{ if(QueueIsEmpty()) Error.Notrace("Internal: queue cannot be empty here");}
      mutexes->UnLockMutex(MUTEX_TERMINATE);
    }
  }
  return ret;
}

bool
StateManager::NotQueueIsEmpty ()
{
  return !queue->isempty ();
}
/* IM<e> */

state *
StateManager::QueueTop ()
{
  return queue->top ();
}

state *
StateManager::QueueDequeue ()
{
  return queue->dequeue ();
}

/* IM<b> */
state *
StateManager::QueueDequeue (bool &checked, unsigned long &NumCurState)
{
#ifdef HASHC_TRACE
  return queue->dequeue (checked, NumCurState);
#else
  NumCurState++;
  return queue->dequeue (checked);
#endif
}
/* IM<e> */

/**
 * Patrick
 */
state *
StateManager::QueueDequeue_Pull (bool &checked, unsigned long &NumCurState)
{
#ifdef HASHC_TRACE
  return queue->dequeue (checked, NumCurState);
#else
  return queue->dequeue (checked);
#endif
}

unsigned
StateManager::NextRuleToTry ()	// Uli: unsigned short -> unsigned
{
  return queue->NextRuleToTry ();
}

void
StateManager::NextRuleToTry (unsigned r)
{
  queue->NextRuleToTry (r);
}

// -------------------------------------------------------------------------
// Uli: added omission probability calculation & printing

#ifdef HASHC

#include <math.h>

double
StateManager::harmonic (double n)
// return harmonic number H_n
{
  return (n < 1) ? 0 : log (n) + 0.577215665 + 1 / (2 * n) - 1 / (12 * n * n);
}

void
StateManager::CheckLevel ()
// check if we are done with the level currently expanded
{
  static double p = 1.0;	// current bound on state omission probability
  static double l = pow (2, double (args->num_bits.value));	// l=2^b
  static double k = -1;		// sum of the number of states - 1
  static double m = NumStates;	// size of the state table

  if (--statesCurrentLevel <= 0)
    // all the states of the current level have been expanded
  {
    // proceed to next level
    statesCurrentLevel = statesNextLevel;
    statesNextLevel = 0;

    // check if there are states in the following level
    if (statesCurrentLevel != 0) {
      currentLevel++;

      // calculate p_k with equation (2) from FORTE/PSTV paper for
      // the following level
      k += statesCurrentLevel;
      double pk = 1 - 2 / l * (harmonic (m + 1) - harmonic (m - k))
	+ ((2 * m) + k * (m - k)) / (m * l * (m - k + 1));
      pno *= pk;
    }
  }
}

void
StateManager::PrintProb ()
{
  // calculate Pr(not even one omission) with equation (12) from CHARME
  //  paper
  double l = pow (2, double (args->num_bits.value));
  double m = NumStates;
  double n = the_states->NumElts ();
  double exp = (m + 1) * (harmonic (m + 1) - harmonic (m - n + 1)) - n;
  double pNO =
    pow (1 - 1 / l, (m + 1) * (harmonic (m + 1) - harmonic (m - n + 1)) - n);

  // print omission probabilities
  cout.precision (6);
  cout << "Omission Probabilities (caused by Hash Compaction):\n\n"
    << "\tPr[even one omitted state]    <= " << 1 - pNO << "\n";
  if (args->main_alg.mode == argmain_alg::Verify_bfs)
    cout << "\tPr[even one undetected error] <= " << 1 - pno << "\n"
      << "\tDiameter of reachability graph: " << currentLevel - 1 << "\n\n";
  // remark: startstates had incremented the currentLevel counter
  else
    cout << "\n";
}

#endif

// -------------------------------------------------------------------------

//Patrick
size_t
StateManager::MemSize()
{
	size_t value;
	MallocExtension::instance()->GetNumericProperty("generic.current_allocated_bytes", &value);
	return value;
}

void
StateManager::print_capacity ()
{
  if (args->main_alg.mode == argmain_alg::Verify_dfs
      || args->main_alg.mode == argmain_alg::Verify_bfs) {
    cout << "\nMemory usage:\n\n";
    cout << "\t* The size of each state is " << BITS_IN_WORLD << " bits "
      << "(rounded up to " << BLOCKS_IN_WORLD << " bytes).\n";
    the_states->print_capacity ();
    queue->print_capacity ();
  }
}

void
StateManager::print_all_states ()
{
  the_states->print ();
}

unsigned long
StateManager::NumElts ()
{
  return the_states->NumElts ();
}

unsigned long
StateManager::NumEltsReduced ()
{
  return the_states->NumEltsReduced ();
}

unsigned long
StateManager::QueueNumElts ()
{
  return queue->NumElts ();
}

void
StateManager::print_trace_aux (StatePtr p)	// changes by Uli
{
  state original;
  char *s;

  if (p.isStart ()) {
    // this is a startstate
    // expand it into global variable `theworld`
    // StateCopy(workingstate, s);   // Uli: workingstate is set in 
    //      StateName()

    /* IM<b> */
    s = StartState->StateName (p);
    mutexes->LockMutex(MUTEX_PRINT);
    /* IM<e> */
    // output startstate
    /* IM<b> */
    /*cout << "Startstate " << (s = StartState->StateName (p))*/
    cout << "Startstate " << s
    /* IM<e> */
      << " fired.\n";
    /* IM<b> */
    mutexes->UnLockMutex(MUTEX_PRINT);
    /* IM<e> */
    delete[]s;			// Uli: avoid memory leak
    /* IM<b> */
    mutexes->LockMutex(MUTEX_PRINT);
    /* IM<e> */
    theworld.print ();
    cout << "----------\n\n";
    /* IM<b> */
    mutexes->UnLockMutex(MUTEX_PRINT);
    /* IM<e> */
  }
  else {
    // print the prefix
    print_trace_aux (p.previous ());

    // print the next state, which should be equivalent to state s
    // and set theworld to that state.
    // FALSE: no need to print full state
    Rules->print_world_to_state (p, FALSE);
  }
}

void
StateManager::print_trace (StatePtr p)
{
  // print the prefix 
  if (p.isStart ()) {
    print_trace_aux (p);
  }
  else {
    print_trace_aux (p.previous ());

    // print the next state, which should be equivalent to state s
    // and set theworld to that state.
    // TRUE: print full state please;
    Rules->print_world_to_state (p, TRUE);
  }
}


/************************************************************/
/* StartStateManager */
/************************************************************/
StartStateManager::StartStateManager ()
{
  generator = new StartStateGenerator;
}

state *
StartStateManager::RandomStartState ()
{
  what_startstate = (unsigned short) (random.next () % numstartstates);
  return StartState ();
}

/* IM<b> */
/*void*/
bool
/* IM<e> */
StartStateManager::AllStartStates ()
{
  state *nextstate = NULL;

  for (what_startstate = 0; what_startstate < numstartstates;
       what_startstate++) {
    nextstate = StartState ();	// nextstate points to internal data at theworld.getstate()
    /* IM<b> */
    /*(void) StateSet->Add (nextstate, FALSE, TRUE);*/
    if (!StateSet->Add (nextstate, FALSE, TRUE, TRUE))
     return FALSE;
    /* IM<e> */
  }
  /* IM<b> */
  return TRUE;
  /* IM<e> */
}

state *
StartStateManager::NextStartState ()
{
  static int next_startstate = 0;
  if (next_startstate >= numstartstates)
    return NULL;
  what_startstate = next_startstate++;
  return StartState ();
}

state *
StartStateManager::StartState ()
{
  state *next_state = NULL;
  category = STARTSTATE;

  // preparation
  theworld.reset ();

  // fire state rule
  generator->Code (what_startstate);

  // print verbose message
  if (args->verbose.value)
    Reporter->print_fire_startstate ();

  // Uli: invariant check moved

  // Uli: mark as startstate
  /* IM<b> */
  /*workingstate->previous.clear ();*/
  workingstate->previous.clear (Communicate->GetRank());
  /* IM<e> */

  return workingstate;
}

char *
StartStateManager::LastStateName ()
{
  return generator->Name (what_startstate);
}

char *
StartStateManager::StateName (StatePtr p)
{
  state nextstate;
  if (!p.isStart ())
    Error.
      Notrace ("Internal: Cannot find startstate name for non startstate");
  for (what_startstate = 0; what_startstate < numstartstates;
       what_startstate++) {
    StartState ();
    StateCopy (&nextstate, workingstate);

    if (StateEquivalent (&nextstate, p))
      return LastStateName ();
  }

//  Norris: it is very funny, but the following code is supposed to work, but it doesn't
//
//   state * nextstate;
//   for(what_startstate=0; what_startstate<numstartstates; what_startstate++)
//     {
//       nextstate = StartState();                  // nextstate points to internal data at theworld.getstate()
//       if (p.compare(nextstate))
//      return LastStateName();
//     }

  Error.
    Notrace ("Internal: Cannot find startstate name for funny startstate");
  return NULL;
}

/************************************************************/
/* RuleManager */
/************************************************************/
RuleManager::RuleManager ():rules_fired (0)
/* IM<b> */
 , rules_fired_others(0), rules_fired_others_d(0.0), is_rules_fired_others_double(FALSE),
 rules_fired_d(0.0), is_rules_fired_double(FALSE)
/* IM<e> */
{
  NumTimesFired = new unsigned long[RULES_IN_WORLD];
  generator = new NextStateGenerator;

  // initialize check timesfired
  for (int i = 0; i < RULES_IN_WORLD; i++)
    NumTimesFired[i] = 0;
};

RuleManager::~RuleManager ()
{
  delete[OLD_GPP (RULES_IN_WORLD)] NumTimesFired;
}

void
RuleManager::ResetRuleNum ()
{
  what_rule = 0;
}

void
RuleManager::SetRuleNum (unsigned r)
{
  what_rule = r;
}

state *
RuleManager::SeqNextState ()
{
  state *ret;

  what_rule = StateSet->NextRuleToTry ();

  generator->SetNextEnabledRule (what_rule);

  if (what_rule < numrules) {
    ret = NextState ();
    StateSet->NextRuleToTry (what_rule + 1);
    return ret;
  }
  else
    return NULL;
}

// Uli: un-commented, fixed memory leak
state *
RuleManager::RandomNextState ()
{
  unsigned PickARule;
  setofrules rulesleft;
  static state *originalstate = new state;	// buffer, for deadlock checking

  // save workingstate
  StateCopy (originalstate, workingstate);

  // setup set of rules to be checked
  rulesleft.includeall ();

  // nondeterministically fire rules until a different state is obtained
  // or no rule available
  category = CONDITION;

  while (StateCmp (originalstate, curstate) == 0 && rulesleft.size () != 0) {
    PickARule = (unsigned) (random.next () % rulesleft.size ());
    what_rule = rulesleft.getnthrule (PickARule);
    if (generator->Condition (what_rule)) {
      category = RULE;
      generator->Code (what_rule);
    }
    curstate = workingstate;
  }

  // if deadlock occurs
  if (!args->no_deadlock.value && StateCmp (originalstate, curstate) == 0) {
    cout << "\nStatus:\n\n";
    cout << "\t" << rules_fired << " rules fired in simulation in "
      << SecondsSinceStart () << "s.\n";
    Error.Notrace ("Deadlocked state found.");
  }

  rules_fired++;

  // print verbose message
  if (args->verbose.value & !args->full_trace.value)
    Reporter->print_fire_rule_diff (originalstate);
  if (args->verbose.value & args->full_trace.value)
    Reporter->print_fire_rule ();

  if (!Properties->CheckInvariants ()) {
    cout << "\nStatus:\n\n";
    cout << "\t" << rules_fired << " rules fired in simulation in "
      << SecondsSinceStart () << "s.\n";
    Error.Notrace ("Invariant %s failed.", Properties->LastInvariantName ());
  }

  // progress report
  if (!args->verbose.value && rules_fired % args->progress_count.value == 0) {
    cout << "\t" << rules_fired << " rules fired in simulation in "
      << SecondsSinceStart () << "s.\n";
    cout.flush ();
  }
  return curstate;
}

/* IM<b> */
/*bool RuleManager::AllNextStates ()*/
int RuleManager::AllNextStates (bool tracing)
/* IM<e> */
{
  setofrules *
    fire;

  // get set of rules to fire
  fire = EnabledTransition ();

  // generate the set of next states
  /* IM<b> */
  /*return AllNextStates (fire);*/
  return AllNextStates (fire, tracing);
  /* IM<e> */
}

/****************************************
  Generate set of transitions to be made:
  setofrules transitionset_enabled()
  -- future extension
  -- setofrules transitionset_sleepset_rr(sleepset s)
  -- setofrules transitionset_gode_dl(setofrules rs)
  ****************************************/
setofrules *
RuleManager::EnabledTransition ()
{
  static setofrules ret;
  int p;			// Priority of the current rule

  ret.removeall ();

  // record what kind of analysis is currently carried out
  category = CONDITION;

  // Minimum priority among all rules
  minp = INT_MAX;
  // get enabled
  for (what_rule = 0; what_rule < numrules; what_rule++) {
    generator->SetNextEnabledRule (what_rule);
    if (what_rule < numrules) {
      ret.add (what_rule);

      // Compute minimum priority
      if ((p = generator->Priority (what_rule)) < minp)
	minp = p;
    }
  }
  return &ret;
}

/****************************************
  The BFS verification supporting routines:
  void generate_startstateset()
  bool generate_nextstateset_standard(setofrules fire)
  -- future extension
  -- bool generate_nextstateset_sym() 
  -- bool generate_nextstateset_gode_dl() 
  -- bool generate_nextstateset_sleepset_rr(setofrules fire, sleepset cursleepset)
  -- bool generate_nextstateset_gode_sleepset_dl(sleepset cursleepset)
  ****************************************/

// Uli: corrected a memory-leak, improved performance
/* IM<b> */
/*bool RuleManager::AllNextStates (setofrules * fire)*/
int RuleManager::AllNextStates (setofrules * fire, bool tracing)
/* IM<e> */
{
  // this will unconditionally fire rule in "fire"
  // please make sure the conditions are true for the rules in "fire"
  // before calling this function.

  static state *
    originalstate = new state;	// buffer for workingstate // useless, always equal to curstate
  state *
    nextstate;
  bool
    deadlocked_so_far = TRUE;
  bool
    permanent;

  StateCopy (originalstate, workingstate);	// make copy of workingstate
  
  for (what_rule = 0; what_rule < numrules; what_rule++) {
    if (fire->in (what_rule) && generator->Priority (what_rule) <= minp)
      // if (fire->in(what_rule) )
    {
      nextstate = NextState ();
      if (StateCmp (curstate, nextstate) != 0) {
	deadlocked_so_far = FALSE;
	permanent = (generator->Priority (what_rule) < 50);	// Uli
	/* IM<b> */
	/*(void) StateSet->Add (nextstate, TRUE, permanent);*/
	if (!tracing && !StateSet->Add (nextstate, TRUE, permanent, TRUE)) {
	  /* Enters here only if result has been set by some other node */
	  StateCopy (workingstate, originalstate);	// restore workingstate
	  mutexes->LockMutex(MUTEX_TERMINATE);
	  Terminate = TRUE;
	  mutexes->UnLockMutex(MUTEX_TERMINATE);
	  return -1;
	}
	/* IM<e> */
	StateCopy (workingstate, originalstate);	// restore workingstate
      }
    }
  }
  return deadlocked_so_far;
}

// the following global variables have been set:
// theworld, curstate and what_rule
state *
RuleManager::NextState ()
{
  category = RULE;

  // fire rule
  generator->Code (what_rule);
  rules_fired++;
  /* IM<b> */
  if (!is_rules_fired_double)
    is_rules_fired_double = rules_fired == 0;
  rules_fired_d = rules_fired_d + 1.0;
  /* IM<e> */

  // update timesfired record
  NumTimesFired[what_rule]++;

  // print verbose message
  if (args->verbose.value)
    Reporter->print_fire_rule ();

  // Uli: invariant check moved
//  if (!Properties->CheckInvariants())
//    {
//      Error.Error("Invariant \"%s\" failed.",Properties->LastInvariantName());
//    }

  // get next state
#ifdef HASHC
/* IM<b> */
#ifdef HASHC_TRACE
/* IM<e> */
  if (args->trace_file.value)
    /* IM<b> */
    /*workingstate->previous.set (NumCurState);*/
    workingstate->previous.set (NumCurState, Communicate->GetRank ());
    /* IM<e> */
  else
/* IM<b> */
#endif
/* IM<e> */
#endif
    /* IM<b> */
    /*workingstate->previous.set (curstate);*/
    ;
    /* IM<e> */
  return workingstate;
}

void
RuleManager::print_world_to_state (StatePtr p, bool fullstate)
{
  state original;
  state nextstate;
  char *s;

  // save last state
  StateCopy (&original, workingstate);

  // generate next state
  for (what_rule = 0; what_rule < numrules; what_rule++) {
    category = CONDITION;
    if (generator->Condition (what_rule)) {
      category = RULE;
      generator->Code (what_rule);
      StateCopy (&nextstate, workingstate);

      if (StateEquivalent (&nextstate, p)) {
	// output the name of the rule and the last state in full
	/* IM<b> */
	s = generator->Name (what_rule);
	mutexes->LockMutex(MUTEX_PRINT);
	/* IM<e> */
	cout << "Rule "
	  // << rules[ what_rule ].name
	  /* IM<b> */
	  /*<< (s = generator->Name (what_rule))*/
	  << s
	  /* IM<e> */
	  << " fired.\n";
	/* IM<b> */
	mutexes->UnLockMutex(MUTEX_PRINT);
	/* IM<e> */
	delete[]s;		// Uli: avoid memory leak
	/* IM<b> */
	mutexes->UnLockMutex(MUTEX_PRINT);
	/* IM<e> */
	if (fullstate)
	  cout << "The last state of the trace (in full) is:\n";
	if (args->full_trace.value || fullstate)
	  theworld.print ();
	else
	  theworld.print_diff (&original);
	cout << "----------\n\n";
	/* IM<b> */
	mutexes->UnLockMutex(MUTEX_PRINT);
	/* IM<e> */
	return;
      }
      else
	StateCopy (workingstate, &original);
    }
  }
  Error.Notrace ("Internal Error:print_world_to_state().");
}

char *
RuleManager::LastRuleName ()
{
  return generator->Name (what_rule);
}

unsigned long
RuleManager::NumRulesFired ()
{
  return rules_fired;
}

void
RuleManager::print_rules_information ()
{
  /* IM<b> */
  /*bool exist;*/
  bool exist = FALSE;
  /* IM<e> */

  if (args->print_rule.value) {

    cout << "Rules Information:\n\n";
    for (int i = 0; i < RULES_IN_WORLD; i++)
      cout << "\tFired " << NumTimesFired[i] << " times\t- Rule \""
	<< generator->Name (i)
	<< "\"\n";
  }
  else {
    /* IM<b> */
    /*for (int i = 0; i < RULES_IN_WORLD; i++)*/
    for (int i = 0; i < RULES_IN_WORLD && !exist; i++)
    /* IM<e> */
      if (NumTimesFired[i] == 0)
	exist = TRUE;
    if (exist)
      cout << "Analysis of State Space:\n\n"
	<< "\tThere are rules that are never fired.\n"
	<<
	"\tIf you are running with symmetry, this may be why.  Otherwise,\n"
	<<
	"\tplease run this program with \"-pr\" for the rules information.\n";
  }
}

/************************************************************/
/* PropertyManager */
/************************************************************/
PropertyManager::PropertyManager ()
{
}

bool PropertyManager::CheckInvariants ()
{
  category = INVARIANT;
  for (what_invariant = 0; what_invariant < numinvariants; what_invariant++) {
    if (!(*invariants[what_invariant].condition) ())
      /* Uh oh, invariant blown. */
    {
      /* IM<b> */
      mutexes->LockMutex(MUTEX_RSLT); /* VERY DANGEROUS; check no other part of the code to make the inverse locking */
      result = 'n';
      mutexes->UnLockMutex(MUTEX_RSLT);
      /* IM<e> */
      return FALSE;
    }
  }
  return TRUE;
}

/* IM<b> */
bool PropertyManager::CheckInvariants (state *s)
{
  assert(0);
  return TRUE;
}
/* IM<e> */

char *
PropertyManager::LastInvariantName ()
{
  return invariants[what_invariant].name;
}

/************************************************************/
/* SymmetryManager */
/************************************************************/
SymmetryManager::SymmetryManager ()
{
}

/************************************************************/
/* POManager */
/************************************************************/
POManager::POManager ()
{
}

/* IM<b> */
#ifdef DEBUG_SIGNALS
//
// Debug signal terminations
//
void general_handler(int i) {
  if (Communicate != NULL)
    cout << "Caught signal "<< i << " on node " << Communicate->GetRank() << "\n";
  else
    cout << "Caught signal "<< i << "\n";
  cout.flush();
  char to_be_exec[2048];
  sprintf(to_be_exec, "gdb %s %d <<bdg\nbt\nthread 2\nbt\ndetach\nbdg >debug.%d", argv_p, getpid(), Communicate->GetRank());
  cout << "Debugging...\n";
  system(to_be_exec);
#ifdef WRITE_MPI_CALLS
  fprintf(Communicate->stream_MPI_fun, "%ld MPI_Iprobe(MESSAGE_STATES), %ld MPI_Iprobe(MESSAGE_TERMINATE), %ld MPI_Iprobe(MESSAGE_TERMINATE_PROBE);\n",
    Communicate->num_iprobe_states, Communicate->num_iprobe_terminate, Communicate->num_iprobe_terminate_probe);
  fclose(Communicate->stream_MPI_fun);
#endif
  /*int tmp = 1;
  while(tmp);*/
  /*if (Communicate != NULL)
    Error.Notrace("Caught signal %d on node %d\n", i, Communicate->GetRank());
  else
    Error.Notrace("Caught signal %d\n", i);*/
}
#endif
/* IM<e> */

/************************************************************/
/* AlgorithmManager */
/************************************************************/
AlgorithmManager::AlgorithmManager ()
{
  // why exists? (Norris)
  // oldnh = set_new_handler(&err_new_handler);

  // create managers
  StartState = new StartStateManager;
  Rules = new RuleManager;
  Properties = new PropertyManager;
  Symmetry = new SymmetryManager;
  PO = new POManager;
  Reporter = new ReportManager;

#ifdef HASHC
  h3 = new hash_function (BLOCKS_IN_WORLD);
/* IM<b> */
#ifdef HASHC_TRACE
  if (args->print_trace.value) {
    h3_others = new hash_function *[Communicate->GetNumProcs () - 1];
    for (int i = 0; i < Communicate->GetNumProcs () - 1; i++)
      h3_others[i] = NULL;
    Communicate->set_blocks_in_world (BLOCKS_IN_WORLD);
  }
#endif
/* IM<e> */
#endif

  /* IM<b> */
  if (Communicate->IsRoot()) {
  /* IM<e> */
  Reporter->CheckConsistentVersion ();
  if (args->main_alg.mode != argmain_alg::Nothing)
    Reporter->print_header ();
  Reporter->print_algorithm ();
  /* IM<b> */
  Communicate->print_capacity ();
  }
  /* IM<e> */

  switch (args->main_alg.mode) {
  case argmain_alg::Verify_bfs:
    StateSet = new StateManager (TRUE, NumStatesGivenBytes (args->mem.value));
    /* IM<b> */
    if (Communicate->IsRoot())
    /* IM<e> */
    StateSet->print_capacity ();
    break;
  case argmain_alg::Verify_dfs:
    StateSet =
      new StateManager (FALSE, NumStatesGivenBytes (args->mem.value));
    StateSet->print_capacity ();
    break;
  case argmain_alg::Simulate:
    StateSet = NULL;
    break;
  default:
    break;
  }

  /* IM<b> */
  if (Communicate->IsRoot()) {
  /* IM<e> */
  Reporter->print_warning ();
  /* IM<b> */
  }
  theworld.to_state (NULL);	// trick : marks variables in world
  /* IM<e> */

/* IM<b> */
#ifdef DEBUG_SIGNALS
  /* system dependent, there should always be 31 signals at least... */
  for (int i = 1; i <= 31; i++)
      signal(i, general_handler);
#endif
/* IM<e> */
};

/* IM<b> */
/************************************************************/
/* AlgorithmManager */
/************************************************************/
AlgorithmManager::~AlgorithmManager ()
{
  if (StartState != NULL) delete StartState;
  if (Rules != NULL) delete Rules;
  if (Properties != NULL) delete Properties;
  if (Symmetry != NULL) delete Symmetry;
  if (PO != NULL) delete PO;
  if (Reporter != NULL) delete Reporter;

  if (StateSet != NULL) delete StateSet;
};
/* IM<e> */

/****************************************
  The BFS verification main routines:
  void verify_bfs_standard()
  -- future extension:
  -- void verify_bfs_gode_dl()
  -- void verify_bfs_sleepset_rr()
  -- void verify_bfs_gode_sleepset_dl()
  ****************************************/
void
AlgorithmManager::verify_bfs ()
{
  // Use Global Variables: what_rule, curstate, theworld, queue, the_states
  setofrules fire;		// set of rule to be fired
  /* IM<b> */
  /*bool deadlocked;		// boolean for checking deadlock*/
  int deadlocked;
  /* IM<e> */

  /* IM<b> */
  if (Communicate->IsRoot()) {
  /* IM<e> */
  // print verbose message
  if (args->verbose.value)
    Reporter->print_verbose_header ();
  /* IM<b> */
  }
  /* IM<e> */

  cout.flush ();

  /* IM<b> */
  /* moved before the thread creation */
  /*theworld.to_state (NULL);	// trick : marks variables in world*/
  /* IM<e> */

  // Generate all start state
  /* IM<b> */
  /*StartState->AllStartStates ();*/
  if (Communicate->IsRoot() && !StartState->AllStartStates ()) {
    mutexes->LockMutex(MUTEX_TERMINATE);
    Terminate = TRUE;
    mutexes->UnLockMutex(MUTEX_TERMINATE);
  }
  /* IM<e> */

#ifdef HASHC
/* IM<b> */
#if 0 /* Impossibile to speak of levels, and so to compute the omission probability */
/* IM<e> */
  // omission probability calculation
  StateSet->CheckLevel ();
/* IM<b> */
#endif
/* IM<e> */
#endif

  // search state space
  /* IM<b> */
  /*while (!StateSet->QueueIsEmpty ()) {*/
  while (!StateSet->ParTerminate ()) {
    LOG_VERBOSE_LIMIT_FREQUENCY(WORKER_LOOP_ID, 1, " (control-flow) Worker thread loop running.\n");
    bool checked;
  /* IM<e> */
    // get and remove a state from the queue
    // please make sure that global variable curstate does not change 
    // throughout the iteration 
    /* IM<b> */
    /*curstate = StateSet->QueueDequeue ();
    NumCurState++;*/
    curstate = StateSet->QueueDequeue (checked, NumCurState);
    if (!checked) {
      if (StateSet->SimpleWasPresent (curstate))
        continue;
#ifdef HASHC_TRACE
      if (args->trace_file.value)
	NumCurState = TraceFile->numLast ();
#endif
    }
    /* IM<e> */
    StateCopy (workingstate, curstate);

    // print verbose message
    if (args->verbose.value)
      Reporter->print_curstate ();

    // generate all next state 
    deadlocked = Rules->AllNextStates ();

    /* IM<b> */
    // check deadlock 
    /*if (deadlocked && !args->no_deadlock.value)
      Error.Deadlocked ("Deadlocked state found.");*/
    if (!args->no_deadlock.value && deadlocked != -1 && deadlocked != 0) {
      mutexes->LockMutex(MUTEX_RSLT);
      result = 'd';
      mutexes->UnLockMutex(MUTEX_RSLT);
      Error.Deadlocked ("Deadlocked state found.");
    }
    /* IM<e> */

/* IM<b> */
/*#ifdef HASHC*/
#if 0
/* IM<e> */
    // omission probability calculation
    StateSet->CheckLevel ();

    delete curstate;
#endif

/* IM<b> */
    /*if (!checked)
      delete curstate;*/
/* IM<e> */
  }				// while
  /* IM<b> */
  mutexes->LockMutex(MUTEX_TERMINATE);
  Terminate = TRUE;
  mutexes->UnLockMutex(MUTEX_TERMINATE);
  pthread_join(*(Communicate->GetThread()), NULL);
  if (Communicate->IsRoot()) {
  /* IM<e> */
  Reporter->print_final_report ();
  /* IM<b> */
    if (result != 'y' && args->print_trace.value) {
      /* Here, some other node has discovered the error */
      if (result == 'd')
	Error.Deadlocked("Deadlocked state found.");
      else if (result == 'n')
	Error.Deadlocked("An invariant failed.");
      else /* result == 'e' */
        Error.Error("A generic error or an assertion error occurred.");
    }
    /* If Error.Deadlocked is executed, the program is finished */
  }
#ifdef HASHC_TRACE
  else if (result != 'y' && args->print_trace.value)
    Communicate->LoopForStates_nothreads();
#endif
  /* IM<e> */
}

/****************************************
  The DFS verification routine:
  void verify_dfs()
  -- not changed yet 
  ****************************************/

void
AlgorithmManager::verify_dfs ()
{
  // use global variables: what_rule, curstate, theworld, queue, the_states
  state *nextstate;
  bool deadlocked_so_far = TRUE;

  // print verbose message
  if (args->verbose.value)
    Reporter->print_verbose_header ();

  theworld.to_state (NULL);	// trick : marks variables in world

  // for each startstate start a DFS search
  while ((curstate = StartState->NextStartState ()) != NULL) {
    (void) StateSet->Add (curstate, FALSE, TRUE);

    while (!StateSet->QueueIsEmpty ()) {
      // get the last state from the stack
      curstate = StateSet->QueueTop ();
      StateCopy (workingstate, curstate);

      // l) method:
      // get a different next state by incrementing what_rule
      // until a rule is enabled and the new state is different from the
      // old state or all the rules are exhausted
      // 2) setting of varibles
      // what_rule is set by previous iteration
      // curstate is set at the beginning of the iteration
      // theworld is set at the beginning of the iteration

      // get next rule that is enabled and fire it
      // set global variable what_rule

      nextstate = Rules->SeqNextState ();

      if (nextstate != NULL) {
	if (StateCmp (curstate, nextstate) != 0) {
	  // curstate state does not deadlock
	  deadlocked_so_far = FALSE;

	  // check if the next state has been searched or not
	  if (StateSet->Add (nextstate, TRUE, TRUE)) {
	    // curstate state does not deadlock, but the next state might
	    deadlocked_so_far = TRUE;
	  }
	  else {
	    // a rule has been fired and the next state has been searched
	    // ==> check next rule
	    if (args->verbose.value)
	      cout << "This state has been examined, try another rule.\n";
	  }
	}
	else if (args->verbose.value)
	  cout << "This state has been examined, try another rule.\n";
      }
      else {
	// check deadlock
	if (deadlocked_so_far && !args->no_deadlock.value) {
	  if (args->verbose.value)
	    Reporter->print_dfs_deadlock ();
	  Error.Deadlocked ("Deadlocked state found.");
	}

	// remove explored state
	(void) StateSet->QueueDequeue ();

	// print verbose message
	if (args->verbose.value)
	  Reporter->print_retrack ();

	// previous state does not deadlock, as it gives the state just removed
	deadlocked_so_far = FALSE;

#ifdef HASHC
	delete curstate;
#endif
      }				// if
    }				// while

    // print verbose message
    if (args->verbose.value)
      cout << "------------------------------\n"
	<< "Finished working on one statestate.\n"
	<< "------------------------------\n";
  }				// for
  Reporter->print_final_report ();
}

/****************************************
  The simulation main routine:
  void simulate()
  ****************************************/

// Uli: added required call to theworld.to_state()
void
AlgorithmManager::simulate ()
{
  // progress report must be printed out so as to make sense 
  // otherwise, if there is no bug, the program just run on for ever
  // without any message.

  // print verbose message
  if (args->verbose.value)
    Reporter->print_verbose_header ();

  Reporter->StartSimulation ();

  theworld.to_state (NULL);	// trick: marks variables in world

  // GetRandomStartState will choose a Startstate randomly
  curstate = StartState->RandomStartState ();

  // simulate
  while (1) {
    // SimulateRandomRule always executes a rule that leads to
    // a different state.
    curstate = Rules->RandomNextState ();
  }
}

/********************
  $Log: mu_system.C,v $
  Revision 1.3  1999/01/29 08:28:09  uli
  efficiency improvements for security protocols

  Revision 1.2  1999/01/29 07:49:11  uli
  bugfixes

  Revision 1.4  1996/08/07 18:54:33  ip
  last bug fix on NextRule/SetNextEnabledRule has a bug; fixed this turn

  Revision 1.3  1996/08/07 01:07:55  ip
  Fixed bug on what_rule setting during guard evaluation; otherwise, bad diagnoistic message on undefine error on guard

  Revision 1.2  1996/08/07 00:15:26  ip
  fixed while code generation bug

  Revision 1.1  1996/08/07 00:14:46  ip
  Initial revision

********************/
