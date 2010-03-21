/******************************
  Program "sets.m" compiled by "Eddy_Murphi Release 3.2.4"

  Murphi Last Modefied Date: "June 19 2009"
  Murphi Last Compiled date: "Mar 13 2010"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Eddy_Murphi Release 3.2.4"
#define MURPHI_DATE "June 19 2009"
#define PROTOCOL_NAME "sets"
#define BITS_IN_WORLD 60
#define HASHC
#define PARALLEL

/********************
  Include
 ********************/
#include "mu_prolog.inc"

/********************
  Decl declaration
 ********************/

class mu_1_elt_t: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_elt_t& val) { return mu__byte::operator=((int) val); };
  mu_1_elt_t (char *name, int os): mu__byte(1, 4, 3, name, os) {};
  mu_1_elt_t (void): mu__byte(1, 4, 3) {};
  mu_1_elt_t (int val): mu__byte(1, 4, 3, "Parameter or function result.", 0)
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
mu_1_elt_t mu_1_elt_t_undefined_var;

class mu_1_entry_t: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_entry_t& val) { return mu__byte::operator=((int) val); };
  mu_1_entry_t (char *name, int os): mu__byte(0, 4, 3, name, os) {};
  mu_1_entry_t (void): mu__byte(0, 4, 3) {};
  mu_1_entry_t (int val): mu__byte(0, 4, 3, "Parameter or function result.", 0)
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
mu_1_entry_t mu_1_entry_t_undefined_var;

class mu_1_setInd_t: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_setInd_t& val) { return mu__byte::operator=((int) val); };
  mu_1_setInd_t (char *name, int os): mu__byte(0, 11, 4, name, os) {};
  mu_1_setInd_t (void): mu__byte(0, 11, 4) {};
  mu_1_setInd_t (int val): mu__byte(0, 11, 4, "Parameter or function result.", 0)
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
mu_1_setInd_t mu_1_setInd_t_undefined_var;

class mu_1__type_0
{
 public:
  mu_1_entry_t array[ 12 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_0 (char *n, int os) { set_self(n, os); };
  mu_1__type_0 ( void ) {};
  virtual ~mu_1__type_0 ();
  mu_1_entry_t& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 11 ) )
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
  mu_1__type_0& operator= (const mu_1__type_0& from)
  {
    for (int i = 0; i < 12; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_0& a, mu_1__type_0& b)
  {
    int w;
    for (int i=0; i<12; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_0& a, mu_1__type_0& b)
  {
    int w;
    for (int i=0; i<12; i++) {
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
    for (int i=0; i<12; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<12; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 12; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 12; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 12; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 12; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 12; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 12; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_0::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_0::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_0::set_self( char *n, int os)
{
  char* s;
  name = n;
  for(int i = 0; i < 12; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 3 + os);
    delete[] s;
  }
};
mu_1__type_0::~mu_1__type_0()
{
}
/*** end array declaration ***/
mu_1__type_0 mu_1__type_0_undefined_var;

class mu_1__type_1: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_1& val) { return mu__byte::operator=((int) val); };
  mu_1__type_1 (char *name, int os): mu__byte(0, 12, 4, name, os) {};
  mu_1__type_1 (void): mu__byte(0, 12, 4) {};
  mu_1__type_1 (int val): mu__byte(0, 12, 4, "Parameter or function result.", 0)
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
mu_1__type_1 mu_1__type_1_undefined_var;

class mu_1__type_2: public mu__long
{
 public:
  inline int operator=(int val) { return mu__long::operator=(val); };
  inline int operator=(const mu_1__type_2& val) { return mu__long::operator=((int) val); };
  mu_1__type_2 (char *name, int os): mu__long(0, 1000, 10, name, os) {};
  mu_1__type_2 (void): mu__long(0, 1000, 10) {};
  mu_1__type_2 (int val): mu__long(0, 1000, 10, "Parameter or function result.", 0)
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
mu_1__type_2 mu_1__type_2_undefined_var;

class mu_1__type_3: public mu__long
{
 public:
  inline int operator=(int val) { return mu__long::operator=(val); };
  inline int operator=(const mu_1__type_3& val) { return mu__long::operator=((int) val); };
  mu_1__type_3 (char *name, int os): mu__long(0, 1000, 10, name, os) {};
  mu_1__type_3 (void): mu__long(0, 1000, 10) {};
  mu_1__type_3 (int val): mu__long(0, 1000, 10, "Parameter or function result.", 0)
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
mu_1__type_3 mu_1__type_3_undefined_var;

class mu_1_set_t
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1__type_0 mu_a;
  mu_1__type_1 mu_n;
  mu_1__type_2 mu_numIns;
  mu_1__type_3 mu_numDel;
  mu_1_set_t ( char *n, int os ) { set_self(n,os); };
  mu_1_set_t ( void ) {};

  virtual ~mu_1_set_t(); 
friend int CompareWeight(mu_1_set_t& a, mu_1_set_t& b)
  {
    int w;
    w = CompareWeight(a.mu_a, b.mu_a);
    if (w!=0) return w;
    w = CompareWeight(a.mu_n, b.mu_n);
    if (w!=0) return w;
    w = CompareWeight(a.mu_numIns, b.mu_numIns);
    if (w!=0) return w;
    w = CompareWeight(a.mu_numDel, b.mu_numDel);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_set_t& a, mu_1_set_t& b)
  {
    int w;
    w = Compare(a.mu_a, b.mu_a);
    if (w!=0) return w;
    w = Compare(a.mu_n, b.mu_n);
    if (w!=0) return w;
    w = Compare(a.mu_numIns, b.mu_numIns);
    if (w!=0) return w;
    w = Compare(a.mu_numDel, b.mu_numDel);
    if (w!=0) return w;
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
    mu_a.MultisetSort();
    mu_n.MultisetSort();
    mu_numIns.MultisetSort();
    mu_numDel.MultisetSort();
  }
  void print_statistic()
  {
    mu_a.print_statistic();
    mu_n.print_statistic();
    mu_numIns.print_statistic();
    mu_numDel.print_statistic();
  }
  void clear() {
    mu_a.clear();
    mu_n.clear();
    mu_numIns.clear();
    mu_numDel.clear();
 };
  void undefine() {
    mu_a.undefine();
    mu_n.undefine();
    mu_numIns.undefine();
    mu_numDel.undefine();
 };
  void reset() {
    mu_a.reset();
    mu_n.reset();
    mu_numIns.reset();
    mu_numDel.reset();
 };
  void print() {
    mu_a.print();
    mu_n.print();
    mu_numIns.print();
    mu_numDel.print();
  };
  void print_diff(state *prevstate) {
    mu_a.print_diff(prevstate);
    mu_n.print_diff(prevstate);
    mu_numIns.print_diff(prevstate);
    mu_numDel.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_a.to_state(thestate);
    mu_n.to_state(thestate);
    mu_numIns.to_state(thestate);
    mu_numDel.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_set_t& operator= (const mu_1_set_t& from) {
    mu_a = from.mu_a;
    mu_n.value(from.mu_n.value());
    mu_numIns.value(from.mu_numIns.value());
    mu_numDel.value(from.mu_numDel.value());
    return *this;
  };
};

  void mu_1_set_t::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_set_t::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_set_t::set_self(char *n, int os)
{
  name = n;
  mu_a.set_self_2(name, ".a", os + 0 );
  mu_n.set_self_2(name, ".n", os + 36 );
  mu_numIns.set_self_2(name, ".numIns", os + 40 );
  mu_numDel.set_self_2(name, ".numDel", os + 50 );
}

mu_1_set_t::~mu_1_set_t()
{
}

/*** end record declaration ***/
mu_1_set_t mu_1_set_t_undefined_var;

class mu__subrange_10: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_10& val) { return mu__byte::operator=((int) val); };
  mu__subrange_10 (char *name, int os): mu__byte(0, 10, 4, name, os) {};
  mu__subrange_10 (void): mu__byte(0, 10, 4) {};
  mu__subrange_10 (int val): mu__byte(0, 10, 4, "Parameter or function result.", 0)
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
mu__subrange_10 mu__subrange_10_undefined_var;

const int mu_MAX_SET_SIZE = 12;
const int mu_MAX_OPS = 1000;
const int mu_NUM_ELT = 4;
/*** Variable declaration ***/
mu_1_set_t mu_s("s",0);

void mu_Sort(mu_1_set_t& mu_s)
{
/*** Variable declaration ***/
mu_1_entry_t mu_tmpElt("tmpElt",0);

{
for(int mu_i = 0; mu_i <= 10; mu_i++) {
{
int mu__ub4 = 11;
for (int mu_j = (mu_i) + (1); mu_j <= mu__ub4; mu_j += 1) {
bool mu__boolexpr5;
  if (!((mu_i) < (mu_j))) mu__boolexpr5 = FALSE ;
  else {
  mu__boolexpr5 = ((mu_s.mu_a[mu_i]) < (mu_s.mu_a[mu_j])) ; 
}
if ( mu__boolexpr5 )
{
mu_tmpElt = mu_s.mu_a[mu_i];
mu_s.mu_a[mu_i] = mu_s.mu_a[mu_j];
if (mu_tmpElt.isundefined())
  mu_s.mu_a[mu_j].undefine();
else
  mu_s.mu_a[mu_j] = mu_tmpElt;
mu_tmpElt = 0;
}
};
};
};
};
};
/*** end procedure declaration ***/

void mu_Insert(mu_1_set_t& mu_s, const mu_1_elt_t& mu_e)
{
if (mu_e.isundefined())
  mu_s.mu_a[mu_s.mu_n].undefine();
else
  mu_s.mu_a[mu_s.mu_n] = mu_e;
mu_s.mu_n = (mu_s.mu_n) + (1);
mu_s.mu_numIns = (mu_s.mu_numIns) + (1);
mu_Sort ( mu_s );
};
/*** end procedure declaration ***/

void mu_Delete(mu_1_set_t& mu_s, const mu_1_elt_t& mu_e)
{
{
for(int mu_i = 0; mu_i <= 11; mu_i++) {
if ( (mu_s.mu_a[mu_i]) == (mu_e) )
{
mu_s.mu_a[mu_i] = 0;
mu_s.mu_n = (mu_s.mu_n) - (1);
mu_s.mu_numDel = (mu_s.mu_numDel) + (1);
}
};
};
mu_Sort ( mu_s );
};
/*** end procedure declaration ***/





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_s.clear();
}
void world_class::undefine()
{
  mu_s.undefine();
}
void world_class::reset()
{
  mu_s.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_s.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_s.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_s.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_s.to_state( newstate );
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
    static mu_1_elt_t mu_e;
    mu_e.value((r % 4) + 1);
    r = r / 4;
    return tsprintf("Delete last inserted elt, e:%s", mu_e.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_elt_t mu_e;
    mu_e.value((r % 4) + 1);
    r = r / 4;
  return (mu_s.mu_n) > (0);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    static mu_1_elt_t mu_e;
    mu_e.value((r % 4) + 1);
    r = r / 4;
    while (what_rule < 4 )
      {
        if ( ( TRUE  ) ) {
              if ((mu_s.mu_n) > (0)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 4;
        }
        else
          what_rule += 4;
    r = what_rule - 0;
    mu_e.value((r % 4) + 1);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_elt_t mu_e;
    mu_e.value((r % 4) + 1);
    r = r / 4;
mu_Delete ( mu_s, mu_e );
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
    static mu_1_elt_t mu_e;
    mu_e.value((r % 4) + 1);
    r = r / 4;
    return tsprintf("Insert elt, e:%s", mu_e.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_elt_t mu_e;
    mu_e.value((r % 4) + 1);
    r = r / 4;
bool mu__boolexpr6;
  if (!((mu_s.mu_n) < (11))) mu__boolexpr6 = FALSE ;
  else {
bool mu__quant7; 
mu__quant7 = FALSE;
{
for(int mu_i = 0; mu_i <= 11; mu_i++) {
if ( ((mu_s.mu_a[mu_i]) == (mu_e)) )
  { mu__quant7 = TRUE; break; }
};
};
  mu__boolexpr6 = (!(mu__quant7)) ; 
}
  return mu__boolexpr6;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 4;
    static mu_1_elt_t mu_e;
    mu_e.value((r % 4) + 1);
    r = r / 4;
    while (what_rule < 8 )
      {
        if ( ( TRUE  ) ) {
bool mu__boolexpr8;
  if (!((mu_s.mu_n) < (11))) mu__boolexpr8 = FALSE ;
  else {
bool mu__quant9; 
mu__quant9 = FALSE;
{
for(int mu_i = 0; mu_i <= 11; mu_i++) {
if ( ((mu_s.mu_a[mu_i]) == (mu_e)) )
  { mu__quant9 = TRUE; break; }
};
};
  mu__boolexpr8 = (!(mu__quant9)) ; 
}
              if (mu__boolexpr8) {
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
    r = what_rule - 4;
    mu_e.value((r % 4) + 1);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_elt_t mu_e;
    mu_e.value((r % 4) + 1);
    r = r / 4;
mu_Insert ( mu_s, mu_e );
  };

  bool UnFair()
  { return FALSE; }
};
class NextStateGenerator
{
  RuleBase0 R0;
  RuleBase1 R1;
public:
void SetNextEnabledRule(unsigned & what_rule)
{
  category = CONDITION;
  if (what_rule<4)
    { R0.NextRule(what_rule);
      if (what_rule<4) return; }
  if (what_rule>=4 && what_rule<8)
    { R1.NextRule(what_rule);
      if (what_rule<8) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=3) return R0.Condition(r-0);
  if (r>=4 && r<=7) return R1.Condition(r-4);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
}
void Code(unsigned r)
{
  if (r<=3) { R0.Code(r-0); return; } 
  if (r>=4 && r<=7) { R1.Code(r-4); return; } 
}
int Priority(unsigned short r)
{
  if (r<=3) { return R0.Priority(); } 
  if (r>=4 && r<=7) { return R1.Priority(); } 
}
char * Name(unsigned r)
{
  if (r<=3) return R0.Name(r-0);
  if (r>=4 && r<=7) return R1.Name(r-4);
  return NULL;
}
};
const unsigned numrules = 8;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 8


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
mu_s.mu_n = 0;
{
for(int mu_i = 0; mu_i <= 11; mu_i++) {
mu_s.mu_a[mu_i] = 0;
};
};
mu_s.mu_numIns = 0;
mu_s.mu_numDel = 0;
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
int mu__invariant_10() // Invariant "Invariant 0"
{
return ((mu_s.mu_numIns) + (mu_s.mu_numDel)) < (5);
};

bool mu__condition_11() // Condition for Rule "Invariant 0"
{
  return mu__invariant_10( );
}

/**** end rule declaration ****/

const rulerec invariants[] = {
{"Invariant 0", &mu__condition_11, NULL, FALSE},
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
s:NoScalarset
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
        mu_s.MultisetSort();
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
void mu_1_elt_t::Permute(PermSet& Perm, int i) {};
void mu_1_elt_t::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_elt_t::Canonicalize(PermSet& Perm) {};
void mu_1_elt_t::SimpleLimit(PermSet& Perm) {};
void mu_1_elt_t::ArrayLimit(PermSet& Perm) {};
void mu_1_elt_t::Limit(PermSet& Perm) {};
void mu_1_elt_t::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_entry_t::Permute(PermSet& Perm, int i) {};
void mu_1_entry_t::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_entry_t::Canonicalize(PermSet& Perm) {};
void mu_1_entry_t::SimpleLimit(PermSet& Perm) {};
void mu_1_entry_t::ArrayLimit(PermSet& Perm) {};
void mu_1_entry_t::Limit(PermSet& Perm) {};
void mu_1_entry_t::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_setInd_t::Permute(PermSet& Perm, int i) {};
void mu_1_setInd_t::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_setInd_t::Canonicalize(PermSet& Perm) {};
void mu_1_setInd_t::SimpleLimit(PermSet& Perm) {};
void mu_1_setInd_t::ArrayLimit(PermSet& Perm) {};
void mu_1_setInd_t::Limit(PermSet& Perm) {};
void mu_1_setInd_t::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_0::Permute(PermSet& Perm, int i)
{
  static mu_1__type_0 temp("Permute_mu_1__type_0",-1);
  int j;
  for (j=0; j<12; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_0::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_0::Canonicalize(PermSet& Perm){};
void mu_1__type_0::SimpleLimit(PermSet& Perm){}
void mu_1__type_0::ArrayLimit(PermSet& Perm) {}
void mu_1__type_0::Limit(PermSet& Perm){}
void mu_1__type_0::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_1::Permute(PermSet& Perm, int i) {};
void mu_1__type_1::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_1::Canonicalize(PermSet& Perm) {};
void mu_1__type_1::SimpleLimit(PermSet& Perm) {};
void mu_1__type_1::ArrayLimit(PermSet& Perm) {};
void mu_1__type_1::Limit(PermSet& Perm) {};
void mu_1__type_1::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_2::Permute(PermSet& Perm, int i) {};
void mu_1__type_2::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_2::Canonicalize(PermSet& Perm) {};
void mu_1__type_2::SimpleLimit(PermSet& Perm) {};
void mu_1__type_2::ArrayLimit(PermSet& Perm) {};
void mu_1__type_2::Limit(PermSet& Perm) {};
void mu_1__type_2::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_3::Permute(PermSet& Perm, int i) {};
void mu_1__type_3::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_3::Canonicalize(PermSet& Perm) {};
void mu_1__type_3::SimpleLimit(PermSet& Perm) {};
void mu_1__type_3::ArrayLimit(PermSet& Perm) {};
void mu_1__type_3::Limit(PermSet& Perm) {};
void mu_1__type_3::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_set_t::Permute(PermSet& Perm, int i)
{
};
void mu_1_set_t::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1_set_t::Canonicalize(PermSet& Perm)
{
};
void mu_1_set_t::SimpleLimit(PermSet& Perm){}
void mu_1_set_t::ArrayLimit(PermSet& Perm){}
void mu_1_set_t::Limit(PermSet& Perm)
{
};
void mu_1_set_t::MultisetLimit(PermSet& Perm)
{
};
void mu__subrange_10::Permute(PermSet& Perm, int i) {};
void mu__subrange_10::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_10::Canonicalize(PermSet& Perm) {};
void mu__subrange_10::SimpleLimit(PermSet& Perm) {};
void mu__subrange_10::ArrayLimit(PermSet& Perm) {};
void mu__subrange_10::Limit(PermSet& Perm) {};
void mu__subrange_10::MultisetLimit(PermSet& Perm)
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
              
              mu_s.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_s.MultisetSort();
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

          mu_s.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_s.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_s.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_s.MultisetSort();
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
      mu_s.MultisetSort();
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
        mu_s.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_s.MultisetSort();
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
