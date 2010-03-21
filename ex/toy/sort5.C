/******************************
  Program "sort5.m" compiled by "Eddy_Murphi Release 3.2.4"

  Murphi Last Modefied Date: "June 19 2009"
  Murphi Last Compiled date: "Mar 13 2010"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Eddy_Murphi Release 3.2.4"
#define MURPHI_DATE "June 19 2009"
#define PROTOCOL_NAME "sort5"
#define BITS_IN_WORLD 21
#define HASHC
#define PARALLEL

/********************
  Include
 ********************/
#include "mu_prolog.inc"

/********************
  Decl declaration
 ********************/

class mu_1_ind_t: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_ind_t& val) { return mu__byte::operator=((int) val); };
  mu_1_ind_t (char *name, int os): mu__byte(0, 4, 3, name, os) {};
  mu_1_ind_t (void): mu__byte(0, 4, 3) {};
  mu_1_ind_t (int val): mu__byte(0, 4, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_ind_t mu_1_ind_t_undefined_var;

class mu_1_val_t: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_val_t& val) { return mu__byte::operator=((int) val); };
  mu_1_val_t (char *name, int os): mu__byte(0, 4, 3, name, os) {};
  mu_1_val_t (void): mu__byte(0, 4, 3) {};
  mu_1_val_t (int val): mu__byte(0, 4, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_val_t mu_1_val_t_undefined_var;

class mu_1_arr_t
{
 public:
  mu_1_val_t array[ 5 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1_arr_t (char *n, int os) { set_self(n, os); };
  mu_1_arr_t ( void ) {};
  virtual ~mu_1_arr_t ();
  mu_1_val_t& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 4 ) )
      return array[ index - 0 ];
    else {
      if (index==UNDEFVAL) 
        Error.Error("Indexing to %s using an undefined value.", name);
      else
        Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 0 ];
#endif
  };
  mu_1_arr_t& operator= (const mu_1_arr_t& from)
  {
    for (int i = 0; i < 5; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1_arr_t& a, mu_1_arr_t& b)
  {
    int w;
    for (int i=0; i<5; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1_arr_t& a, mu_1_arr_t& b)
  {
    int w;
    for (int i=0; i<5; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<5; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<5; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 5; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 5; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 5; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 5; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 5; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 5; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1_arr_t::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_arr_t::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_arr_t::set_self( char *n, int os)
{
  char* s;
  name = n;
  for(int i = 0; i < 5; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 3 + os);
    delete[] s;
  }
};
mu_1_arr_t::~mu_1_arr_t()
{
}
/*** end array declaration ***/
mu_1_arr_t mu_1_arr_t_undefined_var;

class mu__subrange_5: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_5& val) { return mu__byte::operator=((int) val); };
  mu__subrange_5 (char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_5 (void): mu__byte(0, 3, 3) {};
  mu__subrange_5 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_5 mu__subrange_5_undefined_var;

const int mu_N = 5;
/*** Variable declaration ***/
mu_1_ind_t mu_i("i",0);

/*** Variable declaration ***/
mu_1_ind_t mu_j("j",3);

/*** Variable declaration ***/
mu_1_arr_t mu_a("a",6);

void mu_IncrementMod(mu_1_ind_t& mu_v, const mu_1_ind_t& mu_m)
{
if ( (mu_v) == (mu_m) )
{
mu_v = 0;
}
else
{
mu_v = (mu_v) + (1);
}
};
/*** end procedure declaration ***/

void mu_Increment(mu_1_ind_t& mu_v)
{
mu_IncrementMod ( mu_v, 4 );
};
/*** end procedure declaration ***/

void mu_Swap(mu_1_arr_t& mu_a)
{
/*** Variable declaration ***/
mu_1_val_t mu_tmp("tmp",0);

mu_tmp = mu_a[mu_i];
mu_a[mu_i] = mu_a[mu_j];
if (mu_tmp.isundefined())
  mu_a[mu_j].undefine();
else
  mu_a[mu_j] = mu_tmp;
mu_tmp = 0;
};
/*** end procedure declaration ***/





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_i.clear();
  mu_j.clear();
  mu_a.clear();
}
void world_class::undefine()
{
  mu_i.undefine();
  mu_j.undefine();
  mu_a.undefine();
}
void world_class::reset()
{
  mu_i.reset();
  mu_j.reset();
  mu_a.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_i.print();
  mu_j.print();
  mu_a.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_i.print_statistic();
  mu_j.print_statistic();
  mu_a.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_i.print_diff(prevstate);
    mu_j.print_diff(prevstate);
    mu_a.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_i.to_state( newstate );
  mu_j.to_state( newstate );
  mu_a.to_state( newstate );
}
void world_class::setstate(state *thestate)
{
}


/********************
  Rule declarations
 ********************/
/******************** RuleBase0 ********************/
class RuleBase0
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    return tsprintf("swap");
  }
  bool Condition(unsigned r)
  {
bool mu__boolexpr0;
  if (!((mu_i) < (mu_j))) mu__boolexpr0 = FALSE ;
  else {
  mu__boolexpr0 = ((mu_a[mu_i]) > (mu_a[mu_j])) ; 
}
  return mu__boolexpr0;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    while (what_rule < 1 )
      {
        if ( ( TRUE  ) ) {
bool mu__boolexpr1;
  if (!((mu_i) < (mu_j))) mu__boolexpr1 = FALSE ;
  else {
  mu__boolexpr1 = ((mu_a[mu_i]) > (mu_a[mu_j])) ; 
}
              if (mu__boolexpr1) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 1;
        }
        else
          what_rule += 1;
    r = what_rule - 0;
    }
  }

  void Code(unsigned r)
  {
mu_Swap ( mu_a );
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase1 ********************/
class RuleBase1
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    return tsprintf("j");
  }
  bool Condition(unsigned r)
  {
  return mu_true;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1;
    while (what_rule < 2 )
      {
        if ( ( TRUE  ) ) {
              if (mu_true) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 1;
        }
        else
          what_rule += 1;
    r = what_rule - 1;
    }
  }

  void Code(unsigned r)
  {
mu_Increment ( mu_j );
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase2 ********************/
class RuleBase2
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    return tsprintf("i");
  }
  bool Condition(unsigned r)
  {
  return mu_true;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 2;
    while (what_rule < 3 )
      {
        if ( ( TRUE  ) ) {
              if (mu_true) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 1;
        }
        else
          what_rule += 1;
    r = what_rule - 2;
    }
  }

  void Code(unsigned r)
  {
mu_IncrementMod ( mu_i, 4 );
  };

  bool UnFair()
  { return FALSE; }
};
class NextStateGenerator
{
  RuleBase0 R0;
  RuleBase1 R1;
  RuleBase2 R2;
public:
void SetNextEnabledRule(unsigned & what_rule)
{
  category = CONDITION;
  if (what_rule<1)
    { R0.NextRule(what_rule);
      if (what_rule<1) return; }
  if (what_rule>=1 && what_rule<2)
    { R1.NextRule(what_rule);
      if (what_rule<2) return; }
  if (what_rule>=2 && what_rule<3)
    { R2.NextRule(what_rule);
      if (what_rule<3) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=0) return R0.Condition(r-0);
  if (r>=1 && r<=1) return R1.Condition(r-1);
  if (r>=2 && r<=2) return R2.Condition(r-2);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
}
void Code(unsigned r)
{
  if (r<=0) { R0.Code(r-0); return; } 
  if (r>=1 && r<=1) { R1.Code(r-1); return; } 
  if (r>=2 && r<=2) { R2.Code(r-2); return; } 
}
int Priority(unsigned short r)
{
  if (r<=0) { return R0.Priority(); } 
  if (r>=1 && r<=1) { return R1.Priority(); } 
  if (r>=2 && r<=2) { return R2.Priority(); } 
}
char * Name(unsigned r)
{
  if (r<=0) return R0.Name(r-0);
  if (r>=1 && r<=1) return R1.Name(r-1);
  if (r>=2 && r<=2) return R2.Name(r-2);
  return NULL;
}
};
const unsigned numrules = 3;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 3


/********************
  Startstate records
 ********************/
/******************** StartStateBase0 ********************/
class StartStateBase0
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("Startstate 0");
  }
  void Code(unsigned short r)
  {
mu_i.clear();
mu_j.clear();
{
for(int mu_f = 0; mu_f <= 4; mu_f++) {
mu_a[mu_f] = (4) - (mu_f);
};
};
  };

  bool UnFair()
  { return FALSE; }
};
class StartStateGenerator
{
  StartStateBase0 S0;
public:
void Code(unsigned short r)
{
  if (r<=0) { S0.Code(r-0); return; }
}
char * Name(unsigned short r)
{
  if (r<=0) return S0.Name(r-0);
  return NULL;
}
};
unsigned short StartStateManager::numstartstates = 1;

/********************
  Invariant records
 ********************/
int mu__invariant_2() // Invariant "Invariant 0"
{
bool mu__quant3; 
mu__quant3 = FALSE;
{
for(int mu_i = 0; mu_i <= 3; mu_i++) {
if ( ((mu_a[mu_i]) > (mu_a[(mu_i) + (1)])) )
  { mu__quant3 = TRUE; break; }
};
};
return mu__quant3;
};

bool mu__condition_4() // Condition for Rule "Invariant 0"
{
  return mu__invariant_2( );
}

/**** end rule declaration ****/

const rulerec invariants[] = {
{"Invariant 0", &mu__condition_4, NULL, FALSE},
};
const unsigned short numinvariants = 1;

/******************/
bool mu__true_live() { return TRUE; }
/******************/

/********************
  Liveness records
 ********************/
const liverec livenesses[] = {
{ NULL, NULL, NULL, NULL, E }};
const unsigned short numlivenesses = 0;

/********************
  Fairstates records
 ********************/
const rulerec fairnesses[] = {
{ NULL, NULL, NULL, FALSE }};
const unsigned short numfairnesses = 0;

/********************
  Normal/Canonicalization for scalarset
 ********************/
/*
j:NoScalarset
i:NoScalarset
a:NoScalarset
*/

/********************
Code for symmetry
 ********************/

/********************
 Permutation Set Class
 ********************/
class PermSet
{
public:
  // book keeping
  enum PresentationType {Simple, Explicit};
  PresentationType Presentation;

  void ResetToSimple();
  void ResetToExplicit();
  void SimpleToExplicit();
  void SimpleToOne();
  bool NextPermutation();

  void Print_in_size()
  { int ret=0; for (int i=0; i<count; i++) if (in[i]) ret++; cout << "in_size:" << ret << "\n"; }


  /********************
   Simple and efficient representation
   ********************/
  bool AlreadyOnlyOneRemain;
  bool MoreThanOneRemain();


  /********************
   Explicit representation
  ********************/
  unsigned long size;
  unsigned long count;
  // in will be of product of factorial sizes for fast canonicalize
  // in will be of size 1 for reduced local memory canonicalize
  bool * in;

  // auxiliary for explicit representation

  // in/perm/revperm will be of factorial size for fast canonicalize
  // they will be of size 1 for reduced local memory canonicalize
  // second range will be size of the scalarset
  // procedure for explicit representation
  // General procedure
  PermSet();
  bool In(int i) const { return in[i]; };
  void Add(int i) { for (int j=0; j<i; j++) in[j] = FALSE;};
  void Remove(int i) { in[i] = FALSE; };
};
bool PermSet::MoreThanOneRemain()
{
  int i,j;
  if (AlreadyOnlyOneRemain)
    return FALSE;
  else {
  }
  AlreadyOnlyOneRemain = TRUE;
  return FALSE;
}
PermSet::PermSet()
: Presentation(Simple)
{
  int i,j,k;
  if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize) {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];

    // Set perm and revperm

    // setting up combination of permutations
    // for different scalarset
    int carry;
    size = 1;
    count = 1;
    for (i=0; i<1; i++)
      {
        carry = 1;
        in[i]= TRUE;
    }
  }
  else
  {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];
  in[0] = TRUE;
  }
}
void PermSet::ResetToSimple()
{
  int i;

  AlreadyOnlyOneRemain = FALSE;
  Presentation = Simple;
}
void PermSet::ResetToExplicit()
{
  for (int i=0; i<1; i++) in[i] = TRUE;
  Presentation = Explicit;
}
void PermSet::SimpleToExplicit()
{
  int i,j,k;
  int start, class_size;

  // Setup range for mapping

  // To be In or not to be

  // setup explicit representation 
  // Set perm and revperm
  for (i=0; i<1; i++)
    {
      in[i] = TRUE;
    }
  Presentation = Explicit;
  if (args->test_parameter1.value==0) Print_in_size();
}
void PermSet::SimpleToOne()
{
  int i,j,k;
  int class_size;
  int start;


  // Setup range for mapping
  Presentation = Explicit;
}
bool PermSet::NextPermutation()
{
  bool nexted = FALSE;
  int start, end; 
  int class_size;
  int temp;
  int j,k;

  // algorithm
  // for each class
  //   if forall in the same class reverse_sorted, 
  //     { sort again; goto next class }
  //   else
  //     {
  //       nexted = TRUE;
  //       for (j from l to r)
  // 	       if (for all j+ are reversed sorted)
  // 	         {
  // 	           swap j, j+1
  // 	           sort all j+ again
  // 	           break;
  // 	         }
  //     }
if (!nexted) return FALSE;
  return TRUE;
}

/********************
 Symmetry Class
 ********************/
class SymmetryClass
{
  PermSet Perm;
  bool BestInitialized;
  state BestPermutedState;

  // utilities
  void SetBestResult(int i, state* temp);
  void ResetBestResult() {BestInitialized = FALSE;};

public:
  // initializer
  SymmetryClass() : Perm(), BestInitialized(FALSE) {};
  ~SymmetryClass() {};

  void Normalize(state* s);

  void Exhaustive_Fast_Canonicalize(state *s);
  void Heuristic_Fast_Canonicalize(state *s);
  void Heuristic_Small_Mem_Canonicalize(state *s);
  void Heuristic_Fast_Normalize(state *s);

  void MultisetSort(state* s);
};


/********************
 Symmetry Class Members
 ********************/
void SymmetryClass::MultisetSort(state* s)
{
        mu_j.MultisetSort();
        mu_i.MultisetSort();
        mu_a.MultisetSort();
}
void SymmetryClass::Normalize(state* s)
{
  switch (args->sym_alg.mode) {
  case argsym_alg::Exhaustive_Fast_Canonicalize:
    Exhaustive_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Canonicalize:
    Heuristic_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Small_Mem_Canonicalize:
    Heuristic_Small_Mem_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Normalize:
    Heuristic_Fast_Normalize(s);
    break;
  default:
    Heuristic_Fast_Canonicalize(s);
  }
}

/********************
 Permute and Canonicalize function for different types
 ********************/
void mu_1_ind_t::Permute(PermSet& Perm, int i) {};
void mu_1_ind_t::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_ind_t::Canonicalize(PermSet& Perm) {};
void mu_1_ind_t::SimpleLimit(PermSet& Perm) {};
void mu_1_ind_t::ArrayLimit(PermSet& Perm) {};
void mu_1_ind_t::Limit(PermSet& Perm) {};
void mu_1_ind_t::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_val_t::Permute(PermSet& Perm, int i) {};
void mu_1_val_t::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_val_t::Canonicalize(PermSet& Perm) {};
void mu_1_val_t::SimpleLimit(PermSet& Perm) {};
void mu_1_val_t::ArrayLimit(PermSet& Perm) {};
void mu_1_val_t::Limit(PermSet& Perm) {};
void mu_1_val_t::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_arr_t::Permute(PermSet& Perm, int i)
{
  static mu_1_arr_t temp("Permute_mu_1_arr_t",-1);
  int j;
  for (j=0; j<5; j++)
    array[j].Permute(Perm, i);
};
void mu_1_arr_t::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1_arr_t::Canonicalize(PermSet& Perm){};
void mu_1_arr_t::SimpleLimit(PermSet& Perm){}
void mu_1_arr_t::ArrayLimit(PermSet& Perm) {}
void mu_1_arr_t::Limit(PermSet& Perm){}
void mu_1_arr_t::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu__subrange_5::Permute(PermSet& Perm, int i) {};
void mu__subrange_5::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_5::Canonicalize(PermSet& Perm) {};
void mu__subrange_5::SimpleLimit(PermSet& Perm) {};
void mu__subrange_5::ArrayLimit(PermSet& Perm) {};
void mu__subrange_5::Limit(PermSet& Perm) {};
void mu__subrange_5::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };

/********************
 Auxiliary function for error trace printing
 ********************/
bool match(state* ns, StatePtr p)
{
  int i;
  static PermSet Perm;
  static state temp;
  StateCopy(&temp, ns);
  if (args->symmetry_reduction.value)
    {
      if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize) {
        Perm.ResetToExplicit();
        for (i=0; i<Perm.count; i++)
          if (Perm.In(i))
            {
              if (ns != workingstate)
                  StateCopy(workingstate, ns);
              
              mu_j.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_j.MultisetSort();
              mu_i.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_i.MultisetSort();
              mu_a.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_a.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
      else {
        Perm.ResetToSimple();
        Perm.SimpleToOne();
        if (ns != workingstate)
          StateCopy(workingstate, ns);

          mu_j.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_j.MultisetSort();
          mu_i.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_i.MultisetSort();
          mu_a.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_a.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_j.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_j.MultisetSort();
              mu_i.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_i.MultisetSort();
              mu_a.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_a.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
    }
  if (!args->symmetry_reduction.value
      && args->multiset_reduction.value)
    {
      if (ns != workingstate)
          StateCopy(workingstate, ns);
      mu_j.MultisetSort();
      mu_i.MultisetSort();
      mu_a.MultisetSort();
      if (p.compare(workingstate)) {
        StateCopy(workingstate,&temp); return TRUE; }
      StateCopy(workingstate,&temp);
      return FALSE;
    }
  return (p.compare(ns));
}

/********************
 Canonicalization by fast exhaustive generation of
 all permutations
 ********************/
void SymmetryClass::Exhaustive_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;
  Perm.ResetToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_j.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_j.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_i.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_i.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_a.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_a.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 ********************/
void SymmetryClass::Heuristic_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 and use less local memory
 ********************/
void SymmetryClass::Heuristic_Small_Mem_Canonicalize(state* s)
{
  unsigned long cycle;
  static state temp;

  Perm.ResetToSimple();

};

/********************
 Normalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and for all other variables, pick any remaining permutation
 ********************/
void SymmetryClass::Heuristic_Fast_Normalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

};

/********************
  Include
 ********************/
#include "mu_epilog.inc"
