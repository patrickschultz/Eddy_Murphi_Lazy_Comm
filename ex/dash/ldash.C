/******************************
  Program "ldash.m" compiled by "Eddy_Murphi Release 3.2.4"

  Murphi Last Modefied Date: "June 19 2009"
  Murphi Last Compiled date: "Mar 13 2010"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Eddy_Murphi Release 3.2.4"
#define MURPHI_DATE "June 19 2009"
#define PROTOCOL_NAME "ldash"
#define BITS_IN_WORLD 1130
#define HASHC
#define PARALLEL

/********************
  Include
 ********************/
#include "mu_prolog.inc"

/********************
  Decl declaration
 ********************/

class mu_1_Home: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Home& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Home& val)
    {
      if (val.defined())
        return ( s << mu_1_Home::values[ int(val) - 1 ] );
      else
        return ( s << "Undefined" );
    };

  mu_1_Home (char *name, int os): mu__byte(1, 1, 1, name, os) {};
  mu_1_Home (void): mu__byte(1, 1, 1) {};
  mu_1_Home (int val): mu__byte(1, 1, 1, "Parameter or function result.", 0)
    { operator=(val); };
  char * Name() { return values[ value() -1]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 1] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_Home& a, mu_1_Home& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
};
char *mu_1_Home::values[] =
  { "Home_1",NULL };

/*** end scalarset declaration ***/
mu_1_Home mu_1_Home_undefined_var;

class mu_1_Remote: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Remote& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Remote& val)
    {
      if (val.defined())
        return ( s << mu_1_Remote::values[ int(val) - 2 ] );
      else
        return ( s << "Undefined" );
    };

  mu_1_Remote (char *name, int os): mu__byte(2, 5, 3, name, os) {};
  mu_1_Remote (void): mu__byte(2, 5, 3) {};
  mu_1_Remote (int val): mu__byte(2, 5, 3, "Parameter or function result.", 0)
    { operator=(val); };
  char * Name() { return values[ value() -2]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 2] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_Remote& a, mu_1_Remote& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
};
char *mu_1_Remote::values[] =
  { "Remote_1","Remote_2","Remote_3","Remote_4",NULL };

/*** end scalarset declaration ***/
mu_1_Remote mu_1_Remote_undefined_var;

class mu_1_Proc: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Proc& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Proc& val)
    {
      if (val.defined())
        return ( s << mu_1_Proc::values[ val.indexvalue() ] );
      else
        return ( s << "Undefined" );
    };

  // note thate lb and ub are not used if we have byte compacted state.
  mu_1_Proc (char *name, int os): mu__byte(0, 4, 3, name, os) {};
  mu_1_Proc (void): mu__byte(0, 4, 3) {};
  mu_1_Proc (int val): mu__byte(0, 4, 3, "Parameter or function result.", 0)
    { operator=(val); };
  int value() const
  {
    int val = mu__byte::value();
    // val == -1 if value undefined
    // we can return it since no enum/scalarsetid will have value -1
    if (val == -1) return -1;
    if (val <= 0) return val+1;
    if (val <= 4) return val+1;
  }
  inline int value(int val)
  {
    if (val == -1) { undefine(); return -1; }
    if ((val >= 1) && (val <= 1)) return (mu__byte::value(val-1)+1);
    if ((val >= 2) && (val <= 5)) return (mu__byte::value(val-1)+1);
  }
  inline int indexvalue() const
  {
    return mu__byte::value();
  };
  inline int unionassign(int val)
  {
    return mu__byte::value(val);
  };
  char * Name() { return values[ indexvalue() ]; };
friend int CompareWeight(mu_1_Proc& a, mu_1_Proc& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ indexvalue() ] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
};
char *mu_1_Proc::values[] = {"Home_1","Remote_1","Remote_2","Remote_3","Remote_4",NULL };

/*** end union declaration ***/
mu_1_Proc mu_1_Proc_undefined_var;

class mu_1_LAddress: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_LAddress& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_LAddress& val)
    {
      if (val.defined())
        return ( s << mu_1_LAddress::values[ int(val) - 6 ] );
      else
        return ( s << "Undefined" );
    };

  mu_1_LAddress (char *name, int os): mu__byte(6, 6, 1, name, os) {};
  mu_1_LAddress (void): mu__byte(6, 6, 1) {};
  mu_1_LAddress (int val): mu__byte(6, 6, 1, "Parameter or function result.", 0)
    { operator=(val); };
  char * Name() { return values[ value() -6]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 6] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_LAddress& a, mu_1_LAddress& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
};
char *mu_1_LAddress::values[] =
  { "LAddress_1",NULL };

/*** end scalarset declaration ***/
mu_1_LAddress mu_1_LAddress_undefined_var;

class mu_1_Dir_Index: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_Dir_Index& val) { return mu__byte::operator=((int) val); };
  mu_1_Dir_Index (char *name, int os): mu__byte(0, 4, 3, name, os) {};
  mu_1_Dir_Index (void): mu__byte(0, 4, 3) {};
  mu_1_Dir_Index (int val): mu__byte(0, 4, 3, "Parameter or function result.", 0)
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
mu_1_Dir_Index mu_1_Dir_Index_undefined_var;

class mu_1_Request_Type: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Request_Type& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Request_Type& val)
  {
    if (val.defined())
      return ( s << mu_1_Request_Type::values[ int(val) - 7] );
    else return ( s << "Undefined" );
  };

  mu_1_Request_Type (char *name, int os): mu__byte(7, 9, 2, name, os) {};
  mu_1_Request_Type (void): mu__byte(7, 9, 2) {};
  mu_1_Request_Type (int val): mu__byte(7, 9, 2, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -7]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -7] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1_Request_Type::values[] = {"RD_L","GSET","IOWR",NULL };

/*** end of enum declaration ***/
mu_1_Request_Type mu_1_Request_Type_undefined_var;

class mu_1_Reply_Type: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Reply_Type& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Reply_Type& val)
  {
    if (val.defined())
      return ( s << mu_1_Reply_Type::values[ int(val) - 10] );
    else return ( s << "Undefined" );
  };

  mu_1_Reply_Type (char *name, int os): mu__byte(10, 12, 2, name, os) {};
  mu_1_Reply_Type (void): mu__byte(10, 12, 2) {};
  mu_1_Reply_Type (int val): mu__byte(10, 12, 2, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -10]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -10] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1_Reply_Type::values[] = {"ACK_L","LCK","UNLCK",NULL };

/*** end of enum declaration ***/
mu_1_Reply_Type mu_1_Reply_Type_undefined_var;

class mu_1_Request
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1_Request_Type mu_Mtype;
  mu_1_Proc mu_Aux;
  mu_1_LAddress mu_LAddr;
  mu_1_Request ( char *n, int os ) { set_self(n,os); };
  mu_1_Request ( void ) {};

  virtual ~mu_1_Request(); 
friend int CompareWeight(mu_1_Request& a, mu_1_Request& b)
  {
    int w;
    w = CompareWeight(a.mu_Mtype, b.mu_Mtype);
    if (w!=0) return w;
    w = CompareWeight(a.mu_Aux, b.mu_Aux);
    if (w!=0) return w;
    w = CompareWeight(a.mu_LAddr, b.mu_LAddr);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_Request& a, mu_1_Request& b)
  {
    int w;
    w = Compare(a.mu_Mtype, b.mu_Mtype);
    if (w!=0) return w;
    w = Compare(a.mu_Aux, b.mu_Aux);
    if (w!=0) return w;
    w = Compare(a.mu_LAddr, b.mu_LAddr);
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
    mu_Mtype.MultisetSort();
    mu_Aux.MultisetSort();
    mu_LAddr.MultisetSort();
  }
  void print_statistic()
  {
    mu_Mtype.print_statistic();
    mu_Aux.print_statistic();
    mu_LAddr.print_statistic();
  }
  void clear() {
    mu_Mtype.clear();
    mu_Aux.clear();
    mu_LAddr.clear();
 };
  void undefine() {
    mu_Mtype.undefine();
    mu_Aux.undefine();
    mu_LAddr.undefine();
 };
  void reset() {
    mu_Mtype.reset();
    mu_Aux.reset();
    mu_LAddr.reset();
 };
  void print() {
    mu_Mtype.print();
    mu_Aux.print();
    mu_LAddr.print();
  };
  void print_diff(state *prevstate) {
    mu_Mtype.print_diff(prevstate);
    mu_Aux.print_diff(prevstate);
    mu_LAddr.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_Mtype.to_state(thestate);
    mu_Aux.to_state(thestate);
    mu_LAddr.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_Request& operator= (const mu_1_Request& from) {
    mu_Mtype.value(from.mu_Mtype.value());
    mu_Aux.value(from.mu_Aux.value());
    mu_LAddr.value(from.mu_LAddr.value());
    return *this;
  };
};

  void mu_1_Request::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_Request::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_Request::set_self(char *n, int os)
{
  name = n;
  mu_Mtype.set_self_2(name, ".Mtype", os + 0 );
  mu_Aux.set_self_2(name, ".Aux", os + 2 );
  mu_LAddr.set_self_2(name, ".LAddr", os + 5 );
}

mu_1_Request::~mu_1_Request()
{
}

/*** end record declaration ***/
mu_1_Request mu_1_Request_undefined_var;

class mu_1_Reply
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1_Reply_Type mu_Mtype;
  mu_1_Proc mu_Aux;
  mu_1_LAddress mu_LAddr;
  mu_1_Reply ( char *n, int os ) { set_self(n,os); };
  mu_1_Reply ( void ) {};

  virtual ~mu_1_Reply(); 
friend int CompareWeight(mu_1_Reply& a, mu_1_Reply& b)
  {
    int w;
    w = CompareWeight(a.mu_Mtype, b.mu_Mtype);
    if (w!=0) return w;
    w = CompareWeight(a.mu_Aux, b.mu_Aux);
    if (w!=0) return w;
    w = CompareWeight(a.mu_LAddr, b.mu_LAddr);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_Reply& a, mu_1_Reply& b)
  {
    int w;
    w = Compare(a.mu_Mtype, b.mu_Mtype);
    if (w!=0) return w;
    w = Compare(a.mu_Aux, b.mu_Aux);
    if (w!=0) return w;
    w = Compare(a.mu_LAddr, b.mu_LAddr);
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
    mu_Mtype.MultisetSort();
    mu_Aux.MultisetSort();
    mu_LAddr.MultisetSort();
  }
  void print_statistic()
  {
    mu_Mtype.print_statistic();
    mu_Aux.print_statistic();
    mu_LAddr.print_statistic();
  }
  void clear() {
    mu_Mtype.clear();
    mu_Aux.clear();
    mu_LAddr.clear();
 };
  void undefine() {
    mu_Mtype.undefine();
    mu_Aux.undefine();
    mu_LAddr.undefine();
 };
  void reset() {
    mu_Mtype.reset();
    mu_Aux.reset();
    mu_LAddr.reset();
 };
  void print() {
    mu_Mtype.print();
    mu_Aux.print();
    mu_LAddr.print();
  };
  void print_diff(state *prevstate) {
    mu_Mtype.print_diff(prevstate);
    mu_Aux.print_diff(prevstate);
    mu_LAddr.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_Mtype.to_state(thestate);
    mu_Aux.to_state(thestate);
    mu_LAddr.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_Reply& operator= (const mu_1_Reply& from) {
    mu_Mtype.value(from.mu_Mtype.value());
    mu_Aux.value(from.mu_Aux.value());
    mu_LAddr.value(from.mu_LAddr.value());
    return *this;
  };
};

  void mu_1_Reply::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_Reply::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_Reply::set_self(char *n, int os)
{
  name = n;
  mu_Mtype.set_self_2(name, ".Mtype", os + 0 );
  mu_Aux.set_self_2(name, ".Aux", os + 2 );
  mu_LAddr.set_self_2(name, ".LAddr", os + 5 );
}

mu_1_Reply::~mu_1_Reply()
{
}

/*** end record declaration ***/
mu_1_Reply mu_1_Reply_undefined_var;

class mu_1_RAC_State: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_RAC_State& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_RAC_State& val)
  {
    if (val.defined())
      return ( s << mu_1_RAC_State::values[ int(val) - 13] );
    else return ( s << "Undefined" );
  };

  mu_1_RAC_State (char *name, int os): mu__byte(13, 19, 3, name, os) {};
  mu_1_RAC_State (void): mu__byte(13, 19, 3) {};
  mu_1_RAC_State (int val): mu__byte(13, 19, 3, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -13]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -13] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1_RAC_State::values[] = {"INVAL","DLCK","DULCK","DGNTS","WLCK","RLCK","WDIRW",NULL };

/*** end of enum declaration ***/
mu_1_RAC_State mu_1_RAC_State_undefined_var;

class mu_1_Cache_State: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Cache_State& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Cache_State& val)
  {
    if (val.defined())
      return ( s << mu_1_Cache_State::values[ int(val) - 20] );
    else return ( s << "Undefined" );
  };

  mu_1_Cache_State (char *name, int os): mu__byte(20, 21, 2, name, os) {};
  mu_1_Cache_State (void): mu__byte(20, 21, 2) {};
  mu_1_Cache_State (int val): mu__byte(20, 21, 2, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -20]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -20] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1_Cache_State::values[] = {"Non_Locally_Cached","Locally_Shared",NULL };

/*** end of enum declaration ***/
mu_1_Cache_State mu_1_Cache_State_undefined_var;

class mu_1__type_0: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_0& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1__type_0& val)
  {
    if (val.defined())
      return ( s << mu_1__type_0::values[ int(val) - 22] );
    else return ( s << "Undefined" );
  };

  mu_1__type_0 (char *name, int os): mu__byte(22, 24, 2, name, os) {};
  mu_1__type_0 (void): mu__byte(22, 24, 2) {};
  mu_1__type_0 (int val): mu__byte(22, 24, 2, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -22]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -22] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1__type_0::values[] = {"Unlocked","Locked","Queued",NULL };

/*** end of enum declaration ***/
mu_1__type_0 mu_1__type_0_undefined_var;

class mu_1__type_1
{
 public:
  mu_1_Proc array[ 5 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_1 (char *n, int os) { set_self(n, os); };
  mu_1__type_1 ( void ) {};
  virtual ~mu_1__type_1 ();
  mu_1_Proc& operator[] (int index) /* const */
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
  mu_1__type_1& operator= (const mu_1__type_1& from)
  {
    for (int i = 0; i < 5; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_1& a, mu_1__type_1& b)
  {
    int w;
    for (int i=0; i<5; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_1& a, mu_1__type_1& b)
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

  void mu_1__type_1::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_1::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_1::set_self( char *n, int os)
{
  char* s;
  name = n;
  for(int i = 0; i < 5; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 3 + os);
    delete[] s;
  }
};
mu_1__type_1::~mu_1__type_1()
{
}
/*** end array declaration ***/
mu_1__type_1 mu_1__type_1_undefined_var;

class mu_1__type_2
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1__type_0 mu_State;
  mu_1_Dir_Index mu_QueuedCount;
  mu_1__type_1 mu_Entries;
  mu_1__type_2 ( char *n, int os ) { set_self(n,os); };
  mu_1__type_2 ( void ) {};

  virtual ~mu_1__type_2(); 
friend int CompareWeight(mu_1__type_2& a, mu_1__type_2& b)
  {
    int w;
    w = CompareWeight(a.mu_State, b.mu_State);
    if (w!=0) return w;
    w = CompareWeight(a.mu_QueuedCount, b.mu_QueuedCount);
    if (w!=0) return w;
    w = CompareWeight(a.mu_Entries, b.mu_Entries);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1__type_2& a, mu_1__type_2& b)
  {
    int w;
    w = Compare(a.mu_State, b.mu_State);
    if (w!=0) return w;
    w = Compare(a.mu_QueuedCount, b.mu_QueuedCount);
    if (w!=0) return w;
    w = Compare(a.mu_Entries, b.mu_Entries);
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
    mu_State.MultisetSort();
    mu_QueuedCount.MultisetSort();
    mu_Entries.MultisetSort();
  }
  void print_statistic()
  {
    mu_State.print_statistic();
    mu_QueuedCount.print_statistic();
    mu_Entries.print_statistic();
  }
  void clear() {
    mu_State.clear();
    mu_QueuedCount.clear();
    mu_Entries.clear();
 };
  void undefine() {
    mu_State.undefine();
    mu_QueuedCount.undefine();
    mu_Entries.undefine();
 };
  void reset() {
    mu_State.reset();
    mu_QueuedCount.reset();
    mu_Entries.reset();
 };
  void print() {
    mu_State.print();
    mu_QueuedCount.print();
    mu_Entries.print();
  };
  void print_diff(state *prevstate) {
    mu_State.print_diff(prevstate);
    mu_QueuedCount.print_diff(prevstate);
    mu_Entries.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_State.to_state(thestate);
    mu_QueuedCount.to_state(thestate);
    mu_Entries.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1__type_2& operator= (const mu_1__type_2& from) {
    mu_State.value(from.mu_State.value());
    mu_QueuedCount.value(from.mu_QueuedCount.value());
    mu_Entries = from.mu_Entries;
    return *this;
  };
};

  void mu_1__type_2::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_2::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_2::set_self(char *n, int os)
{
  name = n;
  mu_State.set_self_2(name, ".State", os + 0 );
  mu_QueuedCount.set_self_2(name, ".QueuedCount", os + 2 );
  mu_Entries.set_self_2(name, ".Entries", os + 5 );
}

mu_1__type_2::~mu_1__type_2()
{
}

/*** end record declaration ***/
mu_1__type_2 mu_1__type_2_undefined_var;

class mu_1__type_3
{
 public:
  mu_1__type_2 array[ 1 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_3 (char *n, int os) { set_self(n, os); };
  mu_1__type_3 ( void ) {};
  virtual ~mu_1__type_3 ();
  mu_1__type_2& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 6 ) && ( index <= 6 ) )
      return array[ index - 6 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: LAddress is internally represented from 6 to 6.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 6 ];
#endif
  };
  mu_1__type_3& operator= (const mu_1__type_3& from)
  {
      array[0] = from.array[0];
    return *this;
  }

friend int CompareWeight(mu_1__type_3& a, mu_1__type_3& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_3& a, mu_1__type_3& b)
  {
    int w;
    for (int i=0; i<1; i++) {
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
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 1; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_3::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_3::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_3::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"LAddress_1", i * 20 + os);i++;
}
mu_1__type_3::~mu_1__type_3()
{
}
/*** end array declaration ***/
mu_1__type_3 mu_1__type_3_undefined_var;

class mu_1_HomeState
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1__type_3 mu_LDir;
  mu_1_HomeState ( char *n, int os ) { set_self(n,os); };
  mu_1_HomeState ( void ) {};

  virtual ~mu_1_HomeState(); 
friend int CompareWeight(mu_1_HomeState& a, mu_1_HomeState& b)
  {
    int w;
    w = CompareWeight(a.mu_LDir, b.mu_LDir);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_HomeState& a, mu_1_HomeState& b)
  {
    int w;
    w = Compare(a.mu_LDir, b.mu_LDir);
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
    mu_LDir.MultisetSort();
  }
  void print_statistic()
  {
    mu_LDir.print_statistic();
  }
  void clear() {
    mu_LDir.clear();
 };
  void undefine() {
    mu_LDir.undefine();
 };
  void reset() {
    mu_LDir.reset();
 };
  void print() {
    mu_LDir.print();
  };
  void print_diff(state *prevstate) {
    mu_LDir.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_LDir.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_HomeState& operator= (const mu_1_HomeState& from) {
    mu_LDir = from.mu_LDir;
    return *this;
  };
};

  void mu_1_HomeState::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_HomeState::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_HomeState::set_self(char *n, int os)
{
  name = n;
  mu_LDir.set_self_2(name, ".LDir", os + 0 );
}

mu_1_HomeState::~mu_1_HomeState()
{
}

/*** end record declaration ***/
mu_1_HomeState mu_1_HomeState_undefined_var;

class mu_1__type_4
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1_Cache_State mu_State;
  mu_1__type_4 ( char *n, int os ) { set_self(n,os); };
  mu_1__type_4 ( void ) {};

  virtual ~mu_1__type_4(); 
friend int CompareWeight(mu_1__type_4& a, mu_1__type_4& b)
  {
    int w;
    w = CompareWeight(a.mu_State, b.mu_State);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1__type_4& a, mu_1__type_4& b)
  {
    int w;
    w = Compare(a.mu_State, b.mu_State);
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
    mu_State.MultisetSort();
  }
  void print_statistic()
  {
    mu_State.print_statistic();
  }
  void clear() {
    mu_State.clear();
 };
  void undefine() {
    mu_State.undefine();
 };
  void reset() {
    mu_State.reset();
 };
  void print() {
    mu_State.print();
  };
  void print_diff(state *prevstate) {
    mu_State.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_State.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1__type_4& operator= (const mu_1__type_4& from) {
    mu_State.value(from.mu_State.value());
    return *this;
  };
};

  void mu_1__type_4::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_4::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_4::set_self(char *n, int os)
{
  name = n;
  mu_State.set_self_2(name, ".State", os + 0 );
}

mu_1__type_4::~mu_1__type_4()
{
}

/*** end record declaration ***/
mu_1__type_4 mu_1__type_4_undefined_var;

class mu_1__type_5
{
 public:
  mu_1__type_4 array[ 1 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_5 (char *n, int os) { set_self(n, os); };
  mu_1__type_5 ( void ) {};
  virtual ~mu_1__type_5 ();
  mu_1__type_4& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 6 ) && ( index <= 6 ) )
      return array[ index - 6 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: LAddress is internally represented from 6 to 6.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 6 ];
#endif
  };
  mu_1__type_5& operator= (const mu_1__type_5& from)
  {
      array[0] = from.array[0];
    return *this;
  }

friend int CompareWeight(mu_1__type_5& a, mu_1__type_5& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_5& a, mu_1__type_5& b)
  {
    int w;
    for (int i=0; i<1; i++) {
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
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 1; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_5::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_5::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_5::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"LAddress_1", i * 2 + os);i++;
}
mu_1__type_5::~mu_1__type_5()
{
}
/*** end array declaration ***/
mu_1__type_5 mu_1__type_5_undefined_var;

class mu_1__type_6
{
 public:
  mu_1__type_5 array[ 1 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_6 (char *n, int os) { set_self(n, os); };
  mu_1__type_6 ( void ) {};
  virtual ~mu_1__type_6 ();
  mu_1__type_5& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 1 ) )
      return array[ index - 1 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: Home is internally represented from 1 to 1.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_6& operator= (const mu_1__type_6& from)
  {
      array[0] = from.array[0];
    return *this;
  }

friend int CompareWeight(mu_1__type_6& a, mu_1__type_6& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_6& a, mu_1__type_6& b)
  {
    int w;
    for (int i=0; i<1; i++) {
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
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 1; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_6::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_6::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_6::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"Home_1", i * 2 + os);i++;
}
mu_1__type_6::~mu_1__type_6()
{
}
/*** end array declaration ***/
mu_1__type_6 mu_1__type_6_undefined_var;

class mu_1__type_7
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1_RAC_State mu_State;
  mu_1_Proc mu_Granting;
  mu_1__type_7 ( char *n, int os ) { set_self(n,os); };
  mu_1__type_7 ( void ) {};

  virtual ~mu_1__type_7(); 
friend int CompareWeight(mu_1__type_7& a, mu_1__type_7& b)
  {
    int w;
    w = CompareWeight(a.mu_State, b.mu_State);
    if (w!=0) return w;
    w = CompareWeight(a.mu_Granting, b.mu_Granting);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1__type_7& a, mu_1__type_7& b)
  {
    int w;
    w = Compare(a.mu_State, b.mu_State);
    if (w!=0) return w;
    w = Compare(a.mu_Granting, b.mu_Granting);
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
    mu_State.MultisetSort();
    mu_Granting.MultisetSort();
  }
  void print_statistic()
  {
    mu_State.print_statistic();
    mu_Granting.print_statistic();
  }
  void clear() {
    mu_State.clear();
    mu_Granting.clear();
 };
  void undefine() {
    mu_State.undefine();
    mu_Granting.undefine();
 };
  void reset() {
    mu_State.reset();
    mu_Granting.reset();
 };
  void print() {
    mu_State.print();
    mu_Granting.print();
  };
  void print_diff(state *prevstate) {
    mu_State.print_diff(prevstate);
    mu_Granting.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_State.to_state(thestate);
    mu_Granting.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1__type_7& operator= (const mu_1__type_7& from) {
    mu_State.value(from.mu_State.value());
    mu_Granting.value(from.mu_Granting.value());
    return *this;
  };
};

  void mu_1__type_7::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_7::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_7::set_self(char *n, int os)
{
  name = n;
  mu_State.set_self_2(name, ".State", os + 0 );
  mu_Granting.set_self_2(name, ".Granting", os + 3 );
}

mu_1__type_7::~mu_1__type_7()
{
}

/*** end record declaration ***/
mu_1__type_7 mu_1__type_7_undefined_var;

class mu_1__type_8
{
 public:
  mu_1__type_7 array[ 1 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_8 (char *n, int os) { set_self(n, os); };
  mu_1__type_8 ( void ) {};
  virtual ~mu_1__type_8 ();
  mu_1__type_7& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 6 ) && ( index <= 6 ) )
      return array[ index - 6 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: LAddress is internally represented from 6 to 6.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 6 ];
#endif
  };
  mu_1__type_8& operator= (const mu_1__type_8& from)
  {
      array[0] = from.array[0];
    return *this;
  }

friend int CompareWeight(mu_1__type_8& a, mu_1__type_8& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_8& a, mu_1__type_8& b)
  {
    int w;
    for (int i=0; i<1; i++) {
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
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 1; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_8::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_8::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_8::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"LAddress_1", i * 6 + os);i++;
}
mu_1__type_8::~mu_1__type_8()
{
}
/*** end array declaration ***/
mu_1__type_8 mu_1__type_8_undefined_var;

class mu_1__type_9
{
 public:
  mu_1__type_8 array[ 1 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_9 (char *n, int os) { set_self(n, os); };
  mu_1__type_9 ( void ) {};
  virtual ~mu_1__type_9 ();
  mu_1__type_8& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 1 ) )
      return array[ index - 1 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: Home is internally represented from 1 to 1.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_9& operator= (const mu_1__type_9& from)
  {
      array[0] = from.array[0];
    return *this;
  }

friend int CompareWeight(mu_1__type_9& a, mu_1__type_9& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_9& a, mu_1__type_9& b)
  {
    int w;
    for (int i=0; i<1; i++) {
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
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 1; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_9::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_9::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_9::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"Home_1", i * 6 + os);i++;
}
mu_1__type_9::~mu_1__type_9()
{
}
/*** end array declaration ***/
mu_1__type_9 mu_1__type_9_undefined_var;

class mu_1__type_10
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1_RAC_State mu_State;
  mu_1__type_10 ( char *n, int os ) { set_self(n,os); };
  mu_1__type_10 ( void ) {};

  virtual ~mu_1__type_10(); 
friend int CompareWeight(mu_1__type_10& a, mu_1__type_10& b)
  {
    int w;
    w = CompareWeight(a.mu_State, b.mu_State);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1__type_10& a, mu_1__type_10& b)
  {
    int w;
    w = Compare(a.mu_State, b.mu_State);
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
    mu_State.MultisetSort();
  }
  void print_statistic()
  {
    mu_State.print_statistic();
  }
  void clear() {
    mu_State.clear();
 };
  void undefine() {
    mu_State.undefine();
 };
  void reset() {
    mu_State.reset();
 };
  void print() {
    mu_State.print();
  };
  void print_diff(state *prevstate) {
    mu_State.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_State.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1__type_10& operator= (const mu_1__type_10& from) {
    mu_State.value(from.mu_State.value());
    return *this;
  };
};

  void mu_1__type_10::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_10::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_10::set_self(char *n, int os)
{
  name = n;
  mu_State.set_self_2(name, ".State", os + 0 );
}

mu_1__type_10::~mu_1__type_10()
{
}

/*** end record declaration ***/
mu_1__type_10 mu_1__type_10_undefined_var;

class mu_1__type_11
{
 public:
  mu_1__type_10 array[ 1 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_11 (char *n, int os) { set_self(n, os); };
  mu_1__type_11 ( void ) {};
  virtual ~mu_1__type_11 ();
  mu_1__type_10& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 6 ) && ( index <= 6 ) )
      return array[ index - 6 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: LAddress is internally represented from 6 to 6.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 6 ];
#endif
  };
  mu_1__type_11& operator= (const mu_1__type_11& from)
  {
      array[0] = from.array[0];
    return *this;
  }

friend int CompareWeight(mu_1__type_11& a, mu_1__type_11& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_11& a, mu_1__type_11& b)
  {
    int w;
    for (int i=0; i<1; i++) {
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
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 1; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_11::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_11::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_11::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"LAddress_1", i * 3 + os);i++;
}
mu_1__type_11::~mu_1__type_11()
{
}
/*** end array declaration ***/
mu_1__type_11 mu_1__type_11_undefined_var;

class mu_1__type_12
{
 public:
  mu_1__type_11 array[ 1 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_12 (char *n, int os) { set_self(n, os); };
  mu_1__type_12 ( void ) {};
  virtual ~mu_1__type_12 ();
  mu_1__type_11& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 1 ) )
      return array[ index - 1 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: Home is internally represented from 1 to 1.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_12& operator= (const mu_1__type_12& from)
  {
      array[0] = from.array[0];
    return *this;
  }

friend int CompareWeight(mu_1__type_12& a, mu_1__type_12& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_12& a, mu_1__type_12& b)
  {
    int w;
    for (int i=0; i<1; i++) {
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
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 1; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_12::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_12::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_12::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"Home_1", i * 3 + os);i++;
}
mu_1__type_12::~mu_1__type_12()
{
}
/*** end array declaration ***/
mu_1__type_12 mu_1__type_12_undefined_var;

class mu_1_ProcState
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1__type_6 mu_LCache;
  mu_1__type_9 mu_LRAC;
  mu_1__type_12 mu_ULRAC;
  mu_1_ProcState ( char *n, int os ) { set_self(n,os); };
  mu_1_ProcState ( void ) {};

  virtual ~mu_1_ProcState(); 
friend int CompareWeight(mu_1_ProcState& a, mu_1_ProcState& b)
  {
    int w;
    w = CompareWeight(a.mu_LCache, b.mu_LCache);
    if (w!=0) return w;
    w = CompareWeight(a.mu_LRAC, b.mu_LRAC);
    if (w!=0) return w;
    w = CompareWeight(a.mu_ULRAC, b.mu_ULRAC);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_ProcState& a, mu_1_ProcState& b)
  {
    int w;
    w = Compare(a.mu_LCache, b.mu_LCache);
    if (w!=0) return w;
    w = Compare(a.mu_LRAC, b.mu_LRAC);
    if (w!=0) return w;
    w = Compare(a.mu_ULRAC, b.mu_ULRAC);
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
    mu_LCache.MultisetSort();
    mu_LRAC.MultisetSort();
    mu_ULRAC.MultisetSort();
  }
  void print_statistic()
  {
    mu_LCache.print_statistic();
    mu_LRAC.print_statistic();
    mu_ULRAC.print_statistic();
  }
  void clear() {
    mu_LCache.clear();
    mu_LRAC.clear();
    mu_ULRAC.clear();
 };
  void undefine() {
    mu_LCache.undefine();
    mu_LRAC.undefine();
    mu_ULRAC.undefine();
 };
  void reset() {
    mu_LCache.reset();
    mu_LRAC.reset();
    mu_ULRAC.reset();
 };
  void print() {
    mu_LCache.print();
    mu_LRAC.print();
    mu_ULRAC.print();
  };
  void print_diff(state *prevstate) {
    mu_LCache.print_diff(prevstate);
    mu_LRAC.print_diff(prevstate);
    mu_ULRAC.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_LCache.to_state(thestate);
    mu_LRAC.to_state(thestate);
    mu_ULRAC.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_ProcState& operator= (const mu_1_ProcState& from) {
    mu_LCache = from.mu_LCache;
    mu_LRAC = from.mu_LRAC;
    mu_ULRAC = from.mu_ULRAC;
    return *this;
  };
};

  void mu_1_ProcState::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_ProcState::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_ProcState::set_self(char *n, int os)
{
  name = n;
  mu_LCache.set_self_2(name, ".LCache", os + 0 );
  mu_LRAC.set_self_2(name, ".LRAC", os + 2 );
  mu_ULRAC.set_self_2(name, ".ULRAC", os + 8 );
}

mu_1_ProcState::~mu_1_ProcState()
{
}

/*** end record declaration ***/
mu_1_ProcState mu_1_ProcState_undefined_var;

class mu_1__type_13: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_13& val) { return mu__byte::operator=((int) val); };
  mu_1__type_13 (char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1__type_13 (void): mu__byte(0, 3, 3) {};
  mu_1__type_13 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu_1__type_13 mu_1__type_13_undefined_var;

class mu__subrange_29: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_29& val) { return mu__byte::operator=((int) val); };
  mu__subrange_29 (char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_29 (void): mu__byte(0, 2, 2) {};
  mu__subrange_29 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_29 mu__subrange_29_undefined_var;

class mu_1__type_14
{
 public:
  mu_1_Request array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_14 (char *n, int os) { set_self(n, os); };
  mu_1__type_14 ( void ) {};
  virtual ~mu_1__type_14 ();
  mu_1_Request& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 2 ) )
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
  mu_1__type_14& operator= (const mu_1__type_14& from)
  {
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_14& a, mu_1__type_14& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_14& a, mu_1__type_14& b)
  {
    int w;
    for (int i=0; i<3; i++) {
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
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_14::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_14::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_14::set_self( char *n, int os)
{
  char* s;
  name = n;
  for(int i = 0; i < 3; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 6 + os);
    delete[] s;
  }
};
mu_1__type_14::~mu_1__type_14()
{
}
/*** end array declaration ***/
mu_1__type_14 mu_1__type_14_undefined_var;

class mu_1__type_15
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1__type_13 mu_Count;
  mu_1__type_14 mu_Messages;
  mu_1__type_15 ( char *n, int os ) { set_self(n,os); };
  mu_1__type_15 ( void ) {};

  virtual ~mu_1__type_15(); 
friend int CompareWeight(mu_1__type_15& a, mu_1__type_15& b)
  {
    int w;
    w = CompareWeight(a.mu_Count, b.mu_Count);
    if (w!=0) return w;
    w = CompareWeight(a.mu_Messages, b.mu_Messages);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1__type_15& a, mu_1__type_15& b)
  {
    int w;
    w = Compare(a.mu_Count, b.mu_Count);
    if (w!=0) return w;
    w = Compare(a.mu_Messages, b.mu_Messages);
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
    mu_Count.MultisetSort();
    mu_Messages.MultisetSort();
  }
  void print_statistic()
  {
    mu_Count.print_statistic();
    mu_Messages.print_statistic();
  }
  void clear() {
    mu_Count.clear();
    mu_Messages.clear();
 };
  void undefine() {
    mu_Count.undefine();
    mu_Messages.undefine();
 };
  void reset() {
    mu_Count.reset();
    mu_Messages.reset();
 };
  void print() {
    mu_Count.print();
    mu_Messages.print();
  };
  void print_diff(state *prevstate) {
    mu_Count.print_diff(prevstate);
    mu_Messages.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_Count.to_state(thestate);
    mu_Messages.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1__type_15& operator= (const mu_1__type_15& from) {
    mu_Count.value(from.mu_Count.value());
    mu_Messages = from.mu_Messages;
    return *this;
  };
};

  void mu_1__type_15::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_15::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_15::set_self(char *n, int os)
{
  name = n;
  mu_Count.set_self_2(name, ".Count", os + 0 );
  mu_Messages.set_self_2(name, ".Messages", os + 3 );
}

mu_1__type_15::~mu_1__type_15()
{
}

/*** end record declaration ***/
mu_1__type_15 mu_1__type_15_undefined_var;

class mu_1__type_16
{
 public:
  mu_1__type_15 array[ 5 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_16 (char *n, int os) { set_self(n, os); };
  mu_1__type_16 ( void ) {};
  virtual ~mu_1__type_16 ();
  mu_1__type_15& operator[] (int index) /* const */
  {
    if ( ( index >= 1 ) && ( index <= 1 ) )
      return array[ index - (1) ];
    if ( ( index >= 2 ) && ( index <= 5 ) )
      return array[ index - (1) ];
    if (index==UNDEFVAL) 
      Error.Error("Indexing to %s using an undefined value.", name);
    else
      Error.Error("Funny index value %d for %s. (Internal Error in Type Checking.",index, name);
    return array[0];
  }
  mu_1__type_16& operator= (const mu_1__type_16& from)
  {
    for (int i = 0; i < 5; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_16& a, mu_1__type_16& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_16& a, mu_1__type_16& b)
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

  void mu_1__type_16::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_16::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_16::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"Home_1", i * 21 + os);i++;
array[i].set_self_ar(n,"Remote_1", i * 21 + os);i++;
array[i].set_self_ar(n,"Remote_2", i * 21 + os);i++;
array[i].set_self_ar(n,"Remote_3", i * 21 + os);i++;
array[i].set_self_ar(n,"Remote_4", i * 21 + os);i++;
}
mu_1__type_16::~mu_1__type_16()
{
}
/*** end array declaration ***/
mu_1__type_16 mu_1__type_16_undefined_var;

class mu_1__type_17
{
 public:
  mu_1__type_16 array[ 5 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_17 (char *n, int os) { set_self(n, os); };
  mu_1__type_17 ( void ) {};
  virtual ~mu_1__type_17 ();
  mu_1__type_16& operator[] (int index) /* const */
  {
    if ( ( index >= 1 ) && ( index <= 1 ) )
      return array[ index - (1) ];
    if ( ( index >= 2 ) && ( index <= 5 ) )
      return array[ index - (1) ];
    if (index==UNDEFVAL) 
      Error.Error("Indexing to %s using an undefined value.", name);
    else
      Error.Error("Funny index value %d for %s. (Internal Error in Type Checking.",index, name);
    return array[0];
  }
  mu_1__type_17& operator= (const mu_1__type_17& from)
  {
    for (int i = 0; i < 5; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_17& a, mu_1__type_17& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_17& a, mu_1__type_17& b)
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

  void mu_1__type_17::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_17::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_17::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"Home_1", i * 105 + os);i++;
array[i].set_self_ar(n,"Remote_1", i * 105 + os);i++;
array[i].set_self_ar(n,"Remote_2", i * 105 + os);i++;
array[i].set_self_ar(n,"Remote_3", i * 105 + os);i++;
array[i].set_self_ar(n,"Remote_4", i * 105 + os);i++;
}
mu_1__type_17::~mu_1__type_17()
{
}
/*** end array declaration ***/
mu_1__type_17 mu_1__type_17_undefined_var;

class mu_1__type_18: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_18& val) { return mu__byte::operator=((int) val); };
  mu_1__type_18 (char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1__type_18 (void): mu__byte(0, 3, 3) {};
  mu_1__type_18 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
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
mu_1__type_18 mu_1__type_18_undefined_var;

class mu__subrange_35: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_35& val) { return mu__byte::operator=((int) val); };
  mu__subrange_35 (char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_35 (void): mu__byte(0, 2, 2) {};
  mu__subrange_35 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_35 mu__subrange_35_undefined_var;

class mu_1__type_19
{
 public:
  mu_1_Reply array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_19 (char *n, int os) { set_self(n, os); };
  mu_1__type_19 ( void ) {};
  virtual ~mu_1__type_19 ();
  mu_1_Reply& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 2 ) )
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
  mu_1__type_19& operator= (const mu_1__type_19& from)
  {
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_19& a, mu_1__type_19& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_19& a, mu_1__type_19& b)
  {
    int w;
    for (int i=0; i<3; i++) {
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
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_19::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_19::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_19::set_self( char *n, int os)
{
  char* s;
  name = n;
  for(int i = 0; i < 3; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 6 + os);
    delete[] s;
  }
};
mu_1__type_19::~mu_1__type_19()
{
}
/*** end array declaration ***/
mu_1__type_19 mu_1__type_19_undefined_var;

class mu_1__type_20
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1__type_18 mu_Count;
  mu_1__type_19 mu_Messages;
  mu_1__type_20 ( char *n, int os ) { set_self(n,os); };
  mu_1__type_20 ( void ) {};

  virtual ~mu_1__type_20(); 
friend int CompareWeight(mu_1__type_20& a, mu_1__type_20& b)
  {
    int w;
    w = CompareWeight(a.mu_Count, b.mu_Count);
    if (w!=0) return w;
    w = CompareWeight(a.mu_Messages, b.mu_Messages);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1__type_20& a, mu_1__type_20& b)
  {
    int w;
    w = Compare(a.mu_Count, b.mu_Count);
    if (w!=0) return w;
    w = Compare(a.mu_Messages, b.mu_Messages);
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
    mu_Count.MultisetSort();
    mu_Messages.MultisetSort();
  }
  void print_statistic()
  {
    mu_Count.print_statistic();
    mu_Messages.print_statistic();
  }
  void clear() {
    mu_Count.clear();
    mu_Messages.clear();
 };
  void undefine() {
    mu_Count.undefine();
    mu_Messages.undefine();
 };
  void reset() {
    mu_Count.reset();
    mu_Messages.reset();
 };
  void print() {
    mu_Count.print();
    mu_Messages.print();
  };
  void print_diff(state *prevstate) {
    mu_Count.print_diff(prevstate);
    mu_Messages.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_Count.to_state(thestate);
    mu_Messages.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1__type_20& operator= (const mu_1__type_20& from) {
    mu_Count.value(from.mu_Count.value());
    mu_Messages = from.mu_Messages;
    return *this;
  };
};

  void mu_1__type_20::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_20::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_20::set_self(char *n, int os)
{
  name = n;
  mu_Count.set_self_2(name, ".Count", os + 0 );
  mu_Messages.set_self_2(name, ".Messages", os + 3 );
}

mu_1__type_20::~mu_1__type_20()
{
}

/*** end record declaration ***/
mu_1__type_20 mu_1__type_20_undefined_var;

class mu_1__type_21
{
 public:
  mu_1__type_20 array[ 5 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_21 (char *n, int os) { set_self(n, os); };
  mu_1__type_21 ( void ) {};
  virtual ~mu_1__type_21 ();
  mu_1__type_20& operator[] (int index) /* const */
  {
    if ( ( index >= 1 ) && ( index <= 1 ) )
      return array[ index - (1) ];
    if ( ( index >= 2 ) && ( index <= 5 ) )
      return array[ index - (1) ];
    if (index==UNDEFVAL) 
      Error.Error("Indexing to %s using an undefined value.", name);
    else
      Error.Error("Funny index value %d for %s. (Internal Error in Type Checking.",index, name);
    return array[0];
  }
  mu_1__type_21& operator= (const mu_1__type_21& from)
  {
    for (int i = 0; i < 5; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_21& a, mu_1__type_21& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_21& a, mu_1__type_21& b)
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

  void mu_1__type_21::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_21::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_21::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"Home_1", i * 21 + os);i++;
array[i].set_self_ar(n,"Remote_1", i * 21 + os);i++;
array[i].set_self_ar(n,"Remote_2", i * 21 + os);i++;
array[i].set_self_ar(n,"Remote_3", i * 21 + os);i++;
array[i].set_self_ar(n,"Remote_4", i * 21 + os);i++;
}
mu_1__type_21::~mu_1__type_21()
{
}
/*** end array declaration ***/
mu_1__type_21 mu_1__type_21_undefined_var;

class mu_1__type_22
{
 public:
  mu_1__type_21 array[ 5 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_22 (char *n, int os) { set_self(n, os); };
  mu_1__type_22 ( void ) {};
  virtual ~mu_1__type_22 ();
  mu_1__type_21& operator[] (int index) /* const */
  {
    if ( ( index >= 1 ) && ( index <= 1 ) )
      return array[ index - (1) ];
    if ( ( index >= 2 ) && ( index <= 5 ) )
      return array[ index - (1) ];
    if (index==UNDEFVAL) 
      Error.Error("Indexing to %s using an undefined value.", name);
    else
      Error.Error("Funny index value %d for %s. (Internal Error in Type Checking.",index, name);
    return array[0];
  }
  mu_1__type_22& operator= (const mu_1__type_22& from)
  {
    for (int i = 0; i < 5; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_22& a, mu_1__type_22& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_22& a, mu_1__type_22& b)
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

  void mu_1__type_22::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_22::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_22::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"Home_1", i * 105 + os);i++;
array[i].set_self_ar(n,"Remote_1", i * 105 + os);i++;
array[i].set_self_ar(n,"Remote_2", i * 105 + os);i++;
array[i].set_self_ar(n,"Remote_3", i * 105 + os);i++;
array[i].set_self_ar(n,"Remote_4", i * 105 + os);i++;
}
mu_1__type_22::~mu_1__type_22()
{
}
/*** end array declaration ***/
mu_1__type_22 mu_1__type_22_undefined_var;

class mu_1__type_23
{
 public:
  mu_1_ProcState array[ 5 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_23 (char *n, int os) { set_self(n, os); };
  mu_1__type_23 ( void ) {};
  virtual ~mu_1__type_23 ();
  mu_1_ProcState& operator[] (int index) /* const */
  {
    if ( ( index >= 1 ) && ( index <= 1 ) )
      return array[ index - (1) ];
    if ( ( index >= 2 ) && ( index <= 5 ) )
      return array[ index - (1) ];
    if (index==UNDEFVAL) 
      Error.Error("Indexing to %s using an undefined value.", name);
    else
      Error.Error("Funny index value %d for %s. (Internal Error in Type Checking.",index, name);
    return array[0];
  }
  mu_1__type_23& operator= (const mu_1__type_23& from)
  {
    for (int i = 0; i < 5; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_23& a, mu_1__type_23& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_23& a, mu_1__type_23& b)
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

  void mu_1__type_23::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_23::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_23::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"Home_1", i * 11 + os);i++;
array[i].set_self_ar(n,"Remote_1", i * 11 + os);i++;
array[i].set_self_ar(n,"Remote_2", i * 11 + os);i++;
array[i].set_self_ar(n,"Remote_3", i * 11 + os);i++;
array[i].set_self_ar(n,"Remote_4", i * 11 + os);i++;
}
mu_1__type_23::~mu_1__type_23()
{
}
/*** end array declaration ***/
mu_1__type_23 mu_1__type_23_undefined_var;

class mu_1__type_24
{
 public:
  mu_1_HomeState array[ 1 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_24 (char *n, int os) { set_self(n, os); };
  mu_1__type_24 ( void ) {};
  virtual ~mu_1__type_24 ();
  mu_1_HomeState& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 1 ) )
      return array[ index - 1 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: Home is internally represented from 1 to 1.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_24& operator= (const mu_1__type_24& from)
  {
      array[0] = from.array[0];
    return *this;
  }

friend int CompareWeight(mu_1__type_24& a, mu_1__type_24& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_24& a, mu_1__type_24& b)
  {
    int w;
    for (int i=0; i<1; i++) {
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
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 1; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_24::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_24::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_24::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"Home_1", i * 20 + os);i++;
}
mu_1__type_24::~mu_1__type_24()
{
}
/*** end array declaration ***/
mu_1__type_24 mu_1__type_24_undefined_var;

class mu_1__type_25: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_25& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1__type_25& val)
  {
    if (val.defined())
      return ( s << mu_1__type_25::values[ int(val) - 25] );
    else return ( s << "Undefined" );
  };

  mu_1__type_25 (char *name, int os): mu__byte(25, 26, 2, name, os) {};
  mu_1__type_25 (void): mu__byte(25, 26, 2) {};
  mu_1__type_25 (int val): mu__byte(25, 26, 2, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -25]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -25] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1__type_25::values[] = {"Invalid","Valid",NULL };

/*** end of enum declaration ***/
mu_1__type_25 mu_1__type_25_undefined_var;

class mu_1__type_26
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1__type_25 mu_State;
  mu_1_Proc mu_Proc;
  mu_1__type_26 ( char *n, int os ) { set_self(n,os); };
  mu_1__type_26 ( void ) {};

  virtual ~mu_1__type_26(); 
friend int CompareWeight(mu_1__type_26& a, mu_1__type_26& b)
  {
    int w;
    w = CompareWeight(a.mu_State, b.mu_State);
    if (w!=0) return w;
    w = CompareWeight(a.mu_Proc, b.mu_Proc);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1__type_26& a, mu_1__type_26& b)
  {
    int w;
    w = Compare(a.mu_State, b.mu_State);
    if (w!=0) return w;
    w = Compare(a.mu_Proc, b.mu_Proc);
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
    mu_State.MultisetSort();
    mu_Proc.MultisetSort();
  }
  void print_statistic()
  {
    mu_State.print_statistic();
    mu_Proc.print_statistic();
  }
  void clear() {
    mu_State.clear();
    mu_Proc.clear();
 };
  void undefine() {
    mu_State.undefine();
    mu_Proc.undefine();
 };
  void reset() {
    mu_State.reset();
    mu_Proc.reset();
 };
  void print() {
    mu_State.print();
    mu_Proc.print();
  };
  void print_diff(state *prevstate) {
    mu_State.print_diff(prevstate);
    mu_Proc.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_State.to_state(thestate);
    mu_Proc.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1__type_26& operator= (const mu_1__type_26& from) {
    mu_State.value(from.mu_State.value());
    mu_Proc.value(from.mu_Proc.value());
    return *this;
  };
};

  void mu_1__type_26::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_26::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_26::set_self(char *n, int os)
{
  name = n;
  mu_State.set_self_2(name, ".State", os + 0 );
  mu_Proc.set_self_2(name, ".Proc", os + 2 );
}

mu_1__type_26::~mu_1__type_26()
{
}

/*** end record declaration ***/
mu_1__type_26 mu_1__type_26_undefined_var;

class mu_1__type_27
{
 public:
  mu_1__type_26 array[ 1 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_27 (char *n, int os) { set_self(n, os); };
  mu_1__type_27 ( void ) {};
  virtual ~mu_1__type_27 ();
  mu_1__type_26& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 6 ) && ( index <= 6 ) )
      return array[ index - 6 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: LAddress is internally represented from 6 to 6.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 6 ];
#endif
  };
  mu_1__type_27& operator= (const mu_1__type_27& from)
  {
      array[0] = from.array[0];
    return *this;
  }

friend int CompareWeight(mu_1__type_27& a, mu_1__type_27& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_27& a, mu_1__type_27& b)
  {
    int w;
    for (int i=0; i<1; i++) {
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
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 1; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_27::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_27::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_27::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"LAddress_1", i * 5 + os);i++;
}
mu_1__type_27::~mu_1__type_27()
{
}
/*** end array declaration ***/
mu_1__type_27 mu_1__type_27_undefined_var;

class mu_1__type_28
{
 public:
  mu_1__type_27 array[ 1 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_28 (char *n, int os) { set_self(n, os); };
  mu_1__type_28 ( void ) {};
  virtual ~mu_1__type_28 ();
  mu_1__type_27& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 1 ) )
      return array[ index - 1 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: Home is internally represented from 1 to 1.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_28& operator= (const mu_1__type_28& from)
  {
      array[0] = from.array[0];
    return *this;
  }

friend int CompareWeight(mu_1__type_28& a, mu_1__type_28& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_28& a, mu_1__type_28& b)
  {
    int w;
    for (int i=0; i<1; i++) {
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
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 1; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_28::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_28::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_28::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"Home_1", i * 5 + os);i++;
}
mu_1__type_28::~mu_1__type_28()
{
}
/*** end array declaration ***/
mu_1__type_28 mu_1__type_28_undefined_var;

class mu__subrange_46: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_46& val) { return mu__byte::operator=((int) val); };
  mu__subrange_46 (char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_46 (void): mu__byte(0, 2, 2) {};
  mu__subrange_46 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_46 mu__subrange_46_undefined_var;

class mu__subrange_47: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_47& val) { return mu__byte::operator=((int) val); };
  mu__subrange_47 (char *name, int os): mu__byte(0, 4, 3, name, os) {};
  mu__subrange_47 (void): mu__byte(0, 4, 3) {};
  mu__subrange_47 (int val): mu__byte(0, 4, 3, "Parameter or function result.", 0)
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
mu__subrange_47 mu__subrange_47_undefined_var;

class mu__subrange_48: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_48& val) { return mu__byte::operator=((int) val); };
  mu__subrange_48 (char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_48 (void): mu__byte(0, 2, 2) {};
  mu__subrange_48 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
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
mu__subrange_48 mu__subrange_48_undefined_var;

const int mu_HomeCount = 1;
const int mu_RemoteCount = 4;
const int mu_ProcCount = 5;
const int mu_LockAddressCount = 1;
const int mu_DirMax = 5;
const int mu_ChanMax = 3;
const int mu_nohome = 1;
const int mu_Home_1 = 1;
const int mu_Remote_1 = 2;
const int mu_Remote_2 = 3;
const int mu_Remote_3 = 4;
const int mu_Remote_4 = 5;
const int mu_LAddress_1 = 6;
const int mu_RD_L = 7;
const int mu_GSET = 8;
const int mu_IOWR = 9;
const int mu_ACK_L = 10;
const int mu_LCK = 11;
const int mu_UNLCK = 12;
const int mu_INVAL = 13;
const int mu_DLCK = 14;
const int mu_DULCK = 15;
const int mu_DGNTS = 16;
const int mu_WLCK = 17;
const int mu_RLCK = 18;
const int mu_WDIRW = 19;
const int mu_Non_Locally_Cached = 20;
const int mu_Locally_Shared = 21;
const int mu_Unlocked = 22;
const int mu_Locked = 23;
const int mu_Queued = 24;
/*** Variable declaration ***/
mu_1__type_17 mu_ReqNet("ReqNet",0);

/*** Variable declaration ***/
mu_1__type_22 mu_ReplyNet("ReplyNet",525);

/*** Variable declaration ***/
mu_1__type_23 mu_Procs("Procs",1050);

/*** Variable declaration ***/
mu_1__type_24 mu_Homes("Homes",1105);

const int mu_Invalid = 25;
const int mu_Valid = 26;
/*** Variable declaration ***/
mu_1__type_28 mu_LockOwner("LockOwner",1125);

void mu_Remove_from_Queue(const mu_1_Proc& mu_h, const mu_1_LAddress& mu_l, const mu_1_Dir_Index& mu_Entry)
{
{
  mu_1_Dir_Index& mu_QueuedCount = mu_Homes[mu_h].mu_LDir[mu_l].mu_QueuedCount;
{
int mu__ub29 = (mu_QueuedCount) - (2);
for (int mu_i = 0; mu_i <= mu__ub29; mu_i += 1) {
if ( (mu_i) >= (mu_Entry) )
{
mu_Homes[mu_h].mu_LDir[mu_l].mu_Entries[mu_i] = mu_Homes[mu_h].mu_LDir[mu_l].mu_Entries[(mu_i) + (1)];
}
};
};
mu_Homes[mu_h].mu_LDir[mu_l].mu_Entries[(mu_QueuedCount) - (1)].undefine();
mu_QueuedCount = (mu_QueuedCount) - (1);
if ( (mu_QueuedCount) == (0) )
{
mu_Homes[mu_h].mu_LDir[mu_l].mu_State = mu_Locked;
}
}
};
/*** end procedure declaration ***/

void mu_Add_to_LDir_Entries(const mu_1_Proc& mu_h, const mu_1_LAddress& mu_l, const mu_1_Proc& mu_n)
{
{
  mu_1_Dir_Index& mu_QueuedCount = mu_Homes[mu_h].mu_LDir[mu_l].mu_QueuedCount;
bool mu__quant30; 
mu__quant30 = TRUE;
{
for(int mu_i = 0; mu_i <= 4; mu_i++) {
bool mu__boolexpr31;
  if (!((mu_i) < (mu_QueuedCount))) mu__boolexpr31 = TRUE ;
  else {
  mu__boolexpr31 = ((mu_Homes[mu_h].mu_LDir[mu_l].mu_Entries[mu_i]) != (mu_n)) ; 
}
if ( !(mu__boolexpr31) )
  { mu__quant30 = FALSE; break; }
};
};
if ( mu__quant30 )
{
if ( !((mu_QueuedCount) < (mu_DirMax)) ) Error.Error("Assertion failed: directory queue overflow");
if (mu_n.isundefined())
  mu_Homes[mu_h].mu_LDir[mu_l].mu_Entries[mu_QueuedCount].undefine();
else
  mu_Homes[mu_h].mu_LDir[mu_l].mu_Entries[mu_QueuedCount] = mu_n;
mu_QueuedCount = (mu_QueuedCount) + (1);
}
}
};
/*** end procedure declaration ***/

void mu_Send_Req(const mu_1_Request_Type& mu_t, const mu_1_Proc& mu_Dst, const mu_1_Proc& mu_Src, const mu_1_Proc& mu_Aux, const mu_1_LAddress& mu_LAddr)
{
{
  mu_1__type_13& mu_NewID = mu_ReqNet[mu_Src][mu_Dst].mu_Count;
if ( !((mu_NewID) != (mu_ChanMax)) ) Error.Error("Assertion failed: Request Channel is full");
if (mu_t.isundefined())
  mu_ReqNet[mu_Src][mu_Dst].mu_Messages[mu_NewID].mu_Mtype.undefine();
else
  mu_ReqNet[mu_Src][mu_Dst].mu_Messages[mu_NewID].mu_Mtype = mu_t;
if ( mu_Aux.isundefined() )
{
mu_ReqNet[mu_Src][mu_Dst].mu_Messages[mu_NewID].mu_Aux.undefine();
}
else
{
if (mu_Aux.isundefined())
  mu_ReqNet[mu_Src][mu_Dst].mu_Messages[mu_NewID].mu_Aux.undefine();
else
  mu_ReqNet[mu_Src][mu_Dst].mu_Messages[mu_NewID].mu_Aux = mu_Aux;
}
if (mu_LAddr.isundefined())
  mu_ReqNet[mu_Src][mu_Dst].mu_Messages[mu_NewID].mu_LAddr.undefine();
else
  mu_ReqNet[mu_Src][mu_Dst].mu_Messages[mu_NewID].mu_LAddr = mu_LAddr;
mu_NewID = (mu_NewID) + (1);
}
};
/*** end procedure declaration ***/

void mu_Consume_Request(const mu_1_Proc& mu_Src, const mu_1_Proc& mu_Dst)
{
{
  mu_1__type_13& mu_NumID = mu_ReqNet[mu_Src][mu_Dst].mu_Count;
{
int mu__ub32 = (mu_NumID) - (2);
for (int mu_i = 0; mu_i <= mu__ub32; mu_i += 1) {
mu_ReqNet[mu_Src][mu_Dst].mu_Messages[mu_i] = mu_ReqNet[mu_Src][mu_Dst].mu_Messages[(mu_i) + (1)];
};
};
mu_ReqNet[mu_Src][mu_Dst].mu_Messages[(mu_NumID) - (1)].undefine();
mu_NumID = (mu_NumID) - (1);
}
};
/*** end procedure declaration ***/

void mu_Send_Reply(const mu_1_Reply_Type& mu_t, const mu_1_Proc& mu_Dst, const mu_1_Proc& mu_Src, const mu_1_Proc& mu_Aux, const mu_1_LAddress& mu_LAddr)
{
{
  mu_1__type_18& mu_NewID = mu_ReplyNet[mu_Src][mu_Dst].mu_Count;
if ( !((mu_NewID) != (mu_ChanMax)) ) Error.Error("Assertion failed: Reply Channel is full");
if (mu_t.isundefined())
  mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[mu_NewID].mu_Mtype.undefine();
else
  mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[mu_NewID].mu_Mtype = mu_t;
if ( mu_Aux.isundefined() )
{
mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[mu_NewID].mu_Aux.undefine();
}
else
{
if (mu_Aux.isundefined())
  mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[mu_NewID].mu_Aux.undefine();
else
  mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[mu_NewID].mu_Aux = mu_Aux;
}
if (mu_LAddr.isundefined())
  mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[mu_NewID].mu_LAddr.undefine();
else
  mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[mu_NewID].mu_LAddr = mu_LAddr;
mu_NewID = (mu_NewID) + (1);
}
};
/*** end procedure declaration ***/

void mu_Consume_Reply(const mu_1_Proc& mu_Src, const mu_1_Proc& mu_Dst)
{
{
  mu_1__type_18& mu_NumID = mu_ReplyNet[mu_Src][mu_Dst].mu_Count;
{
int mu__ub33 = (mu_NumID) - (2);
for (int mu_i = 0; mu_i <= mu__ub33; mu_i += 1) {
mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[mu_i] = mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[(mu_i) + (1)];
};
};
mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[(mu_NumID) - (1)].undefine();
mu_NumID = (mu_NumID) - (1);
}
};
/*** end procedure declaration ***/

void mu_Check_Mutual_Exclusion(const mu_1_Home& mu_h, const mu_1_LAddress& mu_l)
{
if ( !((mu_LockOwner[mu_h][mu_l].mu_State) != (mu_Valid)) ) Error.Error("Assertion failed: Mutual exclusion violated");
};
/*** end procedure declaration ***/

void mu_Send_ACK_L(const mu_1_Proc& mu_Dst, const mu_1_Proc& mu_Src, const mu_1_Proc& mu_Aux, const mu_1_LAddress& mu_l)
{
mu_Send_Reply ( mu_ACK_L, mu_Dst, mu_Src, mu_Aux, mu_l );
};
/*** end procedure declaration ***/

void mu_Send_RD_L(const mu_1_Proc& mu_Dst, const mu_1_Proc& mu_Src, const mu_1_LAddress& mu_l)
{
/*** Variable declaration ***/
mu_1_Proc mu_UNDEF("UNDEF",0);

mu_UNDEF.undefine();
mu_Send_Req ( mu_RD_L, mu_Dst, mu_Src, mu_UNDEF, mu_l );
};
/*** end procedure declaration ***/

void mu_Send_Grant_SET(const mu_1_Proc& mu_Dst, const mu_1_Proc& mu_Src, const mu_1_Proc& mu_Aux, const mu_1_LAddress& mu_l)
{
mu_Send_Req ( mu_GSET, mu_Dst, mu_Src, mu_Aux, mu_l );
};
/*** end procedure declaration ***/

void mu_Send_Unlock(const mu_1_Proc& mu_Dst, const mu_1_Proc& mu_Src, const mu_1_Proc& mu_Aux, const mu_1_LAddress& mu_l)
{
mu_Send_Req ( mu_IOWR, mu_Dst, mu_Src, mu_Aux, mu_l );
};
/*** end procedure declaration ***/

void mu_Send_Unlock_Reply(const mu_1_Proc& mu_Dst, const mu_1_Proc& mu_Src, const mu_1_LAddress& mu_l)
{
/*** Variable declaration ***/
mu_1_Proc mu_UNDEF("UNDEF",0);

mu_UNDEF.undefine();
mu_Send_Reply ( mu_UNLCK, mu_Dst, mu_Src, mu_UNDEF, mu_l );
};
/*** end procedure declaration ***/

void mu_Send_Lock_Reply(const mu_1_Proc& mu_Dst, const mu_1_Proc& mu_Src, const mu_1_LAddress& mu_l)
{
/*** Variable declaration ***/
mu_1_Proc mu_UNDEF("UNDEF",0);

mu_UNDEF.undefine();
mu_Send_Reply ( mu_LCK, mu_Dst, mu_Src, mu_UNDEF, mu_l );
};
/*** end procedure declaration ***/





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_ReqNet.clear();
  mu_ReplyNet.clear();
  mu_Procs.clear();
  mu_Homes.clear();
  mu_LockOwner.clear();
}
void world_class::undefine()
{
  mu_ReqNet.undefine();
  mu_ReplyNet.undefine();
  mu_Procs.undefine();
  mu_Homes.undefine();
  mu_LockOwner.undefine();
}
void world_class::reset()
{
  mu_ReqNet.reset();
  mu_ReplyNet.reset();
  mu_Procs.reset();
  mu_Homes.reset();
  mu_LockOwner.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_ReqNet.print();
  mu_ReplyNet.print();
  mu_Procs.print();
  mu_Homes.print();
  mu_LockOwner.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_ReqNet.print_statistic();
  mu_ReplyNet.print_statistic();
  mu_Procs.print_statistic();
  mu_Homes.print_statistic();
  mu_LockOwner.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_ReqNet.print_diff(prevstate);
    mu_ReplyNet.print_diff(prevstate);
    mu_Procs.print_diff(prevstate);
    mu_Homes.print_diff(prevstate);
    mu_LockOwner.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_ReqNet.to_state( newstate );
  mu_ReplyNet.to_state( newstate );
  mu_Procs.to_state( newstate );
  mu_Homes.to_state( newstate );
  mu_LockOwner.to_state( newstate );
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
    static mu_1_Proc mu_Src;
    mu_Src.unionassign(r % 5);
    r = r / 5;
    static mu_1_Proc mu_Dst;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
    return tsprintf("Handle release acknowledgement, Src:%s, Dst:%s", mu_Src.Name(), mu_Dst.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Proc mu_Src;
    mu_Src.unionassign(r % 5);
    r = r / 5;
    static mu_1_Proc mu_Dst;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
  mu_1__type_20& mu_ReplyChan = mu_ReplyNet[mu_Src][mu_Dst];
  mu_1_Reply_Type& mu_Reply = mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[0].mu_Mtype;
  mu_1_LAddress& mu_LAddr = mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[0].mu_LAddr;
  mu_1_Proc& mu_Aux = mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[0].mu_Aux;
bool mu__boolexpr34;
  if (!((mu_ReplyChan.mu_Count) > (0))) mu__boolexpr34 = FALSE ;
  else {
  mu__boolexpr34 = ((mu_Reply) == (mu_ACK_L)) ; 
}
  return mu__boolexpr34;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    static mu_1_Proc mu_Src;
    mu_Src.unionassign(r % 5);
    r = r / 5;
    static mu_1_Proc mu_Dst;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
    while (what_rule < 25 )
      {
        if ( ( TRUE  ) ) {
  mu_1__type_20& mu_ReplyChan = mu_ReplyNet[mu_Src][mu_Dst];
  mu_1_Reply_Type& mu_Reply = mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[0].mu_Mtype;
  mu_1_LAddress& mu_LAddr = mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[0].mu_LAddr;
  mu_1_Proc& mu_Aux = mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[0].mu_Aux;
bool mu__boolexpr35;
  if (!((mu_ReplyChan.mu_Count) > (0))) mu__boolexpr35 = FALSE ;
  else {
  mu__boolexpr35 = ((mu_Reply) == (mu_ACK_L)) ; 
}
              if (mu__boolexpr35) {
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
    mu_Src.unionassign(r % 5);
    r = r / 5;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Proc mu_Src;
    mu_Src.unionassign(r % 5);
    r = r / 5;
    static mu_1_Proc mu_Dst;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
  mu_1__type_20& mu_ReplyChan = mu_ReplyNet[mu_Src][mu_Dst];
  mu_1_Reply_Type& mu_Reply = mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[0].mu_Mtype;
  mu_1_LAddress& mu_LAddr = mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[0].mu_LAddr;
  mu_1_Proc& mu_Aux = mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[0].mu_Aux;
{
  mu_1__type_10& mu_ULRAC = mu_Procs[mu_Dst].mu_ULRAC[mu_Aux][mu_LAddr];
switch ((int) mu_ULRAC.mu_State) {
case mu_WDIRW:
mu_ULRAC.mu_State = mu_INVAL;
break;
default:
Error.Error("Error: release acknowledgement with funny ULRAC entry");
break;
}
mu_Consume_Reply ( mu_Src, mu_Dst );
}
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
    static mu_1_Proc mu_Src;
    mu_Src.unionassign(r % 5);
    r = r / 5;
    static mu_1_Proc mu_Dst;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
    return tsprintf("Handle lock reply, Src:%s, Dst:%s", mu_Src.Name(), mu_Dst.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Proc mu_Src;
    mu_Src.unionassign(r % 5);
    r = r / 5;
    static mu_1_Proc mu_Dst;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
  mu_1__type_20& mu_ReplyChan = mu_ReplyNet[mu_Src][mu_Dst];
  mu_1_Reply_Type& mu_Reply = mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[0].mu_Mtype;
  mu_1_LAddress& mu_LAddr = mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[0].mu_LAddr;
  mu_1_Proc& mu_Aux = mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[0].mu_Aux;
bool mu__boolexpr36;
  if (!((mu_ReplyChan.mu_Count) > (0))) mu__boolexpr36 = FALSE ;
  else {
  mu__boolexpr36 = ((mu_Reply) == (mu_LCK)) ; 
}
  return mu__boolexpr36;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 25;
    static mu_1_Proc mu_Src;
    mu_Src.unionassign(r % 5);
    r = r / 5;
    static mu_1_Proc mu_Dst;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
    while (what_rule < 50 )
      {
        if ( ( TRUE  ) ) {
  mu_1__type_20& mu_ReplyChan = mu_ReplyNet[mu_Src][mu_Dst];
  mu_1_Reply_Type& mu_Reply = mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[0].mu_Mtype;
  mu_1_LAddress& mu_LAddr = mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[0].mu_LAddr;
  mu_1_Proc& mu_Aux = mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[0].mu_Aux;
bool mu__boolexpr37;
  if (!((mu_ReplyChan.mu_Count) > (0))) mu__boolexpr37 = FALSE ;
  else {
  mu__boolexpr37 = ((mu_Reply) == (mu_LCK)) ; 
}
              if (mu__boolexpr37) {
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
    r = what_rule - 25;
    mu_Src.unionassign(r % 5);
    r = r / 5;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Proc mu_Src;
    mu_Src.unionassign(r % 5);
    r = r / 5;
    static mu_1_Proc mu_Dst;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
  mu_1__type_20& mu_ReplyChan = mu_ReplyNet[mu_Src][mu_Dst];
  mu_1_Reply_Type& mu_Reply = mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[0].mu_Mtype;
  mu_1_LAddress& mu_LAddr = mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[0].mu_LAddr;
  mu_1_Proc& mu_Aux = mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[0].mu_Aux;
{
  mu_1__type_7& mu_LRAC = mu_Procs[mu_Dst].mu_LRAC[mu_Src][mu_LAddr];
switch ((int) mu_LRAC.mu_State) {
case mu_WLCK:
mu_LRAC.mu_State = mu_DLCK;
break;
case mu_RLCK:
mu_LRAC.mu_State = mu_INVAL;
mu_LRAC.mu_Granting.undefine();
break;
default:
Error.Error("Error: lock reply with funny LRAC state");
break;
}
mu_Consume_Reply ( mu_Src, mu_Dst );
}
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
    static mu_1_Proc mu_Src;
    mu_Src.unionassign(r % 5);
    r = r / 5;
    static mu_1_Proc mu_Dst;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
    return tsprintf("Handle unlock reply, Src:%s, Dst:%s", mu_Src.Name(), mu_Dst.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Proc mu_Src;
    mu_Src.unionassign(r % 5);
    r = r / 5;
    static mu_1_Proc mu_Dst;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
  mu_1__type_20& mu_ReplyChan = mu_ReplyNet[mu_Src][mu_Dst];
  mu_1_Reply_Type& mu_Reply = mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[0].mu_Mtype;
  mu_1_LAddress& mu_LAddr = mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[0].mu_LAddr;
  mu_1_Proc& mu_Aux = mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[0].mu_Aux;
bool mu__boolexpr38;
  if (!((mu_ReplyChan.mu_Count) > (0))) mu__boolexpr38 = FALSE ;
  else {
  mu__boolexpr38 = ((mu_Reply) == (mu_UNLCK)) ; 
}
  return mu__boolexpr38;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 50;
    static mu_1_Proc mu_Src;
    mu_Src.unionassign(r % 5);
    r = r / 5;
    static mu_1_Proc mu_Dst;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
    while (what_rule < 75 )
      {
        if ( ( TRUE  ) ) {
  mu_1__type_20& mu_ReplyChan = mu_ReplyNet[mu_Src][mu_Dst];
  mu_1_Reply_Type& mu_Reply = mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[0].mu_Mtype;
  mu_1_LAddress& mu_LAddr = mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[0].mu_LAddr;
  mu_1_Proc& mu_Aux = mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[0].mu_Aux;
bool mu__boolexpr39;
  if (!((mu_ReplyChan.mu_Count) > (0))) mu__boolexpr39 = FALSE ;
  else {
  mu__boolexpr39 = ((mu_Reply) == (mu_UNLCK)) ; 
}
              if (mu__boolexpr39) {
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
    r = what_rule - 50;
    mu_Src.unionassign(r % 5);
    r = r / 5;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Proc mu_Src;
    mu_Src.unionassign(r % 5);
    r = r / 5;
    static mu_1_Proc mu_Dst;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
  mu_1__type_20& mu_ReplyChan = mu_ReplyNet[mu_Src][mu_Dst];
  mu_1_Reply_Type& mu_Reply = mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[0].mu_Mtype;
  mu_1_LAddress& mu_LAddr = mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[0].mu_LAddr;
  mu_1_Proc& mu_Aux = mu_ReplyNet[mu_Src][mu_Dst].mu_Messages[0].mu_Aux;
{
  mu_1__type_7& mu_LRAC = mu_Procs[mu_Dst].mu_LRAC[mu_Src][mu_LAddr];
switch ((int) mu_LRAC.mu_State) {
case mu_WLCK:
mu_LRAC.mu_State = mu_DULCK;
break;
case mu_RLCK:
Error.Error("Error: unlock reply with funny LRAC state");
mu_LRAC.mu_State = mu_DULCK;
break;
default:
Error.Error("Error: unlock reply with funny LRAC state");
break;
}
mu_Consume_Reply ( mu_Src, mu_Dst );
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase3 ********************/
class RuleBase3
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Proc mu_Src;
    mu_Src.unionassign(r % 5);
    r = r / 5;
    static mu_1_Proc mu_Dst;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
    return tsprintf("Handle lock grant to grant cluster, Src:%s, Dst:%s", mu_Src.Name(), mu_Dst.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Proc mu_Src;
    mu_Src.unionassign(r % 5);
    r = r / 5;
    static mu_1_Proc mu_Dst;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
  mu_1__type_15& mu_ReqChan = mu_ReqNet[mu_Src][mu_Dst];
  mu_1_Request_Type& mu_Request = mu_ReqNet[mu_Src][mu_Dst].mu_Messages[0].mu_Mtype;
  mu_1_LAddress& mu_LAddr = mu_ReqNet[mu_Src][mu_Dst].mu_Messages[0].mu_LAddr;
  mu_1_Proc& mu_Aux = mu_ReqNet[mu_Src][mu_Dst].mu_Messages[0].mu_Aux;
bool mu__boolexpr40;
  if (!((mu_ReqChan.mu_Count) > (0))) mu__boolexpr40 = FALSE ;
  else {
  mu__boolexpr40 = ((mu_Request) == (mu_GSET)) ; 
}
  return mu__boolexpr40;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 75;
    static mu_1_Proc mu_Src;
    mu_Src.unionassign(r % 5);
    r = r / 5;
    static mu_1_Proc mu_Dst;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
    while (what_rule < 100 )
      {
        if ( ( TRUE  ) ) {
  mu_1__type_15& mu_ReqChan = mu_ReqNet[mu_Src][mu_Dst];
  mu_1_Request_Type& mu_Request = mu_ReqNet[mu_Src][mu_Dst].mu_Messages[0].mu_Mtype;
  mu_1_LAddress& mu_LAddr = mu_ReqNet[mu_Src][mu_Dst].mu_Messages[0].mu_LAddr;
  mu_1_Proc& mu_Aux = mu_ReqNet[mu_Src][mu_Dst].mu_Messages[0].mu_Aux;
bool mu__boolexpr41;
  if (!((mu_ReqChan.mu_Count) > (0))) mu__boolexpr41 = FALSE ;
  else {
  mu__boolexpr41 = ((mu_Request) == (mu_GSET)) ; 
}
              if (mu__boolexpr41) {
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
    r = what_rule - 75;
    mu_Src.unionassign(r % 5);
    r = r / 5;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Proc mu_Src;
    mu_Src.unionassign(r % 5);
    r = r / 5;
    static mu_1_Proc mu_Dst;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
  mu_1__type_15& mu_ReqChan = mu_ReqNet[mu_Src][mu_Dst];
  mu_1_Request_Type& mu_Request = mu_ReqNet[mu_Src][mu_Dst].mu_Messages[0].mu_Mtype;
  mu_1_LAddress& mu_LAddr = mu_ReqNet[mu_Src][mu_Dst].mu_Messages[0].mu_LAddr;
  mu_1_Proc& mu_Aux = mu_ReqNet[mu_Src][mu_Dst].mu_Messages[0].mu_Aux;
{
  mu_1__type_7& mu_LRAC = mu_Procs[mu_Dst].mu_LRAC[mu_Src][mu_LAddr];
  mu_1__type_10& mu_ULRAC = mu_Procs[mu_Dst].mu_ULRAC[mu_Src][mu_LAddr];
switch ((int) mu_LRAC.mu_State) {
case mu_INVAL:
mu_LRAC.mu_State = mu_DGNTS;
mu_LRAC.mu_Granting = mu_Aux;
break;
case mu_WLCK:
mu_LRAC.mu_State = mu_RLCK;
mu_Send_Unlock ( mu_Src, mu_Dst, mu_Aux, mu_LAddr );
break;
case mu_DLCK:
mu_LRAC.mu_State = mu_DGNTS;
mu_LRAC.mu_Granting = mu_Aux;
break;
case mu_RLCK:
Error.Error("Error: GSET with RLCK");
break;
default:
Error.Error("Error: GSET with funny LRAC state");
break;
}
mu_Consume_Request ( mu_Src, mu_Dst );
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase4 ********************/
class RuleBase4
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Dir_Index mu_j;
    mu_j.value((r % 5) + 0);
    r = r / 5;
    static mu_1_Proc mu_Src;
    mu_Src.unionassign(r % 5);
    r = r / 5;
    static mu_1_Proc mu_Dst;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
    return tsprintf("Handle unlock request to home, j:%s, Src:%s, Dst:%s", mu_j.Name(), mu_Src.Name(), mu_Dst.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Dir_Index mu_j;
    mu_j.value((r % 5) + 0);
    r = r / 5;
    static mu_1_Proc mu_Src;
    mu_Src.unionassign(r % 5);
    r = r / 5;
    static mu_1_Proc mu_Dst;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
  mu_1__type_15& mu_ReqChan = mu_ReqNet[mu_Src][mu_Dst];
  mu_1_Request_Type& mu_Request = mu_ReqNet[mu_Src][mu_Dst].mu_Messages[0].mu_Mtype;
  mu_1_Proc& mu_Aux = mu_ReqNet[mu_Src][mu_Dst].mu_Messages[0].mu_Aux;
  mu_1_LAddress& mu_LAddr = mu_ReqNet[mu_Src][mu_Dst].mu_Messages[0].mu_LAddr;
bool mu__boolexpr42;
  if (!((mu_ReqChan.mu_Count) > (0))) mu__boolexpr42 = FALSE ;
  else {
  mu__boolexpr42 = ((mu_Request) == (mu_IOWR)) ; 
}
  return mu__boolexpr42;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 100;
    static mu_1_Dir_Index mu_j;
    mu_j.value((r % 5) + 0);
    r = r / 5;
    static mu_1_Proc mu_Src;
    mu_Src.unionassign(r % 5);
    r = r / 5;
    static mu_1_Proc mu_Dst;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
    while (what_rule < 225 )
      {
        if ( ( TRUE  ) ) {
  mu_1__type_15& mu_ReqChan = mu_ReqNet[mu_Src][mu_Dst];
  mu_1_Request_Type& mu_Request = mu_ReqNet[mu_Src][mu_Dst].mu_Messages[0].mu_Mtype;
  mu_1_Proc& mu_Aux = mu_ReqNet[mu_Src][mu_Dst].mu_Messages[0].mu_Aux;
  mu_1_LAddress& mu_LAddr = mu_ReqNet[mu_Src][mu_Dst].mu_Messages[0].mu_LAddr;
bool mu__boolexpr43;
  if (!((mu_ReqChan.mu_Count) > (0))) mu__boolexpr43 = FALSE ;
  else {
  mu__boolexpr43 = ((mu_Request) == (mu_IOWR)) ; 
}
              if (mu__boolexpr43) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 5;
        }
        else
          what_rule += 5;
    r = what_rule - 100;
    mu_j.value((r % 5) + 0);
    r = r / 5;
    mu_Src.unionassign(r % 5);
    r = r / 5;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Dir_Index mu_j;
    mu_j.value((r % 5) + 0);
    r = r / 5;
    static mu_1_Proc mu_Src;
    mu_Src.unionassign(r % 5);
    r = r / 5;
    static mu_1_Proc mu_Dst;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
  mu_1__type_15& mu_ReqChan = mu_ReqNet[mu_Src][mu_Dst];
  mu_1_Request_Type& mu_Request = mu_ReqNet[mu_Src][mu_Dst].mu_Messages[0].mu_Mtype;
  mu_1_Proc& mu_Aux = mu_ReqNet[mu_Src][mu_Dst].mu_Messages[0].mu_Aux;
  mu_1_LAddress& mu_LAddr = mu_ReqNet[mu_Src][mu_Dst].mu_Messages[0].mu_LAddr;
{
  mu_1__type_7& mu_LRAC = mu_Procs[mu_Dst].mu_LRAC[mu_Dst][mu_LAddr];
  mu_1__type_10& mu_ULRAC = mu_Procs[mu_Dst].mu_ULRAC[mu_Dst][mu_LAddr];
  mu_1__type_2& mu_LDir = mu_Homes[mu_Dst].mu_LDir[mu_LAddr];
switch ((int) mu_LRAC.mu_State) {
case mu_INVAL:
switch ((int) mu_LDir.mu_State) {
case mu_Unlocked:
Error.Error("Error: release when lock is not acquired.");
break;
case mu_Locked:
mu_LDir.mu_State = mu_Unlocked;
mu_LDir.mu_QueuedCount = 0;
mu_LDir.mu_Entries.undefine();
if ( (mu_Aux) == (mu_Dst) )
{
if ( !((mu_ULRAC.mu_State) == (mu_WDIRW)) ) Error.Error("Assertion failed: lock ack to funny ULRAC state");
mu_ULRAC.mu_State = mu_INVAL;
}
else
{
mu_Send_ACK_L ( mu_Aux, mu_Dst, mu_Dst, mu_LAddr );
}
mu_Consume_Request ( mu_Src, mu_Dst );
break;
case mu_Queued:
bool mu__boolexpr44;
  if (!((mu_j) < (mu_LDir.mu_QueuedCount))) mu__boolexpr44 = FALSE ;
  else {
  mu__boolexpr44 = ((mu_LDir.mu_Entries[mu_j]) != (mu_Dst)) ; 
}
if ( mu__boolexpr44 )
{
mu_Send_Grant_SET ( mu_LDir.mu_Entries[mu_j], mu_Dst, mu_Aux, mu_LAddr );
mu_Remove_from_Queue ( mu_Dst, mu_LAddr, mu_j );
mu_Consume_Request ( mu_Src, mu_Dst );
}
else
{
bool mu__boolexpr45;
  if (!((mu_j) < (mu_LDir.mu_QueuedCount))) mu__boolexpr45 = FALSE ;
  else {
  mu__boolexpr45 = ((mu_LDir.mu_Entries[mu_j]) == (mu_Dst)) ; 
}
if ( mu__boolexpr45 )
{
mu_LRAC.mu_State = mu_DGNTS;
mu_LRAC.mu_Granting = mu_Aux;
mu_Remove_from_Queue ( mu_Dst, mu_LAddr, mu_j );
mu_Consume_Request ( mu_Src, mu_Dst );
}
}
break;
}
break;
default:
Error.Error("Error: IOWR in funny LRAC state");
break;
}
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase5 ********************/
class RuleBase5
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Proc mu_Src;
    mu_Src.unionassign(r % 5);
    r = r / 5;
    static mu_1_Proc mu_Dst;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
    return tsprintf("Handle lock read request, Src:%s, Dst:%s", mu_Src.Name(), mu_Dst.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Proc mu_Src;
    mu_Src.unionassign(r % 5);
    r = r / 5;
    static mu_1_Proc mu_Dst;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
  mu_1__type_15& mu_ReqChan = mu_ReqNet[mu_Src][mu_Dst];
  mu_1_Request_Type& mu_Request = mu_ReqNet[mu_Src][mu_Dst].mu_Messages[0].mu_Mtype;
  mu_1_Proc& mu_Aux = mu_ReqNet[mu_Src][mu_Dst].mu_Messages[0].mu_Aux;
  mu_1_LAddress& mu_LAddr = mu_ReqNet[mu_Src][mu_Dst].mu_Messages[0].mu_LAddr;
bool mu__boolexpr46;
  if (!((mu_ReqChan.mu_Count) > (0))) mu__boolexpr46 = FALSE ;
  else {
  mu__boolexpr46 = ((mu_Request) == (mu_RD_L)) ; 
}
  return mu__boolexpr46;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 225;
    static mu_1_Proc mu_Src;
    mu_Src.unionassign(r % 5);
    r = r / 5;
    static mu_1_Proc mu_Dst;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
    while (what_rule < 250 )
      {
        if ( ( TRUE  ) ) {
  mu_1__type_15& mu_ReqChan = mu_ReqNet[mu_Src][mu_Dst];
  mu_1_Request_Type& mu_Request = mu_ReqNet[mu_Src][mu_Dst].mu_Messages[0].mu_Mtype;
  mu_1_Proc& mu_Aux = mu_ReqNet[mu_Src][mu_Dst].mu_Messages[0].mu_Aux;
  mu_1_LAddress& mu_LAddr = mu_ReqNet[mu_Src][mu_Dst].mu_Messages[0].mu_LAddr;
bool mu__boolexpr47;
  if (!((mu_ReqChan.mu_Count) > (0))) mu__boolexpr47 = FALSE ;
  else {
  mu__boolexpr47 = ((mu_Request) == (mu_RD_L)) ; 
}
              if (mu__boolexpr47) {
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
    r = what_rule - 225;
    mu_Src.unionassign(r % 5);
    r = r / 5;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Proc mu_Src;
    mu_Src.unionassign(r % 5);
    r = r / 5;
    static mu_1_Proc mu_Dst;
    mu_Dst.unionassign(r % 5);
    r = r / 5;
  mu_1__type_15& mu_ReqChan = mu_ReqNet[mu_Src][mu_Dst];
  mu_1_Request_Type& mu_Request = mu_ReqNet[mu_Src][mu_Dst].mu_Messages[0].mu_Mtype;
  mu_1_Proc& mu_Aux = mu_ReqNet[mu_Src][mu_Dst].mu_Messages[0].mu_Aux;
  mu_1_LAddress& mu_LAddr = mu_ReqNet[mu_Src][mu_Dst].mu_Messages[0].mu_LAddr;
{
  mu_1__type_2& mu_LDir = mu_Homes[mu_Dst].mu_LDir[mu_LAddr];
  mu_1__type_4& mu_LCache = mu_Procs[mu_Dst].mu_LCache[mu_Dst][mu_LAddr];
switch ((int) mu_LDir.mu_State) {
case mu_Unlocked:
switch ((int) mu_LCache.mu_State) {
case mu_Non_Locally_Cached:
mu_LDir.mu_State = mu_Locked;
mu_Send_Unlock_Reply ( mu_Src, mu_Dst, mu_LAddr );
break;
case mu_Locally_Shared:
Error.Error("Error: inconsistent LDir and LCache");
break;
}
break;
default:
mu_LDir.mu_State = mu_Queued;
mu_Add_to_LDir_Entries ( mu_Dst, mu_LAddr, mu_Src );
mu_Send_Lock_Reply ( mu_Src, mu_Dst, mu_LAddr );
break;
}
mu_Consume_Request ( mu_Src, mu_Dst );
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase6 ********************/
class RuleBase6
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Dir_Index mu_j;
    mu_j.value((r % 5) + 0);
    r = r / 5;
    static mu_1_LAddress mu_l;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.unionassign(r % 5);
    r = r / 5;
    return tsprintf("Timeout at home cluster -> Grant Rejected, j:%s, l:%s, h:%s, n:%s", mu_j.Name(), mu_l.Name(), mu_h.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Dir_Index mu_j;
    mu_j.value((r % 5) + 0);
    r = r / 5;
    static mu_1_LAddress mu_l;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.unionassign(r % 5);
    r = r / 5;
  mu_1__type_7& mu_LRAC = mu_Procs[mu_n].mu_LRAC[mu_h][mu_l];
  mu_1__type_10& mu_ULRAC = mu_Procs[mu_n].mu_ULRAC[mu_h][mu_l];
  mu_1__type_4& mu_LCache = mu_Procs[mu_n].mu_LCache[mu_h][mu_l];
  mu_1__type_2& mu_LDir = mu_Homes[mu_h].mu_LDir[mu_l];
bool mu__boolexpr48;
bool mu__boolexpr49;
  if (!((mu_h) == (mu_n))) mu__boolexpr49 = FALSE ;
  else {
  mu__boolexpr49 = (!(mu_nohome)) ; 
}
  if (!(mu__boolexpr49)) mu__boolexpr48 = FALSE ;
  else {
  mu__boolexpr48 = ((mu_LRAC.mu_State) == (mu_DGNTS)) ; 
}
  return mu__boolexpr48;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 250;
    static mu_1_Dir_Index mu_j;
    mu_j.value((r % 5) + 0);
    r = r / 5;
    static mu_1_LAddress mu_l;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.unionassign(r % 5);
    r = r / 5;
    while (what_rule < 275 )
      {
        if ( ( TRUE  ) ) {
  mu_1__type_7& mu_LRAC = mu_Procs[mu_n].mu_LRAC[mu_h][mu_l];
  mu_1__type_10& mu_ULRAC = mu_Procs[mu_n].mu_ULRAC[mu_h][mu_l];
  mu_1__type_4& mu_LCache = mu_Procs[mu_n].mu_LCache[mu_h][mu_l];
  mu_1__type_2& mu_LDir = mu_Homes[mu_h].mu_LDir[mu_l];
bool mu__boolexpr50;
bool mu__boolexpr51;
  if (!((mu_h) == (mu_n))) mu__boolexpr51 = FALSE ;
  else {
  mu__boolexpr51 = (!(mu_nohome)) ; 
}
  if (!(mu__boolexpr51)) mu__boolexpr50 = FALSE ;
  else {
  mu__boolexpr50 = ((mu_LRAC.mu_State) == (mu_DGNTS)) ; 
}
              if (mu__boolexpr50) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 5;
        }
        else
          what_rule += 5;
    r = what_rule - 250;
    mu_j.value((r % 5) + 0);
    r = r / 5;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    mu_n.unionassign(r % 5);
    r = r / 5;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Dir_Index mu_j;
    mu_j.value((r % 5) + 0);
    r = r / 5;
    static mu_1_LAddress mu_l;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.unionassign(r % 5);
    r = r / 5;
  mu_1__type_7& mu_LRAC = mu_Procs[mu_n].mu_LRAC[mu_h][mu_l];
  mu_1__type_10& mu_ULRAC = mu_Procs[mu_n].mu_ULRAC[mu_h][mu_l];
  mu_1__type_4& mu_LCache = mu_Procs[mu_n].mu_LCache[mu_h][mu_l];
  mu_1__type_2& mu_LDir = mu_Homes[mu_h].mu_LDir[mu_l];
if ( (mu_LCache.mu_State) == (mu_Locally_Shared) )
{
mu_LCache.mu_State = mu_Non_Locally_Cached;
}
switch ((int) mu_LDir.mu_State) {
case mu_Unlocked:
Error.Error("Error: release with Unlocked lock");
break;
case mu_Locked:
mu_LDir.mu_State = mu_Unlocked;
mu_LDir.mu_QueuedCount = 0;
mu_LDir.mu_Entries.undefine();
if ( (mu_LRAC.mu_Granting) == (mu_n) )
{
if ( !((mu_ULRAC.mu_State) == (mu_WDIRW)) ) Error.Error("Assertion failed: lock ack to funny ULRAC state");
mu_ULRAC.mu_State = mu_INVAL;
}
else
{
mu_Send_ACK_L ( mu_LRAC.mu_Granting, mu_n, mu_n, mu_l );
}
mu_LRAC.mu_State = mu_INVAL;
mu_LRAC.mu_Granting.undefine();
break;
case mu_Queued:
bool mu__boolexpr52;
  if (!((mu_j) < (mu_LDir.mu_QueuedCount))) mu__boolexpr52 = FALSE ;
  else {
  mu__boolexpr52 = ((mu_LDir.mu_Entries[mu_j]) != (mu_n)) ; 
}
if ( mu__boolexpr52 )
{
mu_Send_Grant_SET ( mu_LDir.mu_Entries[mu_j], mu_n, mu_LRAC.mu_Granting, mu_l );
mu_Remove_from_Queue ( mu_n, mu_l, mu_j );
mu_LRAC.mu_State = mu_INVAL;
mu_LRAC.mu_Granting.undefine();
}
break;
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase7 ********************/
class RuleBase7
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Dir_Index mu_j;
    mu_j.value((r % 5) + 0);
    r = r / 5;
    static mu_1_LAddress mu_l;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.unionassign(r % 5);
    r = r / 5;
    return tsprintf("Timeout at remote cluster -> Grant Rejected , j:%s, l:%s, h:%s, n:%s", mu_j.Name(), mu_l.Name(), mu_h.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Dir_Index mu_j;
    mu_j.value((r % 5) + 0);
    r = r / 5;
    static mu_1_LAddress mu_l;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.unionassign(r % 5);
    r = r / 5;
  mu_1__type_7& mu_LRAC = mu_Procs[mu_n].mu_LRAC[mu_h][mu_l];
  mu_1__type_10& mu_ULRAC = mu_Procs[mu_n].mu_ULRAC[mu_h][mu_l];
  mu_1__type_4& mu_LCache = mu_Procs[mu_n].mu_LCache[mu_h][mu_l];
  mu_1__type_2& mu_LDir = mu_Homes[mu_h].mu_LDir[mu_l];
bool mu__boolexpr53;
  if (!((mu_h) != (mu_n))) mu__boolexpr53 = FALSE ;
  else {
  mu__boolexpr53 = ((mu_LRAC.mu_State) == (mu_DGNTS)) ; 
}
  return mu__boolexpr53;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 275;
    static mu_1_Dir_Index mu_j;
    mu_j.value((r % 5) + 0);
    r = r / 5;
    static mu_1_LAddress mu_l;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.unionassign(r % 5);
    r = r / 5;
    while (what_rule < 300 )
      {
        if ( ( TRUE  ) ) {
  mu_1__type_7& mu_LRAC = mu_Procs[mu_n].mu_LRAC[mu_h][mu_l];
  mu_1__type_10& mu_ULRAC = mu_Procs[mu_n].mu_ULRAC[mu_h][mu_l];
  mu_1__type_4& mu_LCache = mu_Procs[mu_n].mu_LCache[mu_h][mu_l];
  mu_1__type_2& mu_LDir = mu_Homes[mu_h].mu_LDir[mu_l];
bool mu__boolexpr54;
  if (!((mu_h) != (mu_n))) mu__boolexpr54 = FALSE ;
  else {
  mu__boolexpr54 = ((mu_LRAC.mu_State) == (mu_DGNTS)) ; 
}
              if (mu__boolexpr54) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 5;
        }
        else
          what_rule += 5;
    r = what_rule - 275;
    mu_j.value((r % 5) + 0);
    r = r / 5;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    mu_n.unionassign(r % 5);
    r = r / 5;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Dir_Index mu_j;
    mu_j.value((r % 5) + 0);
    r = r / 5;
    static mu_1_LAddress mu_l;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.unionassign(r % 5);
    r = r / 5;
  mu_1__type_7& mu_LRAC = mu_Procs[mu_n].mu_LRAC[mu_h][mu_l];
  mu_1__type_10& mu_ULRAC = mu_Procs[mu_n].mu_ULRAC[mu_h][mu_l];
  mu_1__type_4& mu_LCache = mu_Procs[mu_n].mu_LCache[mu_h][mu_l];
  mu_1__type_2& mu_LDir = mu_Homes[mu_h].mu_LDir[mu_l];
if ( (mu_LCache.mu_State) == (mu_Locally_Shared) )
{
mu_LCache.mu_State = mu_Non_Locally_Cached;
}
mu_Send_Unlock ( (int)mu_h, mu_n, mu_LRAC.mu_Granting, mu_l );
mu_LRAC.mu_State = mu_INVAL;
mu_LRAC.mu_Granting.undefine();
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase8 ********************/
class RuleBase8
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_LAddress mu_l;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.unionassign(r % 5);
    r = r / 5;
    return tsprintf("Remote Lock Release, l:%s, h:%s, n:%s", mu_l.Name(), mu_h.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_LAddress mu_l;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.unionassign(r % 5);
    r = r / 5;
  mu_1__type_10& mu_ULRAC = mu_Procs[mu_n].mu_ULRAC[mu_h][mu_l];
  mu_1__type_4& mu_LCache = mu_Procs[mu_n].mu_LCache[mu_h][mu_l];
  mu_1__type_2& mu_LDir = mu_Homes[mu_h].mu_LDir[mu_l];
bool mu__boolexpr55;
bool mu__boolexpr56;
  if (!((mu_h) != (mu_n))) mu__boolexpr56 = FALSE ;
  else {
  mu__boolexpr56 = ((mu_LockOwner[mu_h][mu_l].mu_State) == (mu_Valid)) ; 
}
  if (!(mu__boolexpr56)) mu__boolexpr55 = FALSE ;
  else {
  mu__boolexpr55 = ((mu_LockOwner[mu_h][mu_l].mu_Proc) == (mu_n)) ; 
}
  return mu__boolexpr55;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 300;
    static mu_1_LAddress mu_l;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.unionassign(r % 5);
    r = r / 5;
    while (what_rule < 305 )
      {
        if ( ( TRUE  ) ) {
  mu_1__type_10& mu_ULRAC = mu_Procs[mu_n].mu_ULRAC[mu_h][mu_l];
  mu_1__type_4& mu_LCache = mu_Procs[mu_n].mu_LCache[mu_h][mu_l];
  mu_1__type_2& mu_LDir = mu_Homes[mu_h].mu_LDir[mu_l];
bool mu__boolexpr57;
bool mu__boolexpr58;
  if (!((mu_h) != (mu_n))) mu__boolexpr58 = FALSE ;
  else {
  mu__boolexpr58 = ((mu_LockOwner[mu_h][mu_l].mu_State) == (mu_Valid)) ; 
}
  if (!(mu__boolexpr58)) mu__boolexpr57 = FALSE ;
  else {
  mu__boolexpr57 = ((mu_LockOwner[mu_h][mu_l].mu_Proc) == (mu_n)) ; 
}
              if (mu__boolexpr57) {
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
    r = what_rule - 300;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    mu_n.unionassign(r % 5);
    r = r / 5;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_LAddress mu_l;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.unionassign(r % 5);
    r = r / 5;
  mu_1__type_10& mu_ULRAC = mu_Procs[mu_n].mu_ULRAC[mu_h][mu_l];
  mu_1__type_4& mu_LCache = mu_Procs[mu_n].mu_LCache[mu_h][mu_l];
  mu_1__type_2& mu_LDir = mu_Homes[mu_h].mu_LDir[mu_l];
switch ((int) mu_ULRAC.mu_State) {
case mu_INVAL:
mu_ULRAC.mu_State = mu_WDIRW;
mu_Send_Unlock ( (int)mu_h, mu_n, mu_n, mu_l );
mu_LockOwner[mu_h][mu_l].mu_State = mu_Invalid;
mu_LockOwner[mu_h][mu_l].mu_Proc.undefine();
break;
case mu_WDIRW:
break;
default:
Error.Error("Error: funny ULRAC with lock release action enbled");
break;
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase9 ********************/
class RuleBase9
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Dir_Index mu_j;
    mu_j.value((r % 5) + 0);
    r = r / 5;
    static mu_1_LAddress mu_l;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.unionassign(r % 5);
    r = r / 5;
    return tsprintf("Home Lock Release, j:%s, l:%s, h:%s, n:%s", mu_j.Name(), mu_l.Name(), mu_h.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Dir_Index mu_j;
    mu_j.value((r % 5) + 0);
    r = r / 5;
    static mu_1_LAddress mu_l;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.unionassign(r % 5);
    r = r / 5;
  mu_1__type_10& mu_ULRAC = mu_Procs[mu_n].mu_ULRAC[mu_h][mu_l];
  mu_1__type_4& mu_LCache = mu_Procs[mu_n].mu_LCache[mu_h][mu_l];
  mu_1__type_2& mu_LDir = mu_Homes[mu_h].mu_LDir[mu_l];
bool mu__boolexpr59;
bool mu__boolexpr60;
bool mu__boolexpr61;
  if (!((mu_h) == (mu_n))) mu__boolexpr61 = FALSE ;
  else {
  mu__boolexpr61 = (!(mu_nohome)) ; 
}
  if (!(mu__boolexpr61)) mu__boolexpr60 = FALSE ;
  else {
  mu__boolexpr60 = ((mu_LockOwner[mu_h][mu_l].mu_State) == (mu_Valid)) ; 
}
  if (!(mu__boolexpr60)) mu__boolexpr59 = FALSE ;
  else {
  mu__boolexpr59 = ((mu_LockOwner[mu_h][mu_l].mu_Proc) == (mu_n)) ; 
}
  return mu__boolexpr59;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 305;
    static mu_1_Dir_Index mu_j;
    mu_j.value((r % 5) + 0);
    r = r / 5;
    static mu_1_LAddress mu_l;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.unionassign(r % 5);
    r = r / 5;
    while (what_rule < 330 )
      {
        if ( ( TRUE  ) ) {
  mu_1__type_10& mu_ULRAC = mu_Procs[mu_n].mu_ULRAC[mu_h][mu_l];
  mu_1__type_4& mu_LCache = mu_Procs[mu_n].mu_LCache[mu_h][mu_l];
  mu_1__type_2& mu_LDir = mu_Homes[mu_h].mu_LDir[mu_l];
bool mu__boolexpr62;
bool mu__boolexpr63;
bool mu__boolexpr64;
  if (!((mu_h) == (mu_n))) mu__boolexpr64 = FALSE ;
  else {
  mu__boolexpr64 = (!(mu_nohome)) ; 
}
  if (!(mu__boolexpr64)) mu__boolexpr63 = FALSE ;
  else {
  mu__boolexpr63 = ((mu_LockOwner[mu_h][mu_l].mu_State) == (mu_Valid)) ; 
}
  if (!(mu__boolexpr63)) mu__boolexpr62 = FALSE ;
  else {
  mu__boolexpr62 = ((mu_LockOwner[mu_h][mu_l].mu_Proc) == (mu_n)) ; 
}
              if (mu__boolexpr62) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 5;
        }
        else
          what_rule += 5;
    r = what_rule - 305;
    mu_j.value((r % 5) + 0);
    r = r / 5;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    mu_n.unionassign(r % 5);
    r = r / 5;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Dir_Index mu_j;
    mu_j.value((r % 5) + 0);
    r = r / 5;
    static mu_1_LAddress mu_l;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.unionassign(r % 5);
    r = r / 5;
  mu_1__type_10& mu_ULRAC = mu_Procs[mu_n].mu_ULRAC[mu_h][mu_l];
  mu_1__type_4& mu_LCache = mu_Procs[mu_n].mu_LCache[mu_h][mu_l];
  mu_1__type_2& mu_LDir = mu_Homes[mu_h].mu_LDir[mu_l];
switch ((int) mu_ULRAC.mu_State) {
case mu_INVAL:
switch ((int) mu_LDir.mu_State) {
case mu_Unlocked:
Error.Error("Error: release with unlocked lock");
break;
case mu_Locked:
mu_LDir.mu_State = mu_Unlocked;
mu_LDir.mu_QueuedCount = 0;
mu_LDir.mu_Entries.undefine();
mu_LockOwner[mu_h][mu_l].mu_State = mu_Invalid;
mu_LockOwner[mu_h][mu_l].mu_Proc.undefine();
break;
case mu_Queued:
bool mu__boolexpr65;
  if (!((mu_j) < (mu_LDir.mu_QueuedCount))) mu__boolexpr65 = FALSE ;
  else {
  mu__boolexpr65 = ((mu_LDir.mu_Entries[mu_j]) != (mu_h)) ; 
}
if ( mu__boolexpr65 )
{
mu_ULRAC.mu_State = mu_WDIRW;
mu_Send_Grant_SET ( mu_LDir.mu_Entries[mu_j], (int)mu_h, (int)mu_h, mu_l );
mu_Remove_from_Queue ( mu_n, mu_l, mu_j );
mu_LockOwner[mu_h][mu_l].mu_State = mu_Invalid;
mu_LockOwner[mu_h][mu_l].mu_Proc.undefine();
}
break;
}
break;
case mu_WDIRW:
break;
default:
Error.Error("Error: funny ULRAC with lock release action enbled");
break;
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase10 ********************/
class RuleBase10
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_LAddress mu_l;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.unionassign(r % 5);
    r = r / 5;
    return tsprintf("Remote Lock Acquire, l:%s, h:%s, n:%s", mu_l.Name(), mu_h.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_LAddress mu_l;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.unionassign(r % 5);
    r = r / 5;
  mu_1__type_7& mu_LRAC = mu_Procs[mu_n].mu_LRAC[mu_h][mu_l];
  mu_1__type_10& mu_ULRAC = mu_Procs[mu_n].mu_ULRAC[mu_h][mu_l];
  mu_1__type_4& mu_LCache = mu_Procs[mu_n].mu_LCache[mu_h][mu_l];
  mu_1__type_2& mu_LDir = mu_Homes[mu_h].mu_LDir[mu_l];
bool mu__boolexpr66;
  if (!((mu_h) != (mu_n))) mu__boolexpr66 = FALSE ;
  else {
bool mu__boolexpr67;
  if (!((mu_LockOwner[mu_h][mu_l].mu_State) == (mu_Valid))) mu__boolexpr67 = FALSE ;
  else {
  mu__boolexpr67 = ((mu_LockOwner[mu_h][mu_l].mu_Proc) == (mu_n)) ; 
}
  mu__boolexpr66 = (!(mu__boolexpr67)) ; 
}
  return mu__boolexpr66;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 330;
    static mu_1_LAddress mu_l;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.unionassign(r % 5);
    r = r / 5;
    while (what_rule < 335 )
      {
        if ( ( TRUE  ) ) {
  mu_1__type_7& mu_LRAC = mu_Procs[mu_n].mu_LRAC[mu_h][mu_l];
  mu_1__type_10& mu_ULRAC = mu_Procs[mu_n].mu_ULRAC[mu_h][mu_l];
  mu_1__type_4& mu_LCache = mu_Procs[mu_n].mu_LCache[mu_h][mu_l];
  mu_1__type_2& mu_LDir = mu_Homes[mu_h].mu_LDir[mu_l];
bool mu__boolexpr68;
  if (!((mu_h) != (mu_n))) mu__boolexpr68 = FALSE ;
  else {
bool mu__boolexpr69;
  if (!((mu_LockOwner[mu_h][mu_l].mu_State) == (mu_Valid))) mu__boolexpr69 = FALSE ;
  else {
  mu__boolexpr69 = ((mu_LockOwner[mu_h][mu_l].mu_Proc) == (mu_n)) ; 
}
  mu__boolexpr68 = (!(mu__boolexpr69)) ; 
}
              if (mu__boolexpr68) {
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
    r = what_rule - 330;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    mu_n.unionassign(r % 5);
    r = r / 5;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_LAddress mu_l;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.unionassign(r % 5);
    r = r / 5;
  mu_1__type_7& mu_LRAC = mu_Procs[mu_n].mu_LRAC[mu_h][mu_l];
  mu_1__type_10& mu_ULRAC = mu_Procs[mu_n].mu_ULRAC[mu_h][mu_l];
  mu_1__type_4& mu_LCache = mu_Procs[mu_n].mu_LCache[mu_h][mu_l];
  mu_1__type_2& mu_LDir = mu_Homes[mu_h].mu_LDir[mu_l];
switch ((int) mu_LRAC.mu_State) {
case mu_INVAL:
switch ((int) mu_LCache.mu_State) {
case mu_Non_Locally_Cached:
mu_LRAC.mu_State = mu_WLCK;
mu_Send_RD_L ( (int)mu_h, mu_n, mu_l );
break;
case mu_Locally_Shared:
break;
}
break;
case mu_DLCK:
switch ((int) mu_LCache.mu_State) {
case mu_Non_Locally_Cached:
mu_LCache.mu_State = mu_Locally_Shared;
mu_LRAC.mu_State = mu_INVAL;
mu_LRAC.mu_Granting.undefine();
break;
case mu_Locally_Shared:
Error.Error("Error: DLCK with cached lock");
break;
}
break;
case mu_DULCK:
switch ((int) mu_LCache.mu_State) {
case mu_Non_Locally_Cached:
mu_Check_Mutual_Exclusion ( mu_h, mu_l );
mu_LockOwner[mu_h][mu_l].mu_State = mu_Valid;
mu_LockOwner[mu_h][mu_l].mu_Proc = mu_n;
mu_LRAC.mu_State = mu_INVAL;
mu_LRAC.mu_Granting.undefine();
break;
case mu_Locally_Shared:
Error.Error("Error: DULCK with cached lock");
break;
}
break;
case mu_DGNTS:
if ( (mu_LCache.mu_State) == (mu_Locally_Shared) )
{
mu_LCache.mu_State = mu_Non_Locally_Cached;
}
mu_Check_Mutual_Exclusion ( mu_h, mu_l );
mu_LockOwner[mu_h][mu_l].mu_State = mu_Valid;
mu_LockOwner[mu_h][mu_l].mu_Proc = mu_n;
mu_Send_ACK_L ( mu_LRAC.mu_Granting, mu_n, (int)mu_h, mu_l );
mu_LRAC.mu_State = mu_INVAL;
mu_LRAC.mu_Granting.undefine();
break;
case mu_WLCK:
switch ((int) mu_LCache.mu_State) {
case mu_Non_Locally_Cached:
break;
case mu_Locally_Shared:
Error.Error("Error: WLCK with cached lock");
break;
}
break;
case mu_RLCK:
switch ((int) mu_LCache.mu_State) {
case mu_Non_Locally_Cached:
break;
case mu_Locally_Shared:
Error.Error("Error: WLCK with cached lock");
break;
}
break;
default:
Error.Error("Error: funny LRAC state with lock request enabled.");
break;
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase11 ********************/
class RuleBase11
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_LAddress mu_l;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.unionassign(r % 5);
    r = r / 5;
    return tsprintf("Home Lock Acquire, l:%s, h:%s, n:%s", mu_l.Name(), mu_h.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_LAddress mu_l;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.unionassign(r % 5);
    r = r / 5;
  mu_1__type_7& mu_LRAC = mu_Procs[mu_n].mu_LRAC[mu_h][mu_l];
  mu_1__type_10& mu_ULRAC = mu_Procs[mu_n].mu_ULRAC[mu_h][mu_l];
  mu_1__type_4& mu_LCache = mu_Procs[mu_n].mu_LCache[mu_h][mu_l];
  mu_1__type_2& mu_LDir = mu_Homes[mu_h].mu_LDir[mu_l];
bool mu__boolexpr70;
bool mu__boolexpr71;
  if (!((mu_h) == (mu_n))) mu__boolexpr71 = FALSE ;
  else {
  mu__boolexpr71 = (!(mu_nohome)) ; 
}
  if (!(mu__boolexpr71)) mu__boolexpr70 = FALSE ;
  else {
bool mu__boolexpr72;
  if (!((mu_LockOwner[mu_h][mu_l].mu_State) == (mu_Valid))) mu__boolexpr72 = FALSE ;
  else {
  mu__boolexpr72 = ((mu_LockOwner[mu_h][mu_l].mu_Proc) == (mu_n)) ; 
}
  mu__boolexpr70 = (!(mu__boolexpr72)) ; 
}
  return mu__boolexpr70;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 335;
    static mu_1_LAddress mu_l;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.unionassign(r % 5);
    r = r / 5;
    while (what_rule < 340 )
      {
        if ( ( TRUE  ) ) {
  mu_1__type_7& mu_LRAC = mu_Procs[mu_n].mu_LRAC[mu_h][mu_l];
  mu_1__type_10& mu_ULRAC = mu_Procs[mu_n].mu_ULRAC[mu_h][mu_l];
  mu_1__type_4& mu_LCache = mu_Procs[mu_n].mu_LCache[mu_h][mu_l];
  mu_1__type_2& mu_LDir = mu_Homes[mu_h].mu_LDir[mu_l];
bool mu__boolexpr73;
bool mu__boolexpr74;
  if (!((mu_h) == (mu_n))) mu__boolexpr74 = FALSE ;
  else {
  mu__boolexpr74 = (!(mu_nohome)) ; 
}
  if (!(mu__boolexpr74)) mu__boolexpr73 = FALSE ;
  else {
bool mu__boolexpr75;
  if (!((mu_LockOwner[mu_h][mu_l].mu_State) == (mu_Valid))) mu__boolexpr75 = FALSE ;
  else {
  mu__boolexpr75 = ((mu_LockOwner[mu_h][mu_l].mu_Proc) == (mu_n)) ; 
}
  mu__boolexpr73 = (!(mu__boolexpr75)) ; 
}
              if (mu__boolexpr73) {
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
    r = what_rule - 335;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    mu_n.unionassign(r % 5);
    r = r / 5;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_LAddress mu_l;
    mu_l.value((r % 1) + 6);
    r = r / 1;
    static mu_1_Home mu_h;
    mu_h.value((r % 1) + 1);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.unionassign(r % 5);
    r = r / 5;
  mu_1__type_7& mu_LRAC = mu_Procs[mu_n].mu_LRAC[mu_h][mu_l];
  mu_1__type_10& mu_ULRAC = mu_Procs[mu_n].mu_ULRAC[mu_h][mu_l];
  mu_1__type_4& mu_LCache = mu_Procs[mu_n].mu_LCache[mu_h][mu_l];
  mu_1__type_2& mu_LDir = mu_Homes[mu_h].mu_LDir[mu_l];
switch ((int) mu_LRAC.mu_State) {
case mu_INVAL:
switch ((int) mu_LDir.mu_State) {
case mu_Unlocked:
switch ((int) mu_LCache.mu_State) {
case mu_Non_Locally_Cached:
mu_Check_Mutual_Exclusion ( mu_h, mu_l );
mu_LockOwner[mu_h][mu_l].mu_State = mu_Valid;
mu_LockOwner[mu_h][mu_l].mu_Proc = mu_n;
mu_LDir.mu_State = mu_Locked;
break;
case mu_Locally_Shared:
Error.Error("Error: inconsistent LDir and LCache");
break;
}
break;
default:
switch ((int) mu_LCache.mu_State) {
case mu_Non_Locally_Cached:
mu_LCache.mu_State = mu_Locally_Shared;
mu_LDir.mu_State = mu_Queued;
mu_Add_to_LDir_Entries ( (int)mu_h, mu_l, mu_n );
break;
case mu_Locally_Shared:
break;
}
break;
}
break;
case mu_DGNTS:
switch ((int) mu_LDir.mu_State) {
case mu_Unlocked:
Error.Error("Error: DGNTS with unlocked lock");
break;
default:
if ( (mu_LCache.mu_State) == (mu_Locally_Shared) )
{
mu_LCache.mu_State = mu_Non_Locally_Cached;
}
mu_Check_Mutual_Exclusion ( mu_h, mu_l );
mu_LockOwner[mu_h][mu_l].mu_State = mu_Valid;
mu_LockOwner[mu_h][mu_l].mu_Proc = mu_n;
if ( (mu_LRAC.mu_Granting) == (mu_h) )
{
if ( !((mu_ULRAC.mu_State) == (mu_WDIRW)) ) Error.Error("Assertion failed: lock ack to funny ULRAC state");
mu_ULRAC.mu_State = mu_INVAL;
}
else
{
mu_Send_ACK_L ( mu_LRAC.mu_Granting, mu_n, (int)mu_h, mu_l );
}
mu_LRAC.mu_State = mu_INVAL;
mu_LRAC.mu_Granting.undefine();
break;
}
break;
}
  };

  bool UnFair()
  { return FALSE; }
};
class NextStateGenerator
{
  RuleBase0 R0;
  RuleBase1 R1;
  RuleBase2 R2;
  RuleBase3 R3;
  RuleBase4 R4;
  RuleBase5 R5;
  RuleBase6 R6;
  RuleBase7 R7;
  RuleBase8 R8;
  RuleBase9 R9;
  RuleBase10 R10;
  RuleBase11 R11;
public:
void SetNextEnabledRule(unsigned & what_rule)
{
  category = CONDITION;
  if (what_rule<25)
    { R0.NextRule(what_rule);
      if (what_rule<25) return; }
  if (what_rule>=25 && what_rule<50)
    { R1.NextRule(what_rule);
      if (what_rule<50) return; }
  if (what_rule>=50 && what_rule<75)
    { R2.NextRule(what_rule);
      if (what_rule<75) return; }
  if (what_rule>=75 && what_rule<100)
    { R3.NextRule(what_rule);
      if (what_rule<100) return; }
  if (what_rule>=100 && what_rule<225)
    { R4.NextRule(what_rule);
      if (what_rule<225) return; }
  if (what_rule>=225 && what_rule<250)
    { R5.NextRule(what_rule);
      if (what_rule<250) return; }
  if (what_rule>=250 && what_rule<275)
    { R6.NextRule(what_rule);
      if (what_rule<275) return; }
  if (what_rule>=275 && what_rule<300)
    { R7.NextRule(what_rule);
      if (what_rule<300) return; }
  if (what_rule>=300 && what_rule<305)
    { R8.NextRule(what_rule);
      if (what_rule<305) return; }
  if (what_rule>=305 && what_rule<330)
    { R9.NextRule(what_rule);
      if (what_rule<330) return; }
  if (what_rule>=330 && what_rule<335)
    { R10.NextRule(what_rule);
      if (what_rule<335) return; }
  if (what_rule>=335 && what_rule<340)
    { R11.NextRule(what_rule);
      if (what_rule<340) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=24) return R0.Condition(r-0);
  if (r>=25 && r<=49) return R1.Condition(r-25);
  if (r>=50 && r<=74) return R2.Condition(r-50);
  if (r>=75 && r<=99) return R3.Condition(r-75);
  if (r>=100 && r<=224) return R4.Condition(r-100);
  if (r>=225 && r<=249) return R5.Condition(r-225);
  if (r>=250 && r<=274) return R6.Condition(r-250);
  if (r>=275 && r<=299) return R7.Condition(r-275);
  if (r>=300 && r<=304) return R8.Condition(r-300);
  if (r>=305 && r<=329) return R9.Condition(r-305);
  if (r>=330 && r<=334) return R10.Condition(r-330);
  if (r>=335 && r<=339) return R11.Condition(r-335);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
}
void Code(unsigned r)
{
  if (r<=24) { R0.Code(r-0); return; } 
  if (r>=25 && r<=49) { R1.Code(r-25); return; } 
  if (r>=50 && r<=74) { R2.Code(r-50); return; } 
  if (r>=75 && r<=99) { R3.Code(r-75); return; } 
  if (r>=100 && r<=224) { R4.Code(r-100); return; } 
  if (r>=225 && r<=249) { R5.Code(r-225); return; } 
  if (r>=250 && r<=274) { R6.Code(r-250); return; } 
  if (r>=275 && r<=299) { R7.Code(r-275); return; } 
  if (r>=300 && r<=304) { R8.Code(r-300); return; } 
  if (r>=305 && r<=329) { R9.Code(r-305); return; } 
  if (r>=330 && r<=334) { R10.Code(r-330); return; } 
  if (r>=335 && r<=339) { R11.Code(r-335); return; } 
}
int Priority(unsigned short r)
{
  if (r<=24) { return R0.Priority(); } 
  if (r>=25 && r<=49) { return R1.Priority(); } 
  if (r>=50 && r<=74) { return R2.Priority(); } 
  if (r>=75 && r<=99) { return R3.Priority(); } 
  if (r>=100 && r<=224) { return R4.Priority(); } 
  if (r>=225 && r<=249) { return R5.Priority(); } 
  if (r>=250 && r<=274) { return R6.Priority(); } 
  if (r>=275 && r<=299) { return R7.Priority(); } 
  if (r>=300 && r<=304) { return R8.Priority(); } 
  if (r>=305 && r<=329) { return R9.Priority(); } 
  if (r>=330 && r<=334) { return R10.Priority(); } 
  if (r>=335 && r<=339) { return R11.Priority(); } 
}
char * Name(unsigned r)
{
  if (r<=24) return R0.Name(r-0);
  if (r>=25 && r<=49) return R1.Name(r-25);
  if (r>=50 && r<=74) return R2.Name(r-50);
  if (r>=75 && r<=99) return R3.Name(r-75);
  if (r>=100 && r<=224) return R4.Name(r-100);
  if (r>=225 && r<=249) return R5.Name(r-225);
  if (r>=250 && r<=274) return R6.Name(r-250);
  if (r>=275 && r<=299) return R7.Name(r-275);
  if (r>=300 && r<=304) return R8.Name(r-300);
  if (r>=305 && r<=329) return R9.Name(r-305);
  if (r>=330 && r<=334) return R10.Name(r-330);
  if (r>=335 && r<=339) return R11.Name(r-335);
  return NULL;
}
};
const unsigned numrules = 340;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 340


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
{
for(int mu_h = 1; mu_h <= 1; mu_h++) {
{
for(int mu_l = 6; mu_l <= 6; mu_l++) {
mu_Homes[mu_h].mu_LDir[mu_l].mu_State = mu_Unlocked;
mu_Homes[mu_h].mu_LDir[mu_l].mu_QueuedCount = 0;
mu_Homes[mu_h].mu_LDir[mu_l].mu_Entries.undefine();
};
};
};
};
{
for(int mu_n = 1; mu_n <= 5; mu_n++)
  if (( ( mu_n >= 2 ) && ( mu_n <= 5 ) )|| ( ( mu_n >= 1 ) && ( mu_n <= 1 ) )) {
{
for(int mu_h = 1; mu_h <= 1; mu_h++) {
{
for(int mu_l = 6; mu_l <= 6; mu_l++) {
mu_Procs[mu_n].mu_LCache[mu_h][mu_l].mu_State = mu_Non_Locally_Cached;
mu_Procs[mu_n].mu_LRAC[mu_h][mu_l].mu_State = mu_INVAL;
mu_Procs[mu_n].mu_ULRAC[mu_h][mu_l].mu_State = mu_INVAL;
mu_Procs[mu_n].mu_LRAC[mu_h][mu_l].mu_Granting.undefine();
};
};
};
};
};
};
{
for(int mu_h = 1; mu_h <= 1; mu_h++) {
{
for(int mu_l = 6; mu_l <= 6; mu_l++) {
mu_LockOwner[mu_h][mu_l].mu_State = mu_Invalid;
mu_LockOwner[mu_h][mu_l].mu_Proc.undefine();
};
};
};
};
{
for(int mu_Dst = 1; mu_Dst <= 5; mu_Dst++)
  if (( ( mu_Dst >= 2 ) && ( mu_Dst <= 5 ) )|| ( ( mu_Dst >= 1 ) && ( mu_Dst <= 1 ) )) {
{
for(int mu_Src = 1; mu_Src <= 5; mu_Src++)
  if (( ( mu_Src >= 2 ) && ( mu_Src <= 5 ) )|| ( ( mu_Src >= 1 ) && ( mu_Src <= 1 ) )) {
mu_ReqNet[mu_Src][mu_Dst].mu_Count = 0;
mu_ReqNet[mu_Src][mu_Dst].mu_Messages.undefine();
mu_ReplyNet[mu_Src][mu_Dst].mu_Count = 0;
mu_ReplyNet[mu_Src][mu_Dst].mu_Messages.undefine();
};
};
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
int mu__invariant_76() // Invariant "Irrelevant queue members are set to zero"
{
bool mu__quant77; 
mu__quant77 = TRUE;
{
for(int mu_h = 1; mu_h <= 1; mu_h++) {
bool mu__quant78; 
mu__quant78 = TRUE;
{
for(int mu_l = 6; mu_l <= 6; mu_l++) {
bool mu__boolexpr79;
bool mu__boolexpr80;
  if ((mu_Homes[mu_h].mu_LDir[mu_l].mu_State) == (mu_Queued)) mu__boolexpr80 = TRUE ;
  else {
  mu__boolexpr80 = ((mu_Homes[mu_h].mu_LDir[mu_l].mu_QueuedCount) == (0)) ; 
}
  if (!(mu__boolexpr80)) mu__boolexpr79 = FALSE ;
  else {
bool mu__quant81; 
mu__quant81 = TRUE;
{
for(int mu_i = 0; mu_i <= 4; mu_i++) {
bool mu__boolexpr82;
  if (!((mu_i) >= (mu_Homes[mu_h].mu_LDir[mu_l].mu_QueuedCount))) mu__boolexpr82 = TRUE ;
  else {
  mu__boolexpr82 = (mu_Homes[mu_h].mu_LDir[mu_l].mu_Entries[mu_i].isundefined()) ; 
}
if ( !(mu__boolexpr82) )
  { mu__quant81 = FALSE; break; }
};
};
  mu__boolexpr79 = (mu__quant81) ; 
}
if ( !(mu__boolexpr79) )
  { mu__quant78 = FALSE; break; }
};
};
if ( !(mu__quant78) )
  { mu__quant77 = FALSE; break; }
};
};
return mu__quant77;
};

bool mu__condition_83() // Condition for Rule "Irrelevant queue members are set to zero"
{
  return mu__invariant_76( );
}

/**** end rule declaration ****/

int mu__invariant_84() // Invariant "Correct lock queue"
{
bool mu__quant85; 
mu__quant85 = TRUE;
{
for(int mu_h = 1; mu_h <= 1; mu_h++) {
bool mu__quant86; 
mu__quant86 = TRUE;
{
for(int mu_l = 6; mu_l <= 6; mu_l++) {
bool mu__quant87; 
mu__quant87 = TRUE;
{
for(int mu_j = 0; mu_j <= 4; mu_j++) {
bool mu__quant88; 
mu__quant88 = TRUE;
{
for(int mu_n = 1; mu_n <= 5; mu_n++)
  if (( ( mu_n >= 2 ) && ( mu_n <= 5 ) )|| ( ( mu_n >= 1 ) && ( mu_n <= 1 ) )) {
bool mu__boolexpr89;
bool mu__boolexpr90;
bool mu__boolexpr91;
  if (!((mu_Homes[mu_h].mu_LDir[mu_l].mu_State) == (mu_Queued))) mu__boolexpr91 = FALSE ;
  else {
  mu__boolexpr91 = ((mu_j) < (mu_Homes[mu_h].mu_LDir[mu_l].mu_QueuedCount)) ; 
}
  if (!(mu__boolexpr91)) mu__boolexpr90 = FALSE ;
  else {
  mu__boolexpr90 = ((mu_Homes[mu_h].mu_LDir[mu_l].mu_Entries[mu_j]) == (mu_n)) ; 
}
  if (!(mu__boolexpr90)) mu__boolexpr89 = TRUE ;
  else {
bool mu__boolexpr92;
bool mu__boolexpr93;
  if ((mu_Procs[mu_n].mu_LCache[mu_h][mu_l].mu_State) == (mu_Locally_Shared)) mu__boolexpr93 = TRUE ;
  else {
  mu__boolexpr93 = ((mu_Procs[mu_n].mu_LRAC[mu_h][mu_l].mu_State) == (mu_DLCK)) ; 
}
  if (mu__boolexpr93) mu__boolexpr92 = TRUE ;
  else {
bool mu__quant94; 
mu__quant94 = FALSE;
{
for(int mu_i = 0; mu_i <= 2; mu_i++) {
bool mu__boolexpr95;
  if (!((mu_i) < (mu_ReplyNet[mu_h][mu_n].mu_Count))) mu__boolexpr95 = FALSE ;
  else {
  mu__boolexpr95 = ((mu_ReplyNet[mu_h][mu_n].mu_Messages[mu_i].mu_Mtype) == (mu_LCK)) ; 
}
if ( (mu__boolexpr95) )
  { mu__quant94 = TRUE; break; }
};
};
  mu__boolexpr92 = (mu__quant94) ; 
}
  mu__boolexpr89 = (mu__boolexpr92) ; 
}
if ( !(mu__boolexpr89) )
  { mu__quant88 = FALSE; break; }
};
};
if ( !(mu__quant88) )
  { mu__quant87 = FALSE; break; }
};
};
if ( !(mu__quant87) )
  { mu__quant86 = FALSE; break; }
};
};
if ( !(mu__quant86) )
  { mu__quant85 = FALSE; break; }
};
};
return mu__quant85;
};

bool mu__condition_96() // Condition for Rule "Correct lock queue"
{
  return mu__invariant_84( );
}

/**** end rule declaration ****/

int mu__invariant_97() // Invariant "Correct lock state -> backward"
{
bool mu__quant98; 
mu__quant98 = TRUE;
{
for(int mu_h = 1; mu_h <= 1; mu_h++) {
bool mu__quant99; 
mu__quant99 = TRUE;
{
for(int mu_l = 6; mu_l <= 6; mu_l++) {
bool mu__boolexpr100;
bool mu__boolexpr101;
  if ((mu_Homes[mu_h].mu_LDir[mu_l].mu_State) == (mu_Locked)) mu__boolexpr101 = TRUE ;
  else {
  mu__boolexpr101 = ((mu_Homes[mu_h].mu_LDir[mu_l].mu_State) == (mu_Queued)) ; 
}
  if (!(mu__boolexpr101)) mu__boolexpr100 = TRUE ;
  else {
bool mu__boolexpr102;
bool mu__boolexpr103;
  if ((mu_LockOwner[mu_h][mu_l].mu_State) == (mu_Valid)) mu__boolexpr103 = TRUE ;
  else {
bool mu__quant104; 
mu__quant104 = FALSE;
{
for(int mu_n = 1; mu_n <= 5; mu_n++)
  if (( ( mu_n >= 2 ) && ( mu_n <= 5 ) )|| ( ( mu_n >= 1 ) && ( mu_n <= 1 ) )) {
bool mu__boolexpr105;
  if ((mu_Procs[mu_n].mu_LRAC[mu_h][mu_l].mu_State) == (mu_DULCK)) mu__boolexpr105 = TRUE ;
  else {
  mu__boolexpr105 = ((mu_Procs[mu_n].mu_LRAC[mu_h][mu_l].mu_State) == (mu_DGNTS)) ; 
}
if ( (mu__boolexpr105) )
  { mu__quant104 = TRUE; break; }
};
};
  mu__boolexpr103 = (mu__quant104) ; 
}
  if (mu__boolexpr103) mu__boolexpr102 = TRUE ;
  else {
bool mu__quant106; 
mu__quant106 = FALSE;
{
for(int mu_n = 1; mu_n <= 5; mu_n++)
  if (( ( mu_n >= 2 ) && ( mu_n <= 5 ) )|| ( ( mu_n >= 1 ) && ( mu_n <= 1 ) )) {
bool mu__quant107; 
mu__quant107 = FALSE;
{
for(int mu_i = 0; mu_i <= 2; mu_i++) {
bool mu__boolexpr108;
bool mu__boolexpr109;
bool mu__boolexpr110;
  if (!((mu_i) < (mu_ReplyNet[mu_h][mu_n].mu_Count))) mu__boolexpr110 = FALSE ;
  else {
  mu__boolexpr110 = ((mu_ReplyNet[mu_h][mu_n].mu_Messages[mu_i].mu_Mtype) == (mu_UNLCK)) ; 
}
  if (mu__boolexpr110) mu__boolexpr109 = TRUE ;
  else {
bool mu__boolexpr111;
  if (!((mu_i) < (mu_ReqNet[mu_n][mu_h].mu_Count))) mu__boolexpr111 = FALSE ;
  else {
  mu__boolexpr111 = ((mu_ReqNet[mu_n][mu_h].mu_Messages[mu_i].mu_Mtype) == (mu_IOWR)) ; 
}
  mu__boolexpr109 = (mu__boolexpr111) ; 
}
  if (mu__boolexpr109) mu__boolexpr108 = TRUE ;
  else {
bool mu__boolexpr112;
  if (!((mu_i) < (mu_ReqNet[mu_h][mu_n].mu_Count))) mu__boolexpr112 = FALSE ;
  else {
  mu__boolexpr112 = ((mu_ReqNet[mu_h][mu_n].mu_Messages[mu_i].mu_Mtype) == (mu_GSET)) ; 
}
  mu__boolexpr108 = (mu__boolexpr112) ; 
}
if ( (mu__boolexpr108) )
  { mu__quant107 = TRUE; break; }
};
};
if ( (mu__quant107) )
  { mu__quant106 = TRUE; break; }
};
};
  mu__boolexpr102 = (mu__quant106) ; 
}
  mu__boolexpr100 = (mu__boolexpr102) ; 
}
if ( !(mu__boolexpr100) )
  { mu__quant99 = FALSE; break; }
};
};
if ( !(mu__quant99) )
  { mu__quant98 = FALSE; break; }
};
};
return mu__quant98;
};

bool mu__condition_113() // Condition for Rule "Correct lock state -> backward"
{
  return mu__invariant_97( );
}

/**** end rule declaration ****/

int mu__invariant_114() // Invariant "Correct lock state -> forward"
{
bool mu__quant115; 
mu__quant115 = TRUE;
{
for(int mu_h = 1; mu_h <= 1; mu_h++) {
bool mu__quant116; 
mu__quant116 = TRUE;
{
for(int mu_l = 6; mu_l <= 6; mu_l++) {
bool mu__boolexpr117;
  if (!((mu_LockOwner[mu_h][mu_l].mu_State) == (mu_Valid))) mu__boolexpr117 = TRUE ;
  else {
bool mu__boolexpr118;
  if ((mu_Homes[mu_h].mu_LDir[mu_l].mu_State) == (mu_Locked)) mu__boolexpr118 = TRUE ;
  else {
  mu__boolexpr118 = ((mu_Homes[mu_h].mu_LDir[mu_l].mu_State) == (mu_Queued)) ; 
}
  mu__boolexpr117 = (mu__boolexpr118) ; 
}
if ( !(mu__boolexpr117) )
  { mu__quant116 = FALSE; break; }
};
};
if ( !(mu__quant116) )
  { mu__quant115 = FALSE; break; }
};
};
return mu__quant115;
};

bool mu__condition_119() // Condition for Rule "Correct lock state -> forward"
{
  return mu__invariant_114( );
}

/**** end rule declaration ****/

const rulerec invariants[] = {
{"Correct lock state -> forward", &mu__condition_119, NULL, FALSE},
{"Correct lock state -> backward", &mu__condition_113, NULL, FALSE},
{"Correct lock queue", &mu__condition_96, NULL, FALSE},
{"Irrelevant queue members are set to zero", &mu__condition_83, NULL, FALSE},
};
const unsigned short numinvariants = 4;

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
Homes:ScalarsetVariable
LockOwner:ScalarsetVariable
Procs:ScalarsetArrayOfScalarset
ReplyNet:Complex
ReqNet:Complex
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
  int class_mu_1_Remote[4];
  int undefined_class_mu_1_Remote;// has the highest class number

  void Print_class_mu_1_Remote();
  bool OnlyOneRemain_mu_1_Remote;
  bool MTO_class_mu_1_Remote()
  {
    int i,j;
    if (OnlyOneRemain_mu_1_Remote)
      return FALSE;
    for (i=0; i<4; i++)
      for (j=0; j<4; j++)
        if (i!=j && class_mu_1_Remote[i]== class_mu_1_Remote[j])
	    return TRUE;
    OnlyOneRemain_mu_1_Remote = TRUE;
    return FALSE;
  }
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
  int * in_mu_1_Remote;
  typedef int arr_mu_1_Remote[4];
  arr_mu_1_Remote * perm_mu_1_Remote;
  arr_mu_1_Remote * revperm_mu_1_Remote;

  int size_mu_1_Remote[4];
  bool reversed_sorted_mu_1_Remote(int start, int end);
  void reverse_reversed_mu_1_Remote(int start, int end);

  // procedure for explicit representation
  bool ok0(mu_1_Remote* perm, int size, mu_1_Remote k);
  void GenPerm0(mu_1_Remote* perm, int size, unsigned long& index);

  // General procedure
  PermSet();
  bool In(int i) const { return in[i]; };
  void Add(int i) { for (int j=0; j<i; j++) in[j] = FALSE;};
  void Remove(int i) { in[i] = FALSE; };
};
void PermSet::Print_class_mu_1_Remote()
{
  cout << "class_mu_1_Remote:\t";
  for (int i=0; i<4; i++)
    cout << class_mu_1_Remote[i];
  cout << " " << undefined_class_mu_1_Remote << "\n";
}
bool PermSet::MoreThanOneRemain()
{
  int i,j;
  if (AlreadyOnlyOneRemain)
    return FALSE;
  else {
    for (i=0; i<4; i++)
      for (j=0; j<4; j++)
        if (i!=j && class_mu_1_Remote[i]== class_mu_1_Remote[j])
	    return TRUE;
  }
  AlreadyOnlyOneRemain = TRUE;
  return FALSE;
}
PermSet::PermSet()
: Presentation(Simple)
{
  int i,j,k;
  if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize
     || args->sym_alg.mode == argsym_alg::Heuristic_Fast_Canonicalize) {
    mu_1_Remote Perm0[4];

  /********************
   declaration of class variables
  ********************/
  in = new bool[24];
 in_mu_1_Remote = new int[24];
 perm_mu_1_Remote = new arr_mu_1_Remote[24];
 revperm_mu_1_Remote = new arr_mu_1_Remote[24];

    // Set perm and revperm
    count = 0;
    for (i=2; i<=5; i++)
      {
        Perm0[0].value(i);
        GenPerm0(Perm0, 1, count);
      }
    if (count!=24)
      Error.Error( "unable to initialize PermSet");
    for (i=0; i<24; i++)
      for (j=2; j<=5; j++)
        for (k=2; k<=5; k++)
          if (revperm_mu_1_Remote[i][k-2]==j)   // k - base 
            perm_mu_1_Remote[i][j-2]=k; // j - base 

    // setting up combination of permutations
    // for different scalarset
    int carry;
    int i_mu_1_Remote = 0;
    size = 24;
    count = 24;
    for (i=0; i<24; i++)
      {
        carry = 1;
        in[i]= TRUE;
      in_mu_1_Remote[i] = i_mu_1_Remote;
      i_mu_1_Remote += carry;
      if (i_mu_1_Remote >= 24) { i_mu_1_Remote = 0; carry = 1; } 
      else { carry = 0; } 
    }
  }
  else
  {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];
 in_mu_1_Remote = new int[1];
 perm_mu_1_Remote = new arr_mu_1_Remote[1];
 revperm_mu_1_Remote = new arr_mu_1_Remote[1];
  in[0] = TRUE;
    in_mu_1_Remote[0] = 0;
  }
}
void PermSet::ResetToSimple()
{
  int i;
  for (i=0; i<4; i++)
    class_mu_1_Remote[i]=0;
  undefined_class_mu_1_Remote=0;
  OnlyOneRemain_mu_1_Remote = FALSE;

  AlreadyOnlyOneRemain = FALSE;
  Presentation = Simple;
}
void PermSet::ResetToExplicit()
{
  for (int i=0; i<24; i++) in[i] = TRUE;
  Presentation = Explicit;
}
void PermSet::SimpleToExplicit()
{
  int i,j,k;
  int start, class_size;
  int start_mu_1_Remote[4];
  int size_mu_1_Remote[4];
  bool should_be_in_mu_1_Remote[24];

  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Remote; j++) // class number
    {
      class_size = 0;
      for (k=0; k<4; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Remote[k]==j)
	  class_size++;
      for (k=0; k<4; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Remote[k]==j)
	  {
	    size_mu_1_Remote[k] = class_size;
	    start_mu_1_Remote[k] = start;
	  }
      start+=class_size;
    }

  // To be In or not to be
  for (i=0; i<24; i++) // set up
    should_be_in_mu_1_Remote[i] = TRUE;
  for (i=0; i<24; i++) // to be in or not to be
    for (k=0; k<4; k++) // step through class_mu_1_pid[k]
      if (! (perm_mu_1_Remote[i][k]-2 >=start_mu_1_Remote[k] 
	     && perm_mu_1_Remote[i][k]-2 < start_mu_1_Remote[k] + size_mu_1_Remote[k]) )
  	    {
	      should_be_in_mu_1_Remote[i] = FALSE;
	      break;
	    }

  // setup explicit representation 
  // Set perm and revperm
  for (i=0; i<24; i++)
    {
      in[i] = TRUE;
      if (in[i] && !should_be_in_mu_1_Remote[in_mu_1_Remote[i]]) in[i] = FALSE;
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
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Remote; j++) // class number
    {
      class_size = 0;
      for (k=0; k<4; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Remote[k]==j)
	  class_size++;
      for (k=0; k<4; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Remote[k]==j)
	  {
	    size_mu_1_Remote[k] = class_size;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Remote; j++) // class number
    {
      for (k=0; k<4; k++) // step through class_mu_1_pid[k]
	    if (class_mu_1_Remote[k]==j)
	      revperm_mu_1_Remote[0][start++] = k+2;
    }
  for (j=0; j<4; j++)
    for (k=0; k<4; k++)
      if (revperm_mu_1_Remote[0][k]==j+2)
        perm_mu_1_Remote[0][j]=k+2;
  Presentation = Explicit;
}
bool PermSet::ok0(mu_1_Remote* Perm, int size, mu_1_Remote k)
{
  for (int i=0; i<size; i++)
    if(Perm[i].value()==k)
      return FALSE;
  return TRUE;
}
void PermSet::GenPerm0(mu_1_Remote* Perm,int size, unsigned long& count)
{
  int i;
  if (size!=4)
    {
      for (i=2; i<=5; i++)
        if(ok0(Perm,size,i))
          {
            Perm[size].value(i);
            GenPerm0(Perm, size+1, count);
          }
    }
  else
    {
      for (i=2; i<=5; i++)
        revperm_mu_1_Remote[count][i-2]=Perm[i-2].value();// i - base
      count++;
    }
}
bool PermSet::reversed_sorted_mu_1_Remote(int start, int end)
{
  int i,j;

  for (i=start; i<end; i++)
    if (revperm_mu_1_Remote[0][i]<revperm_mu_1_Remote[0][i+1])
      return FALSE;
  return TRUE;
}
void PermSet::reverse_reversed_mu_1_Remote(int start, int end)
{
  int i,j;
  int temp;

  for (i=start, j=end; i<j; i++,j--) 
    {
      temp = revperm_mu_1_Remote[0][j];
      revperm_mu_1_Remote[0][j] = revperm_mu_1_Remote[0][i];
      revperm_mu_1_Remote[0][i] = temp;
    }
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
  for (start = 0; start < 4; )
    {
      end = start-1+size_mu_1_Remote[revperm_mu_1_Remote[0][start]-2];
      if (reversed_sorted_mu_1_Remote(start,end))
	       {
	  reverse_reversed_mu_1_Remote(start,end);
	  start = end+1;
	}
      else
	{
	  nexted = TRUE;
	  for (j = start; j<end; j++)
	    {
	      if (reversed_sorted_mu_1_Remote(j+1,end))
		{
		  for (k = end; k>j; k--)
		    {
		      if (revperm_mu_1_Remote[0][j]<revperm_mu_1_Remote[0][k])
			{
			  // swap j, k
			  temp = revperm_mu_1_Remote[0][j];
			  revperm_mu_1_Remote[0][j] = revperm_mu_1_Remote[0][k];
			  revperm_mu_1_Remote[0][k] = temp;
			  break;
			}
		    }
		  reverse_reversed_mu_1_Remote(j+1,end);
		  break;
		}
	    }
	  break;
	}
    }
if (!nexted) return FALSE;
  for (j=0; j<4; j++)
    for (k=0; k<4; k++)
      if (revperm_mu_1_Remote[0][k]==j+2)   // k - base 
	perm_mu_1_Remote[0][j]=k+2; // j - base 
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
        mu_Homes.MultisetSort();
        mu_LockOwner.MultisetSort();
        mu_Procs.MultisetSort();
        mu_ReplyNet.MultisetSort();
        mu_ReqNet.MultisetSort();
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
void mu_1_Home::Permute(PermSet& Perm, int i) {}
void mu_1_Home::SimpleCanonicalize(PermSet& Perm) {}
void mu_1_Home::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_Home::SimpleLimit(PermSet& Perm) {}
void mu_1_Home::ArrayLimit(PermSet& Perm) {}
void mu_1_Home::Limit(PermSet& Perm) {}
void mu_1_Home::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
void mu_1_Remote::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined())
    value(Perm.perm_mu_1_Remote[Perm.in_mu_1_Remote[i]][value()-2]); // value - base
};
void mu_1_Remote::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_Remote[value()-2]==Perm.undefined_class_mu_1_Remote) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<4; i++)
          if (Perm.class_mu_1_Remote[i] == Perm.undefined_class_mu_1_Remote && i!=value()-2)
            Perm.class_mu_1_Remote[i]++;
        value(2 + Perm.undefined_class_mu_1_Remote++);
      }
    else 
      {
        value(Perm.class_mu_1_Remote[value()-2]+2);
      }
}
void mu_1_Remote::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_Remote::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_Remote[value()-2]==Perm.undefined_class_mu_1_Remote) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<4; i++)
          if (Perm.class_mu_1_Remote[i] == Perm.undefined_class_mu_1_Remote && i!=value()-2)
            Perm.class_mu_1_Remote[i]++;
        Perm.undefined_class_mu_1_Remote++;
      }
}
void mu_1_Remote::ArrayLimit(PermSet& Perm) {}
void mu_1_Remote::Limit(PermSet& Perm) {}
void mu_1_Remote::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
void mu_1_Proc::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 2 ) && ( value() <= 5 ) )
      value(Perm.perm_mu_1_Remote[Perm.in_mu_1_Remote[i]][value()-2]+(0)); // value - base
  }
}
void mu_1_Proc::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 2 ) && ( value() <= 5 ) )
      {
        if (Perm.class_mu_1_Remote[value()-2]==Perm.undefined_class_mu_1_Remote) // value - base
          {
            // it has not been mapped to any particular value
            for (i=0; i<4; i++)
              if (Perm.class_mu_1_Remote[i] == Perm.undefined_class_mu_1_Remote && i!=value()-2)
                Perm.class_mu_1_Remote[i]++;
            value(2 + Perm.undefined_class_mu_1_Remote++);
          }
        else 
          {
            value(Perm.class_mu_1_Remote[value()-2]+2);
          }
      }
  }
}
void mu_1_Proc::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_Proc::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 2 ) && ( value() <= 5 ) )
      if (Perm.class_mu_1_Remote[value()-2]==Perm.undefined_class_mu_1_Remote) // value - base
        {
          // it has not been mapped to any particular value
          for (i=0; i<4; i++)
            if (Perm.class_mu_1_Remote[i] == Perm.undefined_class_mu_1_Remote && i!=value()-2)
              Perm.class_mu_1_Remote[i]++;
          Perm.undefined_class_mu_1_Remote++;
        }
  }
}
void mu_1_Proc::ArrayLimit(PermSet& Perm) {}
void mu_1_Proc::Limit(PermSet& Perm) {}
void mu_1_Proc::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for union type.\n"); };
void mu_1_LAddress::Permute(PermSet& Perm, int i) {}
void mu_1_LAddress::SimpleCanonicalize(PermSet& Perm) {}
void mu_1_LAddress::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_LAddress::SimpleLimit(PermSet& Perm) {}
void mu_1_LAddress::ArrayLimit(PermSet& Perm) {}
void mu_1_LAddress::Limit(PermSet& Perm) {}
void mu_1_LAddress::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
void mu_1_Dir_Index::Permute(PermSet& Perm, int i) {};
void mu_1_Dir_Index::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_Dir_Index::Canonicalize(PermSet& Perm) {};
void mu_1_Dir_Index::SimpleLimit(PermSet& Perm) {};
void mu_1_Dir_Index::ArrayLimit(PermSet& Perm) {};
void mu_1_Dir_Index::Limit(PermSet& Perm) {};
void mu_1_Dir_Index::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_Request_Type::Permute(PermSet& Perm, int i) {};
void mu_1_Request_Type::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_Request_Type::Canonicalize(PermSet& Perm) {};
void mu_1_Request_Type::SimpleLimit(PermSet& Perm) {};
void mu_1_Request_Type::ArrayLimit(PermSet& Perm) {};
void mu_1_Request_Type::Limit(PermSet& Perm) {};
void mu_1_Request_Type::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_Reply_Type::Permute(PermSet& Perm, int i) {};
void mu_1_Reply_Type::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_Reply_Type::Canonicalize(PermSet& Perm) {};
void mu_1_Reply_Type::SimpleLimit(PermSet& Perm) {};
void mu_1_Reply_Type::ArrayLimit(PermSet& Perm) {};
void mu_1_Reply_Type::Limit(PermSet& Perm) {};
void mu_1_Reply_Type::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_Request::Permute(PermSet& Perm, int i)
{
  mu_Aux.Permute(Perm,i);
};
void mu_1_Request::SimpleCanonicalize(PermSet& Perm)
{
  mu_Aux.SimpleCanonicalize(Perm);
};
void mu_1_Request::Canonicalize(PermSet& Perm)
{
};
void mu_1_Request::SimpleLimit(PermSet& Perm)
{
  mu_Aux.SimpleLimit(Perm);
};
void mu_1_Request::ArrayLimit(PermSet& Perm){}
void mu_1_Request::Limit(PermSet& Perm)
{
};
void mu_1_Request::MultisetLimit(PermSet& Perm)
{
};
void mu_1_Reply::Permute(PermSet& Perm, int i)
{
  mu_Aux.Permute(Perm,i);
};
void mu_1_Reply::SimpleCanonicalize(PermSet& Perm)
{
  mu_Aux.SimpleCanonicalize(Perm);
};
void mu_1_Reply::Canonicalize(PermSet& Perm)
{
};
void mu_1_Reply::SimpleLimit(PermSet& Perm)
{
  mu_Aux.SimpleLimit(Perm);
};
void mu_1_Reply::ArrayLimit(PermSet& Perm){}
void mu_1_Reply::Limit(PermSet& Perm)
{
};
void mu_1_Reply::MultisetLimit(PermSet& Perm)
{
};
void mu_1_RAC_State::Permute(PermSet& Perm, int i) {};
void mu_1_RAC_State::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_RAC_State::Canonicalize(PermSet& Perm) {};
void mu_1_RAC_State::SimpleLimit(PermSet& Perm) {};
void mu_1_RAC_State::ArrayLimit(PermSet& Perm) {};
void mu_1_RAC_State::Limit(PermSet& Perm) {};
void mu_1_RAC_State::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_Cache_State::Permute(PermSet& Perm, int i) {};
void mu_1_Cache_State::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_Cache_State::Canonicalize(PermSet& Perm) {};
void mu_1_Cache_State::SimpleLimit(PermSet& Perm) {};
void mu_1_Cache_State::ArrayLimit(PermSet& Perm) {};
void mu_1_Cache_State::Limit(PermSet& Perm) {};
void mu_1_Cache_State::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1__type_0::Permute(PermSet& Perm, int i) {};
void mu_1__type_0::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_0::Canonicalize(PermSet& Perm) {};
void mu_1__type_0::SimpleLimit(PermSet& Perm) {};
void mu_1__type_0::ArrayLimit(PermSet& Perm) {};
void mu_1__type_0::Limit(PermSet& Perm) {};
void mu_1__type_0::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1__type_1::Permute(PermSet& Perm, int i)
{
  static mu_1__type_1 temp("Permute_mu_1__type_1",-1);
  int j;
  for (j=0; j<5; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_1::SimpleCanonicalize(PermSet& Perm)
{
  for (int j=0; j<5; j++)
    array[j].SimpleCanonicalize(Perm);
}
void mu_1__type_1::Canonicalize(PermSet& Perm){};
void mu_1__type_1::SimpleLimit(PermSet& Perm)
{
  for (int j=0; j<5; j++) {
    array[j].SimpleLimit(Perm);
  }
}
void mu_1__type_1::ArrayLimit(PermSet& Perm) {}
void mu_1__type_1::Limit(PermSet& Perm){}
void mu_1__type_1::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_2::Permute(PermSet& Perm, int i)
{
  mu_Entries.Permute(Perm,i);
};
void mu_1__type_2::SimpleCanonicalize(PermSet& Perm)
{
  mu_Entries.SimpleCanonicalize(Perm);
};
void mu_1__type_2::Canonicalize(PermSet& Perm)
{
};
void mu_1__type_2::SimpleLimit(PermSet& Perm)
{
  mu_Entries.SimpleLimit(Perm);
};
void mu_1__type_2::ArrayLimit(PermSet& Perm){}
void mu_1__type_2::Limit(PermSet& Perm)
{
};
void mu_1__type_2::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_3::Permute(PermSet& Perm, int i)
{
  static mu_1__type_3 temp("Permute_mu_1__type_3",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_3::SimpleCanonicalize(PermSet& Perm)
{
  for (int j=0; j<1; j++)
    array[j].SimpleCanonicalize(Perm);
}
void mu_1__type_3::Canonicalize(PermSet& Perm){};
void mu_1__type_3::SimpleLimit(PermSet& Perm)
{
  for (int j=0; j<1; j++) {
    array[j].SimpleLimit(Perm);
  }
}
void mu_1__type_3::ArrayLimit(PermSet& Perm) {}
void mu_1__type_3::Limit(PermSet& Perm){}
void mu_1__type_3::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1_HomeState::Permute(PermSet& Perm, int i)
{
  mu_LDir.Permute(Perm,i);
};
void mu_1_HomeState::SimpleCanonicalize(PermSet& Perm)
{
  mu_LDir.SimpleCanonicalize(Perm);
};
void mu_1_HomeState::Canonicalize(PermSet& Perm)
{
};
void mu_1_HomeState::SimpleLimit(PermSet& Perm)
{
  mu_LDir.SimpleLimit(Perm);
};
void mu_1_HomeState::ArrayLimit(PermSet& Perm){}
void mu_1_HomeState::Limit(PermSet& Perm)
{
};
void mu_1_HomeState::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_4::Permute(PermSet& Perm, int i)
{
};
void mu_1__type_4::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1__type_4::Canonicalize(PermSet& Perm)
{
};
void mu_1__type_4::SimpleLimit(PermSet& Perm){}
void mu_1__type_4::ArrayLimit(PermSet& Perm){}
void mu_1__type_4::Limit(PermSet& Perm)
{
};
void mu_1__type_4::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_5::Permute(PermSet& Perm, int i)
{
  static mu_1__type_5 temp("Permute_mu_1__type_5",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_5::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_5::Canonicalize(PermSet& Perm){};
void mu_1__type_5::SimpleLimit(PermSet& Perm){}
void mu_1__type_5::ArrayLimit(PermSet& Perm) {}
void mu_1__type_5::Limit(PermSet& Perm){}
void mu_1__type_5::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_6::Permute(PermSet& Perm, int i)
{
  static mu_1__type_6 temp("Permute_mu_1__type_6",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_6::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_6::Canonicalize(PermSet& Perm){};
void mu_1__type_6::SimpleLimit(PermSet& Perm){}
void mu_1__type_6::ArrayLimit(PermSet& Perm) {}
void mu_1__type_6::Limit(PermSet& Perm){}
void mu_1__type_6::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_7::Permute(PermSet& Perm, int i)
{
  mu_Granting.Permute(Perm,i);
};
void mu_1__type_7::SimpleCanonicalize(PermSet& Perm)
{
  mu_Granting.SimpleCanonicalize(Perm);
};
void mu_1__type_7::Canonicalize(PermSet& Perm)
{
};
void mu_1__type_7::SimpleLimit(PermSet& Perm)
{
  mu_Granting.SimpleLimit(Perm);
};
void mu_1__type_7::ArrayLimit(PermSet& Perm){}
void mu_1__type_7::Limit(PermSet& Perm)
{
};
void mu_1__type_7::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_8::Permute(PermSet& Perm, int i)
{
  static mu_1__type_8 temp("Permute_mu_1__type_8",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_8::SimpleCanonicalize(PermSet& Perm)
{
  for (int j=0; j<1; j++)
    array[j].SimpleCanonicalize(Perm);
}
void mu_1__type_8::Canonicalize(PermSet& Perm){};
void mu_1__type_8::SimpleLimit(PermSet& Perm)
{
  for (int j=0; j<1; j++) {
    array[j].SimpleLimit(Perm);
  }
}
void mu_1__type_8::ArrayLimit(PermSet& Perm) {}
void mu_1__type_8::Limit(PermSet& Perm){}
void mu_1__type_8::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_9::Permute(PermSet& Perm, int i)
{
  static mu_1__type_9 temp("Permute_mu_1__type_9",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_9::SimpleCanonicalize(PermSet& Perm)
{
  for (int j=0; j<1; j++)
    array[j].SimpleCanonicalize(Perm);
}
void mu_1__type_9::Canonicalize(PermSet& Perm){};
void mu_1__type_9::SimpleLimit(PermSet& Perm)
{
  for (int j=0; j<1; j++) {
    array[j].SimpleLimit(Perm);
  }
}
void mu_1__type_9::ArrayLimit(PermSet& Perm) {}
void mu_1__type_9::Limit(PermSet& Perm){}
void mu_1__type_9::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_10::Permute(PermSet& Perm, int i)
{
};
void mu_1__type_10::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1__type_10::Canonicalize(PermSet& Perm)
{
};
void mu_1__type_10::SimpleLimit(PermSet& Perm){}
void mu_1__type_10::ArrayLimit(PermSet& Perm){}
void mu_1__type_10::Limit(PermSet& Perm)
{
};
void mu_1__type_10::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_11::Permute(PermSet& Perm, int i)
{
  static mu_1__type_11 temp("Permute_mu_1__type_11",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_11::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_11::Canonicalize(PermSet& Perm){};
void mu_1__type_11::SimpleLimit(PermSet& Perm){}
void mu_1__type_11::ArrayLimit(PermSet& Perm) {}
void mu_1__type_11::Limit(PermSet& Perm){}
void mu_1__type_11::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_12::Permute(PermSet& Perm, int i)
{
  static mu_1__type_12 temp("Permute_mu_1__type_12",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_12::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_12::Canonicalize(PermSet& Perm){};
void mu_1__type_12::SimpleLimit(PermSet& Perm){}
void mu_1__type_12::ArrayLimit(PermSet& Perm) {}
void mu_1__type_12::Limit(PermSet& Perm){}
void mu_1__type_12::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1_ProcState::Permute(PermSet& Perm, int i)
{
  mu_LRAC.Permute(Perm,i);
};
void mu_1_ProcState::SimpleCanonicalize(PermSet& Perm)
{
  mu_LRAC.SimpleCanonicalize(Perm);
};
void mu_1_ProcState::Canonicalize(PermSet& Perm)
{
};
void mu_1_ProcState::SimpleLimit(PermSet& Perm)
{
  mu_LRAC.SimpleLimit(Perm);
};
void mu_1_ProcState::ArrayLimit(PermSet& Perm){}
void mu_1_ProcState::Limit(PermSet& Perm)
{
};
void mu_1_ProcState::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_13::Permute(PermSet& Perm, int i) {};
void mu_1__type_13::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_13::Canonicalize(PermSet& Perm) {};
void mu_1__type_13::SimpleLimit(PermSet& Perm) {};
void mu_1__type_13::ArrayLimit(PermSet& Perm) {};
void mu_1__type_13::Limit(PermSet& Perm) {};
void mu_1__type_13::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_29::Permute(PermSet& Perm, int i) {};
void mu__subrange_29::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_29::Canonicalize(PermSet& Perm) {};
void mu__subrange_29::SimpleLimit(PermSet& Perm) {};
void mu__subrange_29::ArrayLimit(PermSet& Perm) {};
void mu__subrange_29::Limit(PermSet& Perm) {};
void mu__subrange_29::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_14::Permute(PermSet& Perm, int i)
{
  static mu_1__type_14 temp("Permute_mu_1__type_14",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_14::SimpleCanonicalize(PermSet& Perm)
{
  for (int j=0; j<3; j++)
    array[j].SimpleCanonicalize(Perm);
}
void mu_1__type_14::Canonicalize(PermSet& Perm){};
void mu_1__type_14::SimpleLimit(PermSet& Perm)
{
  for (int j=0; j<3; j++) {
    array[j].SimpleLimit(Perm);
  }
}
void mu_1__type_14::ArrayLimit(PermSet& Perm) {}
void mu_1__type_14::Limit(PermSet& Perm){}
void mu_1__type_14::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_15::Permute(PermSet& Perm, int i)
{
  mu_Messages.Permute(Perm,i);
};
void mu_1__type_15::SimpleCanonicalize(PermSet& Perm)
{
  mu_Messages.SimpleCanonicalize(Perm);
};
void mu_1__type_15::Canonicalize(PermSet& Perm)
{
};
void mu_1__type_15::SimpleLimit(PermSet& Perm)
{
  mu_Messages.SimpleLimit(Perm);
};
void mu_1__type_15::ArrayLimit(PermSet& Perm){}
void mu_1__type_15::Limit(PermSet& Perm)
{
};
void mu_1__type_15::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_16::Permute(PermSet& Perm, int i)
{
  static mu_1__type_16 temp("Permute_mu_1__type_16",-1);
  int j;
  for (j=0; j<5; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=2; j<=5; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_Remote[Perm.in_mu_1_Remote[i]][j-2]];
};
void mu_1__type_16::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_16::Canonicalize(PermSet& Perm){};
void mu_1__type_16::SimpleLimit(PermSet& Perm){}
void mu_1__type_16::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int compare;
  static mu_1__type_15 value[5];
  // limit
  bool exists;
  bool split;
  int count_mu_1_Remote;
  bool pos_mu_1_Remote[4][4];
  bool goodset_mu_1_Remote[4];
  // sorting mu_1_Remote
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Remote())
    {
      for (i=0; i<4; i++)
        for (j=0; j<4; j++)
          pos_mu_1_Remote[i][j]=FALSE;
      count_mu_1_Remote = 0;
      for (i=0; i<4; i++)
        {
          for (j=0; j<count_mu_1_Remote; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+2]);
              if (compare==0)
                {
                  pos_mu_1_Remote[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Remote; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<4; z++)
                        pos_mu_1_Remote[k][z] = pos_mu_1_Remote[k-1][z];
                    }
                  value[j] = (*this)[i+2];
                  for (z=0; z<4; z++)
                    pos_mu_1_Remote[j][z] = FALSE;
                  pos_mu_1_Remote[j][i] = TRUE;
                  count_mu_1_Remote++;
                  break;
                }
            }
          if (j==count_mu_1_Remote)
            {
              value[j] = (*this)[i+2];
              for (z=0; z<4; z++)
                pos_mu_1_Remote[j][z] = FALSE;
              pos_mu_1_Remote[j][i] = TRUE;
              count_mu_1_Remote++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Remote() && count_mu_1_Remote>1)
    {
      // limit
      for (j=0; j<4; j++) // class priority
        {
          for (i=0; i<count_mu_1_Remote; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<4; k++) // step through class
                goodset_mu_1_Remote[k] = FALSE;
              for (k=0; k<4; k++) // step through class
                if (pos_mu_1_Remote[i][k] && Perm.class_mu_1_Remote[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Remote[k] = TRUE;
                    pos_mu_1_Remote[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<4; k++)
                    if ( Perm.class_mu_1_Remote[k] == j && !goodset_mu_1_Remote[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<4; k++)
                        if (Perm.class_mu_1_Remote[k]>j
                            || ( Perm.class_mu_1_Remote[k] == j && !goodset_mu_1_Remote[k] ) )
                          Perm.class_mu_1_Remote[k]++;
                      Perm.undefined_class_mu_1_Remote++;
                    }
                }
            }
        }
    }
}
void mu_1__type_16::Limit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1__type_15 value[5];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_Remote, oldcount_mu_1_Remote;
  bool pos_mu_1_Remote[4][4];
  bool goodset_mu_1_Remote[4];
  // initializing pos array
  for (i=0; i<4; i++)
    for (j=0; j<4; j++)
      pos_mu_1_Remote[i][j]=FALSE;
  count_mu_1_Remote = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<4; i++)
       if (Perm.class_mu_1_Remote[i] == count_mu_1_Remote)
         {
           pos_mu_1_Remote[count_mu_1_Remote][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Remote++;
      else break;
    }
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 2; i0++)
  {

  // refinement -- check selfloop
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Remote() && count_mu_1_Remote<4)
    {
      exists = FALSE;
      split = FALSE;
      // if there exists both self loop and non-self loop
      for (k=0; k<4; k++) // step through class
        if ((*this)[k+2].mu_Messages[i0].mu_Aux.isundefined()
            ||(*this)[k+2].mu_Messages[i0].mu_Aux!=k+2)
          exists = TRUE;
        else
          split = TRUE;
      if (exists && split)
        {
          for (i=0; i<count_mu_1_Remote; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<4; k++) // step through class
                goodset_mu_1_Remote[k] = FALSE;
              for (k=0; k<4; k++) // step through class
                if (pos_mu_1_Remote[i][k] 
                    && !(*this)[k+2].mu_Messages[i0].mu_Aux.isundefined()
                    && (*this)[k+2].mu_Messages[i0].mu_Aux==k+2)
                  {
                    exists = TRUE;
                    goodset_mu_1_Remote[k] = TRUE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<4; k++)
                    if ( pos_mu_1_Remote[i][k] && !goodset_mu_1_Remote[k] ) 
                          split= TRUE;
                  if (split)
                    {
                      for (j=count_mu_1_Remote; j>i; j--)
                        for (k=0; k<4; k++)
                          pos_mu_1_Remote[j][k] = pos_mu_1_Remote[j-1][k];
                      for (k=0; k<4; k++)
                        {
                          if (pos_mu_1_Remote[i][k] && !goodset_mu_1_Remote[k])
                            pos_mu_1_Remote[i][k] = FALSE;
                          if (pos_mu_1_Remote[i+1][k] && goodset_mu_1_Remote[k])
                            pos_mu_1_Remote[i+1][k] = FALSE;
                        }
                      count_mu_1_Remote++; i++;
                    }
                }
            }
        }
    }
  }

  // refinement -- checking priority in general
  while_guard = FALSE;
  while_guard = while_guard || (Perm.MTO_class_mu_1_Remote() && count_mu_1_Remote<4);
  while ( while_guard )
    {
      oldcount_mu_1_Remote = count_mu_1_Remote;
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 2; i0++)
  {

      // refinement -- graph structure for a single scalarset
      //               as in array S1 of S1
      // only if there is more than 1 permutation in class
      if (Perm.MTO_class_mu_1_Remote() && count_mu_1_Remote<4)
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<4; k++) // step through class
            if (!(*this)[k+2].mu_Messages[i0].mu_Aux.isundefined()
                &&(*this)[k+2].mu_Messages[i0].mu_Aux!=k+2
                &&(*this)[k+2].mu_Messages[i0].mu_Aux>=2
                &&(*this)[k+2].mu_Messages[i0].mu_Aux<=5)
              exists = TRUE;
          if (exists)
            {
              for (i=0; i<count_mu_1_Remote; i++) // for value priority
                {
                  for (j=0; j<count_mu_1_Remote; j++) // for value priority
                    {
                      exists = FALSE;
                      for (k=0; k<4; k++) // step through class
                        goodset_mu_1_Remote[k] = FALSE;
                      for (k=0; k<4; k++) // step through class
                        if (pos_mu_1_Remote[i][k] 
                            && !(*this)[k+2].mu_Messages[i0].mu_Aux.isundefined()
                            && (*this)[k+2].mu_Messages[i0].mu_Aux!=k+2
                            && (*this)[k+2].mu_Messages[i0].mu_Aux>=2
                            && (*this)[k+2].mu_Messages[i0].mu_Aux<=5
                            && pos_mu_1_Remote[j][(*this)[k+2].mu_Messages[i0].mu_Aux-2])
                          {
                            exists = TRUE;
                            goodset_mu_1_Remote[k] = TRUE;
                          }
                      if (exists)
                        {
                          split=FALSE;
                          for (k=0; k<4; k++)
                            if ( pos_mu_1_Remote[i][k] && !goodset_mu_1_Remote[k] ) 
                              split= TRUE;
                          if (split)
                            {
                              for (j=count_mu_1_Remote; j>i; j--)
                                for (k=0; k<4; k++)
                                  pos_mu_1_Remote[j][k] = pos_mu_1_Remote[j-1][k];
                              for (k=0; k<4; k++)
                                {
                                  if (pos_mu_1_Remote[i][k] && !goodset_mu_1_Remote[k])
                                    pos_mu_1_Remote[i][k] = FALSE;
                                  if (pos_mu_1_Remote[i+1][k] && goodset_mu_1_Remote[k])
                                    pos_mu_1_Remote[i+1][k] = FALSE;                  
                                }
                              count_mu_1_Remote++;
                            }
                        }
                    }
                }
            }
        }
  }
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 2; i0++)
  {
  }
      while_guard = FALSE;
      while_guard = while_guard || (oldcount_mu_1_Remote!=count_mu_1_Remote);
      while_guard_temp = while_guard;
      while_guard = FALSE;
      while_guard = while_guard || count_mu_1_Remote<4;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_Remote())
    {
      for (i=0; i<4; i++)
        for (j=0; j<4; j++)
          if (pos_mu_1_Remote[i][j])
            Perm.class_mu_1_Remote[j] = i;
      Perm.undefined_class_mu_1_Remote=0;
      for (j=0; j<4; j++)
        if (Perm.class_mu_1_Remote[j]>Perm.undefined_class_mu_1_Remote)
          Perm.undefined_class_mu_1_Remote=Perm.class_mu_1_Remote[j];
    }
}
void mu_1__type_16::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_17::Permute(PermSet& Perm, int i)
{
  static mu_1__type_17 temp("Permute_mu_1__type_17",-1);
  int j;
  for (j=0; j<5; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=2; j<=5; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_Remote[Perm.in_mu_1_Remote[i]][j-2]];
};
void mu_1__type_17::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_17::Canonicalize(PermSet& Perm){};
void mu_1__type_17::SimpleLimit(PermSet& Perm){}
void mu_1__type_17::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int compare;
  static mu_1__type_16 value[5];
  // limit
  bool exists;
  bool split;
  int count_mu_1_Remote;
  bool pos_mu_1_Remote[4][4];
  bool goodset_mu_1_Remote[4];
  // sorting mu_1_Remote
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Remote())
    {
      for (i=0; i<4; i++)
        for (j=0; j<4; j++)
          pos_mu_1_Remote[i][j]=FALSE;
      count_mu_1_Remote = 0;
      for (i=0; i<4; i++)
        {
          for (j=0; j<count_mu_1_Remote; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+2]);
              if (compare==0)
                {
                  pos_mu_1_Remote[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Remote; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<4; z++)
                        pos_mu_1_Remote[k][z] = pos_mu_1_Remote[k-1][z];
                    }
                  value[j] = (*this)[i+2];
                  for (z=0; z<4; z++)
                    pos_mu_1_Remote[j][z] = FALSE;
                  pos_mu_1_Remote[j][i] = TRUE;
                  count_mu_1_Remote++;
                  break;
                }
            }
          if (j==count_mu_1_Remote)
            {
              value[j] = (*this)[i+2];
              for (z=0; z<4; z++)
                pos_mu_1_Remote[j][z] = FALSE;
              pos_mu_1_Remote[j][i] = TRUE;
              count_mu_1_Remote++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Remote() && count_mu_1_Remote>1)
    {
      // limit
      for (j=0; j<4; j++) // class priority
        {
          for (i=0; i<count_mu_1_Remote; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<4; k++) // step through class
                goodset_mu_1_Remote[k] = FALSE;
              for (k=0; k<4; k++) // step through class
                if (pos_mu_1_Remote[i][k] && Perm.class_mu_1_Remote[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Remote[k] = TRUE;
                    pos_mu_1_Remote[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<4; k++)
                    if ( Perm.class_mu_1_Remote[k] == j && !goodset_mu_1_Remote[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<4; k++)
                        if (Perm.class_mu_1_Remote[k]>j
                            || ( Perm.class_mu_1_Remote[k] == j && !goodset_mu_1_Remote[k] ) )
                          Perm.class_mu_1_Remote[k]++;
                      Perm.undefined_class_mu_1_Remote++;
                    }
                }
            }
        }
    }
}
void mu_1__type_17::Limit(PermSet& Perm){}
void mu_1__type_17::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_18::Permute(PermSet& Perm, int i) {};
void mu_1__type_18::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_18::Canonicalize(PermSet& Perm) {};
void mu_1__type_18::SimpleLimit(PermSet& Perm) {};
void mu_1__type_18::ArrayLimit(PermSet& Perm) {};
void mu_1__type_18::Limit(PermSet& Perm) {};
void mu_1__type_18::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_35::Permute(PermSet& Perm, int i) {};
void mu__subrange_35::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_35::Canonicalize(PermSet& Perm) {};
void mu__subrange_35::SimpleLimit(PermSet& Perm) {};
void mu__subrange_35::ArrayLimit(PermSet& Perm) {};
void mu__subrange_35::Limit(PermSet& Perm) {};
void mu__subrange_35::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_19::Permute(PermSet& Perm, int i)
{
  static mu_1__type_19 temp("Permute_mu_1__type_19",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_19::SimpleCanonicalize(PermSet& Perm)
{
  for (int j=0; j<3; j++)
    array[j].SimpleCanonicalize(Perm);
}
void mu_1__type_19::Canonicalize(PermSet& Perm){};
void mu_1__type_19::SimpleLimit(PermSet& Perm)
{
  for (int j=0; j<3; j++) {
    array[j].SimpleLimit(Perm);
  }
}
void mu_1__type_19::ArrayLimit(PermSet& Perm) {}
void mu_1__type_19::Limit(PermSet& Perm){}
void mu_1__type_19::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_20::Permute(PermSet& Perm, int i)
{
  mu_Messages.Permute(Perm,i);
};
void mu_1__type_20::SimpleCanonicalize(PermSet& Perm)
{
  mu_Messages.SimpleCanonicalize(Perm);
};
void mu_1__type_20::Canonicalize(PermSet& Perm)
{
};
void mu_1__type_20::SimpleLimit(PermSet& Perm)
{
  mu_Messages.SimpleLimit(Perm);
};
void mu_1__type_20::ArrayLimit(PermSet& Perm){}
void mu_1__type_20::Limit(PermSet& Perm)
{
};
void mu_1__type_20::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_21::Permute(PermSet& Perm, int i)
{
  static mu_1__type_21 temp("Permute_mu_1__type_21",-1);
  int j;
  for (j=0; j<5; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=2; j<=5; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_Remote[Perm.in_mu_1_Remote[i]][j-2]];
};
void mu_1__type_21::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_21::Canonicalize(PermSet& Perm){};
void mu_1__type_21::SimpleLimit(PermSet& Perm){}
void mu_1__type_21::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int compare;
  static mu_1__type_20 value[5];
  // limit
  bool exists;
  bool split;
  int count_mu_1_Remote;
  bool pos_mu_1_Remote[4][4];
  bool goodset_mu_1_Remote[4];
  // sorting mu_1_Remote
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Remote())
    {
      for (i=0; i<4; i++)
        for (j=0; j<4; j++)
          pos_mu_1_Remote[i][j]=FALSE;
      count_mu_1_Remote = 0;
      for (i=0; i<4; i++)
        {
          for (j=0; j<count_mu_1_Remote; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+2]);
              if (compare==0)
                {
                  pos_mu_1_Remote[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Remote; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<4; z++)
                        pos_mu_1_Remote[k][z] = pos_mu_1_Remote[k-1][z];
                    }
                  value[j] = (*this)[i+2];
                  for (z=0; z<4; z++)
                    pos_mu_1_Remote[j][z] = FALSE;
                  pos_mu_1_Remote[j][i] = TRUE;
                  count_mu_1_Remote++;
                  break;
                }
            }
          if (j==count_mu_1_Remote)
            {
              value[j] = (*this)[i+2];
              for (z=0; z<4; z++)
                pos_mu_1_Remote[j][z] = FALSE;
              pos_mu_1_Remote[j][i] = TRUE;
              count_mu_1_Remote++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Remote() && count_mu_1_Remote>1)
    {
      // limit
      for (j=0; j<4; j++) // class priority
        {
          for (i=0; i<count_mu_1_Remote; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<4; k++) // step through class
                goodset_mu_1_Remote[k] = FALSE;
              for (k=0; k<4; k++) // step through class
                if (pos_mu_1_Remote[i][k] && Perm.class_mu_1_Remote[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Remote[k] = TRUE;
                    pos_mu_1_Remote[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<4; k++)
                    if ( Perm.class_mu_1_Remote[k] == j && !goodset_mu_1_Remote[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<4; k++)
                        if (Perm.class_mu_1_Remote[k]>j
                            || ( Perm.class_mu_1_Remote[k] == j && !goodset_mu_1_Remote[k] ) )
                          Perm.class_mu_1_Remote[k]++;
                      Perm.undefined_class_mu_1_Remote++;
                    }
                }
            }
        }
    }
}
void mu_1__type_21::Limit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1__type_20 value[5];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_Remote, oldcount_mu_1_Remote;
  bool pos_mu_1_Remote[4][4];
  bool goodset_mu_1_Remote[4];
  // initializing pos array
  for (i=0; i<4; i++)
    for (j=0; j<4; j++)
      pos_mu_1_Remote[i][j]=FALSE;
  count_mu_1_Remote = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<4; i++)
       if (Perm.class_mu_1_Remote[i] == count_mu_1_Remote)
         {
           pos_mu_1_Remote[count_mu_1_Remote][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Remote++;
      else break;
    }
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 2; i0++)
  {

  // refinement -- check selfloop
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Remote() && count_mu_1_Remote<4)
    {
      exists = FALSE;
      split = FALSE;
      // if there exists both self loop and non-self loop
      for (k=0; k<4; k++) // step through class
        if ((*this)[k+2].mu_Messages[i0].mu_Aux.isundefined()
            ||(*this)[k+2].mu_Messages[i0].mu_Aux!=k+2)
          exists = TRUE;
        else
          split = TRUE;
      if (exists && split)
        {
          for (i=0; i<count_mu_1_Remote; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<4; k++) // step through class
                goodset_mu_1_Remote[k] = FALSE;
              for (k=0; k<4; k++) // step through class
                if (pos_mu_1_Remote[i][k] 
                    && !(*this)[k+2].mu_Messages[i0].mu_Aux.isundefined()
                    && (*this)[k+2].mu_Messages[i0].mu_Aux==k+2)
                  {
                    exists = TRUE;
                    goodset_mu_1_Remote[k] = TRUE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<4; k++)
                    if ( pos_mu_1_Remote[i][k] && !goodset_mu_1_Remote[k] ) 
                          split= TRUE;
                  if (split)
                    {
                      for (j=count_mu_1_Remote; j>i; j--)
                        for (k=0; k<4; k++)
                          pos_mu_1_Remote[j][k] = pos_mu_1_Remote[j-1][k];
                      for (k=0; k<4; k++)
                        {
                          if (pos_mu_1_Remote[i][k] && !goodset_mu_1_Remote[k])
                            pos_mu_1_Remote[i][k] = FALSE;
                          if (pos_mu_1_Remote[i+1][k] && goodset_mu_1_Remote[k])
                            pos_mu_1_Remote[i+1][k] = FALSE;
                        }
                      count_mu_1_Remote++; i++;
                    }
                }
            }
        }
    }
  }

  // refinement -- checking priority in general
  while_guard = FALSE;
  while_guard = while_guard || (Perm.MTO_class_mu_1_Remote() && count_mu_1_Remote<4);
  while ( while_guard )
    {
      oldcount_mu_1_Remote = count_mu_1_Remote;
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 2; i0++)
  {

      // refinement -- graph structure for a single scalarset
      //               as in array S1 of S1
      // only if there is more than 1 permutation in class
      if (Perm.MTO_class_mu_1_Remote() && count_mu_1_Remote<4)
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<4; k++) // step through class
            if (!(*this)[k+2].mu_Messages[i0].mu_Aux.isundefined()
                &&(*this)[k+2].mu_Messages[i0].mu_Aux!=k+2
                &&(*this)[k+2].mu_Messages[i0].mu_Aux>=2
                &&(*this)[k+2].mu_Messages[i0].mu_Aux<=5)
              exists = TRUE;
          if (exists)
            {
              for (i=0; i<count_mu_1_Remote; i++) // for value priority
                {
                  for (j=0; j<count_mu_1_Remote; j++) // for value priority
                    {
                      exists = FALSE;
                      for (k=0; k<4; k++) // step through class
                        goodset_mu_1_Remote[k] = FALSE;
                      for (k=0; k<4; k++) // step through class
                        if (pos_mu_1_Remote[i][k] 
                            && !(*this)[k+2].mu_Messages[i0].mu_Aux.isundefined()
                            && (*this)[k+2].mu_Messages[i0].mu_Aux!=k+2
                            && (*this)[k+2].mu_Messages[i0].mu_Aux>=2
                            && (*this)[k+2].mu_Messages[i0].mu_Aux<=5
                            && pos_mu_1_Remote[j][(*this)[k+2].mu_Messages[i0].mu_Aux-2])
                          {
                            exists = TRUE;
                            goodset_mu_1_Remote[k] = TRUE;
                          }
                      if (exists)
                        {
                          split=FALSE;
                          for (k=0; k<4; k++)
                            if ( pos_mu_1_Remote[i][k] && !goodset_mu_1_Remote[k] ) 
                              split= TRUE;
                          if (split)
                            {
                              for (j=count_mu_1_Remote; j>i; j--)
                                for (k=0; k<4; k++)
                                  pos_mu_1_Remote[j][k] = pos_mu_1_Remote[j-1][k];
                              for (k=0; k<4; k++)
                                {
                                  if (pos_mu_1_Remote[i][k] && !goodset_mu_1_Remote[k])
                                    pos_mu_1_Remote[i][k] = FALSE;
                                  if (pos_mu_1_Remote[i+1][k] && goodset_mu_1_Remote[k])
                                    pos_mu_1_Remote[i+1][k] = FALSE;                  
                                }
                              count_mu_1_Remote++;
                            }
                        }
                    }
                }
            }
        }
  }
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 2; i0++)
  {
  }
      while_guard = FALSE;
      while_guard = while_guard || (oldcount_mu_1_Remote!=count_mu_1_Remote);
      while_guard_temp = while_guard;
      while_guard = FALSE;
      while_guard = while_guard || count_mu_1_Remote<4;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_Remote())
    {
      for (i=0; i<4; i++)
        for (j=0; j<4; j++)
          if (pos_mu_1_Remote[i][j])
            Perm.class_mu_1_Remote[j] = i;
      Perm.undefined_class_mu_1_Remote=0;
      for (j=0; j<4; j++)
        if (Perm.class_mu_1_Remote[j]>Perm.undefined_class_mu_1_Remote)
          Perm.undefined_class_mu_1_Remote=Perm.class_mu_1_Remote[j];
    }
}
void mu_1__type_21::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_22::Permute(PermSet& Perm, int i)
{
  static mu_1__type_22 temp("Permute_mu_1__type_22",-1);
  int j;
  for (j=0; j<5; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=2; j<=5; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_Remote[Perm.in_mu_1_Remote[i]][j-2]];
};
void mu_1__type_22::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_22::Canonicalize(PermSet& Perm){};
void mu_1__type_22::SimpleLimit(PermSet& Perm){}
void mu_1__type_22::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int compare;
  static mu_1__type_21 value[5];
  // limit
  bool exists;
  bool split;
  int count_mu_1_Remote;
  bool pos_mu_1_Remote[4][4];
  bool goodset_mu_1_Remote[4];
  // sorting mu_1_Remote
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Remote())
    {
      for (i=0; i<4; i++)
        for (j=0; j<4; j++)
          pos_mu_1_Remote[i][j]=FALSE;
      count_mu_1_Remote = 0;
      for (i=0; i<4; i++)
        {
          for (j=0; j<count_mu_1_Remote; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+2]);
              if (compare==0)
                {
                  pos_mu_1_Remote[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Remote; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<4; z++)
                        pos_mu_1_Remote[k][z] = pos_mu_1_Remote[k-1][z];
                    }
                  value[j] = (*this)[i+2];
                  for (z=0; z<4; z++)
                    pos_mu_1_Remote[j][z] = FALSE;
                  pos_mu_1_Remote[j][i] = TRUE;
                  count_mu_1_Remote++;
                  break;
                }
            }
          if (j==count_mu_1_Remote)
            {
              value[j] = (*this)[i+2];
              for (z=0; z<4; z++)
                pos_mu_1_Remote[j][z] = FALSE;
              pos_mu_1_Remote[j][i] = TRUE;
              count_mu_1_Remote++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Remote() && count_mu_1_Remote>1)
    {
      // limit
      for (j=0; j<4; j++) // class priority
        {
          for (i=0; i<count_mu_1_Remote; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<4; k++) // step through class
                goodset_mu_1_Remote[k] = FALSE;
              for (k=0; k<4; k++) // step through class
                if (pos_mu_1_Remote[i][k] && Perm.class_mu_1_Remote[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Remote[k] = TRUE;
                    pos_mu_1_Remote[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<4; k++)
                    if ( Perm.class_mu_1_Remote[k] == j && !goodset_mu_1_Remote[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<4; k++)
                        if (Perm.class_mu_1_Remote[k]>j
                            || ( Perm.class_mu_1_Remote[k] == j && !goodset_mu_1_Remote[k] ) )
                          Perm.class_mu_1_Remote[k]++;
                      Perm.undefined_class_mu_1_Remote++;
                    }
                }
            }
        }
    }
}
void mu_1__type_22::Limit(PermSet& Perm){}
void mu_1__type_22::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_23::Permute(PermSet& Perm, int i)
{
  static mu_1__type_23 temp("Permute_mu_1__type_23",-1);
  int j;
  for (j=0; j<5; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=2; j<=5; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_Remote[Perm.in_mu_1_Remote[i]][j-2]];
};
void mu_1__type_23::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_23::Canonicalize(PermSet& Perm){};
void mu_1__type_23::SimpleLimit(PermSet& Perm){}
void mu_1__type_23::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int compare;
  static mu_1_ProcState value[5];
  // limit
  bool exists;
  bool split;
  int count_mu_1_Remote;
  bool pos_mu_1_Remote[4][4];
  bool goodset_mu_1_Remote[4];
  // sorting mu_1_Remote
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Remote())
    {
      for (i=0; i<4; i++)
        for (j=0; j<4; j++)
          pos_mu_1_Remote[i][j]=FALSE;
      count_mu_1_Remote = 0;
      for (i=0; i<4; i++)
        {
          for (j=0; j<count_mu_1_Remote; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+2]);
              if (compare==0)
                {
                  pos_mu_1_Remote[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Remote; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<4; z++)
                        pos_mu_1_Remote[k][z] = pos_mu_1_Remote[k-1][z];
                    }
                  value[j] = (*this)[i+2];
                  for (z=0; z<4; z++)
                    pos_mu_1_Remote[j][z] = FALSE;
                  pos_mu_1_Remote[j][i] = TRUE;
                  count_mu_1_Remote++;
                  break;
                }
            }
          if (j==count_mu_1_Remote)
            {
              value[j] = (*this)[i+2];
              for (z=0; z<4; z++)
                pos_mu_1_Remote[j][z] = FALSE;
              pos_mu_1_Remote[j][i] = TRUE;
              count_mu_1_Remote++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Remote() && count_mu_1_Remote>1)
    {
      // limit
      for (j=0; j<4; j++) // class priority
        {
          for (i=0; i<count_mu_1_Remote; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<4; k++) // step through class
                goodset_mu_1_Remote[k] = FALSE;
              for (k=0; k<4; k++) // step through class
                if (pos_mu_1_Remote[i][k] && Perm.class_mu_1_Remote[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Remote[k] = TRUE;
                    pos_mu_1_Remote[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<4; k++)
                    if ( Perm.class_mu_1_Remote[k] == j && !goodset_mu_1_Remote[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<4; k++)
                        if (Perm.class_mu_1_Remote[k]>j
                            || ( Perm.class_mu_1_Remote[k] == j && !goodset_mu_1_Remote[k] ) )
                          Perm.class_mu_1_Remote[k]++;
                      Perm.undefined_class_mu_1_Remote++;
                    }
                }
            }
        }
    }
}
void mu_1__type_23::Limit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_ProcState value[5];
  // limit
  bool exists;
  bool split;
  int i0,i1;
  int count_mu_1_Remote, oldcount_mu_1_Remote;
  bool pos_mu_1_Remote[4][4];
  bool goodset_mu_1_Remote[4];
  // initializing pos array
  for (i=0; i<4; i++)
    for (j=0; j<4; j++)
      pos_mu_1_Remote[i][j]=FALSE;
  count_mu_1_Remote = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<4; i++)
       if (Perm.class_mu_1_Remote[i] == count_mu_1_Remote)
         {
           pos_mu_1_Remote[count_mu_1_Remote][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Remote++;
      else break;
    }

  // refinement -- check selfloop
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Remote() && count_mu_1_Remote<4)
    {
      exists = FALSE;
      split = FALSE;
      // if there exists both self loop and non-self loop
      for (k=0; k<4; k++) // step through class
        if ((*this)[k+2].mu_LRAC[mu_Home_1][mu_LAddress_1].mu_Granting.isundefined()
            ||(*this)[k+2].mu_LRAC[mu_Home_1][mu_LAddress_1].mu_Granting!=k+2)
          exists = TRUE;
        else
          split = TRUE;
      if (exists && split)
        {
          for (i=0; i<count_mu_1_Remote; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<4; k++) // step through class
                goodset_mu_1_Remote[k] = FALSE;
              for (k=0; k<4; k++) // step through class
                if (pos_mu_1_Remote[i][k] 
                    && !(*this)[k+2].mu_LRAC[mu_Home_1][mu_LAddress_1].mu_Granting.isundefined()
                    && (*this)[k+2].mu_LRAC[mu_Home_1][mu_LAddress_1].mu_Granting==k+2)
                  {
                    exists = TRUE;
                    goodset_mu_1_Remote[k] = TRUE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<4; k++)
                    if ( pos_mu_1_Remote[i][k] && !goodset_mu_1_Remote[k] ) 
                          split= TRUE;
                  if (split)
                    {
                      for (j=count_mu_1_Remote; j>i; j--)
                        for (k=0; k<4; k++)
                          pos_mu_1_Remote[j][k] = pos_mu_1_Remote[j-1][k];
                      for (k=0; k<4; k++)
                        {
                          if (pos_mu_1_Remote[i][k] && !goodset_mu_1_Remote[k])
                            pos_mu_1_Remote[i][k] = FALSE;
                          if (pos_mu_1_Remote[i+1][k] && goodset_mu_1_Remote[k])
                            pos_mu_1_Remote[i+1][k] = FALSE;
                        }
                      count_mu_1_Remote++; i++;
                    }
                }
            }
        }
    }

  // refinement -- checking priority in general
  while_guard = FALSE;
  while_guard = while_guard || (Perm.MTO_class_mu_1_Remote() && count_mu_1_Remote<4);
  while ( while_guard )
    {
      oldcount_mu_1_Remote = count_mu_1_Remote;

      // refinement -- graph structure for a single scalarset
      //               as in array S1 of S1
      // only if there is more than 1 permutation in class
      if (Perm.MTO_class_mu_1_Remote() && count_mu_1_Remote<4)
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<4; k++) // step through class
            if (!(*this)[k+2].mu_LRAC[mu_Home_1][mu_LAddress_1].mu_Granting.isundefined()
                &&(*this)[k+2].mu_LRAC[mu_Home_1][mu_LAddress_1].mu_Granting!=k+2
                &&(*this)[k+2].mu_LRAC[mu_Home_1][mu_LAddress_1].mu_Granting>=2
                &&(*this)[k+2].mu_LRAC[mu_Home_1][mu_LAddress_1].mu_Granting<=5)
              exists = TRUE;
          if (exists)
            {
              for (i=0; i<count_mu_1_Remote; i++) // for value priority
                {
                  for (j=0; j<count_mu_1_Remote; j++) // for value priority
                    {
                      exists = FALSE;
                      for (k=0; k<4; k++) // step through class
                        goodset_mu_1_Remote[k] = FALSE;
                      for (k=0; k<4; k++) // step through class
                        if (pos_mu_1_Remote[i][k] 
                            && !(*this)[k+2].mu_LRAC[mu_Home_1][mu_LAddress_1].mu_Granting.isundefined()
                            && (*this)[k+2].mu_LRAC[mu_Home_1][mu_LAddress_1].mu_Granting!=k+2
                            && (*this)[k+2].mu_LRAC[mu_Home_1][mu_LAddress_1].mu_Granting>=2
                            && (*this)[k+2].mu_LRAC[mu_Home_1][mu_LAddress_1].mu_Granting<=5
                            && pos_mu_1_Remote[j][(*this)[k+2].mu_LRAC[mu_Home_1][mu_LAddress_1].mu_Granting-2])
                          {
                            exists = TRUE;
                            goodset_mu_1_Remote[k] = TRUE;
                          }
                      if (exists)
                        {
                          split=FALSE;
                          for (k=0; k<4; k++)
                            if ( pos_mu_1_Remote[i][k] && !goodset_mu_1_Remote[k] ) 
                              split= TRUE;
                          if (split)
                            {
                              for (j=count_mu_1_Remote; j>i; j--)
                                for (k=0; k<4; k++)
                                  pos_mu_1_Remote[j][k] = pos_mu_1_Remote[j-1][k];
                              for (k=0; k<4; k++)
                                {
                                  if (pos_mu_1_Remote[i][k] && !goodset_mu_1_Remote[k])
                                    pos_mu_1_Remote[i][k] = FALSE;
                                  if (pos_mu_1_Remote[i+1][k] && goodset_mu_1_Remote[k])
                                    pos_mu_1_Remote[i+1][k] = FALSE;                  
                                }
                              count_mu_1_Remote++;
                            }
                        }
                    }
                }
            }
        }
      while_guard = FALSE;
      while_guard = while_guard || (oldcount_mu_1_Remote!=count_mu_1_Remote);
      while_guard_temp = while_guard;
      while_guard = FALSE;
      while_guard = while_guard || count_mu_1_Remote<4;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_Remote())
    {
      for (i=0; i<4; i++)
        for (j=0; j<4; j++)
          if (pos_mu_1_Remote[i][j])
            Perm.class_mu_1_Remote[j] = i;
      Perm.undefined_class_mu_1_Remote=0;
      for (j=0; j<4; j++)
        if (Perm.class_mu_1_Remote[j]>Perm.undefined_class_mu_1_Remote)
          Perm.undefined_class_mu_1_Remote=Perm.class_mu_1_Remote[j];
    }
}
void mu_1__type_23::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_24::Permute(PermSet& Perm, int i)
{
  static mu_1__type_24 temp("Permute_mu_1__type_24",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_24::SimpleCanonicalize(PermSet& Perm)
{
  for (int j=0; j<1; j++)
    array[j].SimpleCanonicalize(Perm);
}
void mu_1__type_24::Canonicalize(PermSet& Perm){};
void mu_1__type_24::SimpleLimit(PermSet& Perm)
{
  for (int j=0; j<1; j++) {
    array[j].SimpleLimit(Perm);
  }
}
void mu_1__type_24::ArrayLimit(PermSet& Perm) {}
void mu_1__type_24::Limit(PermSet& Perm){}
void mu_1__type_24::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_25::Permute(PermSet& Perm, int i) {};
void mu_1__type_25::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_25::Canonicalize(PermSet& Perm) {};
void mu_1__type_25::SimpleLimit(PermSet& Perm) {};
void mu_1__type_25::ArrayLimit(PermSet& Perm) {};
void mu_1__type_25::Limit(PermSet& Perm) {};
void mu_1__type_25::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1__type_26::Permute(PermSet& Perm, int i)
{
  mu_Proc.Permute(Perm,i);
};
void mu_1__type_26::SimpleCanonicalize(PermSet& Perm)
{
  mu_Proc.SimpleCanonicalize(Perm);
};
void mu_1__type_26::Canonicalize(PermSet& Perm)
{
};
void mu_1__type_26::SimpleLimit(PermSet& Perm)
{
  mu_Proc.SimpleLimit(Perm);
};
void mu_1__type_26::ArrayLimit(PermSet& Perm){}
void mu_1__type_26::Limit(PermSet& Perm)
{
};
void mu_1__type_26::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_27::Permute(PermSet& Perm, int i)
{
  static mu_1__type_27 temp("Permute_mu_1__type_27",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_27::SimpleCanonicalize(PermSet& Perm)
{
  for (int j=0; j<1; j++)
    array[j].SimpleCanonicalize(Perm);
}
void mu_1__type_27::Canonicalize(PermSet& Perm){};
void mu_1__type_27::SimpleLimit(PermSet& Perm)
{
  for (int j=0; j<1; j++) {
    array[j].SimpleLimit(Perm);
  }
}
void mu_1__type_27::ArrayLimit(PermSet& Perm) {}
void mu_1__type_27::Limit(PermSet& Perm){}
void mu_1__type_27::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_28::Permute(PermSet& Perm, int i)
{
  static mu_1__type_28 temp("Permute_mu_1__type_28",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_28::SimpleCanonicalize(PermSet& Perm)
{
  for (int j=0; j<1; j++)
    array[j].SimpleCanonicalize(Perm);
}
void mu_1__type_28::Canonicalize(PermSet& Perm){};
void mu_1__type_28::SimpleLimit(PermSet& Perm)
{
  for (int j=0; j<1; j++) {
    array[j].SimpleLimit(Perm);
  }
}
void mu_1__type_28::ArrayLimit(PermSet& Perm) {}
void mu_1__type_28::Limit(PermSet& Perm){}
void mu_1__type_28::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu__subrange_46::Permute(PermSet& Perm, int i) {};
void mu__subrange_46::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_46::Canonicalize(PermSet& Perm) {};
void mu__subrange_46::SimpleLimit(PermSet& Perm) {};
void mu__subrange_46::ArrayLimit(PermSet& Perm) {};
void mu__subrange_46::Limit(PermSet& Perm) {};
void mu__subrange_46::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_47::Permute(PermSet& Perm, int i) {};
void mu__subrange_47::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_47::Canonicalize(PermSet& Perm) {};
void mu__subrange_47::SimpleLimit(PermSet& Perm) {};
void mu__subrange_47::ArrayLimit(PermSet& Perm) {};
void mu__subrange_47::Limit(PermSet& Perm) {};
void mu__subrange_47::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu__subrange_48::Permute(PermSet& Perm, int i) {};
void mu__subrange_48::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_48::Canonicalize(PermSet& Perm) {};
void mu__subrange_48::SimpleLimit(PermSet& Perm) {};
void mu__subrange_48::ArrayLimit(PermSet& Perm) {};
void mu__subrange_48::Limit(PermSet& Perm) {};
void mu__subrange_48::MultisetLimit(PermSet& Perm)
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
      if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize
         || args->sym_alg.mode == argsym_alg::Heuristic_Fast_Canonicalize) {
        Perm.ResetToExplicit();
        for (i=0; i<Perm.count; i++)
          if (Perm.In(i))
            {
              if (ns != workingstate)
                  StateCopy(workingstate, ns);
              
              mu_Homes.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_Homes.MultisetSort();
              mu_LockOwner.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_LockOwner.MultisetSort();
              mu_Procs.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_Procs.MultisetSort();
              mu_ReplyNet.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_ReplyNet.MultisetSort();
              mu_ReqNet.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_ReqNet.MultisetSort();
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

          mu_Homes.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_Homes.MultisetSort();
          mu_LockOwner.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_LockOwner.MultisetSort();
          mu_Procs.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_Procs.MultisetSort();
          mu_ReplyNet.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_ReplyNet.MultisetSort();
          mu_ReqNet.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_ReqNet.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_Homes.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_Homes.MultisetSort();
              mu_LockOwner.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_LockOwner.MultisetSort();
              mu_Procs.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_Procs.MultisetSort();
              mu_ReplyNet.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_ReplyNet.MultisetSort();
              mu_ReqNet.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_ReqNet.MultisetSort();
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
      mu_Homes.MultisetSort();
      mu_LockOwner.MultisetSort();
      mu_Procs.MultisetSort();
      mu_ReplyNet.MultisetSort();
      mu_ReqNet.MultisetSort();
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
        mu_Homes.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Homes.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_LockOwner.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_LockOwner.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_Procs.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Procs.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_ReplyNet.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_ReplyNet.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_ReqNet.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_ReqNet.MultisetSort();
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

  mu_Homes.SimpleCanonicalize(Perm);

  mu_LockOwner.SimpleCanonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_Procs.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Procs.Limit(Perm);
  }

  Perm.SimpleToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_Procs.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Procs.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_ReplyNet.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_ReplyNet.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_ReqNet.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_ReqNet.MultisetSort();
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
 and use less local memory
 ********************/
void SymmetryClass::Heuristic_Small_Mem_Canonicalize(state* s)
{
  unsigned long cycle;
  static state temp;

  Perm.ResetToSimple();

  mu_Homes.SimpleCanonicalize(Perm);

  mu_LockOwner.SimpleCanonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_Procs.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Procs.Limit(Perm);
  }

  Perm.SimpleToOne();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  mu_Procs.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_Procs.MultisetSort();
  mu_ReplyNet.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_ReplyNet.MultisetSort();
  mu_ReqNet.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_ReqNet.MultisetSort();
  BestPermutedState = *workingstate;
  BestInitialized = TRUE;

  cycle=1;
  while (Perm.NextPermutation())
    {
      if (args->perm_limit.value != 0
          && cycle++ >= args->perm_limit.value) break;
      StateCopy(workingstate, &temp);
      mu_Procs.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_Procs.MultisetSort();
      mu_ReplyNet.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_ReplyNet.MultisetSort();
      mu_ReqNet.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_ReqNet.MultisetSort();
      switch (StateCmp(workingstate, &BestPermutedState)) {
      case -1:
        BestPermutedState = *workingstate;
        break;
      case 1:
        break;
      case 0:
        break;
      default:
        Error.Error("funny return value from StateCmp");
      }
    }
  StateCopy(workingstate, &BestPermutedState);

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

  mu_Homes.SimpleCanonicalize(Perm);

  mu_LockOwner.SimpleCanonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_Procs.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Procs.Limit(Perm);
  }

  Perm.SimpleToOne();

  mu_Procs.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_Procs.MultisetSort();

  mu_ReplyNet.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_ReplyNet.MultisetSort();

  mu_ReqNet.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_ReqNet.MultisetSort();

};

/********************
  Include
 ********************/
#include "mu_epilog.inc"
