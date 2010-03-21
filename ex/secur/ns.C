/******************************
  Program "ns.m" compiled by "Eddy_Murphi Release 3.2.4"

  Murphi Last Modefied Date: "June 19 2009"
  Murphi Last Compiled date: "Mar 13 2010"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Eddy_Murphi Release 3.2.4"
#define MURPHI_DATE "June 19 2009"
#define PROTOCOL_NAME "ns"
#define BITS_IN_WORLD 744
#define HASHC
#define PARALLEL

/********************
  Include
 ********************/
#include "mu_prolog.inc"

/********************
  Decl declaration
 ********************/

class mu_1_InitiatorId: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_InitiatorId& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_InitiatorId& val)
    {
      if (val.defined())
        return ( s << mu_1_InitiatorId::values[ int(val) - 1 ] );
      else
        return ( s << "Undefined" );
    };

  mu_1_InitiatorId (char *name, int os): mu__byte(1, 1, 1, name, os) {};
  mu_1_InitiatorId (void): mu__byte(1, 1, 1) {};
  mu_1_InitiatorId (int val): mu__byte(1, 1, 1, "Parameter or function result.", 0)
    { operator=(val); };
  char * Name() { return values[ value() -1]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 1] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_InitiatorId& a, mu_1_InitiatorId& b)
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
char *mu_1_InitiatorId::values[] =
  { "InitiatorId_1",NULL };

/*** end scalarset declaration ***/
mu_1_InitiatorId mu_1_InitiatorId_undefined_var;

class mu_1_ResponderId: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_ResponderId& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_ResponderId& val)
    {
      if (val.defined())
        return ( s << mu_1_ResponderId::values[ int(val) - 2 ] );
      else
        return ( s << "Undefined" );
    };

  mu_1_ResponderId (char *name, int os): mu__byte(2, 2, 1, name, os) {};
  mu_1_ResponderId (void): mu__byte(2, 2, 1) {};
  mu_1_ResponderId (int val): mu__byte(2, 2, 1, "Parameter or function result.", 0)
    { operator=(val); };
  char * Name() { return values[ value() -2]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 2] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_ResponderId& a, mu_1_ResponderId& b)
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
char *mu_1_ResponderId::values[] =
  { "ResponderId_1",NULL };

/*** end scalarset declaration ***/
mu_1_ResponderId mu_1_ResponderId_undefined_var;

class mu_1_IntruderId: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_IntruderId& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_IntruderId& val)
    {
      if (val.defined())
        return ( s << mu_1_IntruderId::values[ int(val) - 3 ] );
      else
        return ( s << "Undefined" );
    };

  mu_1_IntruderId (char *name, int os): mu__byte(3, 5, 2, name, os) {};
  mu_1_IntruderId (void): mu__byte(3, 5, 2) {};
  mu_1_IntruderId (int val): mu__byte(3, 5, 2, "Parameter or function result.", 0)
    { operator=(val); };
  char * Name() { return values[ value() -3]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 3] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_IntruderId& a, mu_1_IntruderId& b)
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
char *mu_1_IntruderId::values[] =
  { "IntruderId_1","IntruderId_2","IntruderId_3",NULL };

/*** end scalarset declaration ***/
mu_1_IntruderId mu_1_IntruderId_undefined_var;

class mu_1_AgentId: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_AgentId& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_AgentId& val)
    {
      if (val.defined())
        return ( s << mu_1_AgentId::values[ val.indexvalue() ] );
      else
        return ( s << "Undefined" );
    };

  // note thate lb and ub are not used if we have byte compacted state.
  mu_1_AgentId (char *name, int os): mu__byte(0, 4, 3, name, os) {};
  mu_1_AgentId (void): mu__byte(0, 4, 3) {};
  mu_1_AgentId (int val): mu__byte(0, 4, 3, "Parameter or function result.", 0)
    { operator=(val); };
  int value() const
  {
    int val = mu__byte::value();
    // val == -1 if value undefined
    // we can return it since no enum/scalarsetid will have value -1
    if (val == -1) return -1;
    if (val <= 0) return val+1;
    if (val <= 1) return val+1;
    if (val <= 4) return val+1;
  }
  inline int value(int val)
  {
    if (val == -1) { undefine(); return -1; }
    if ((val >= 1) && (val <= 1)) return (mu__byte::value(val-1)+1);
    if ((val >= 2) && (val <= 2)) return (mu__byte::value(val-1)+1);
    if ((val >= 3) && (val <= 5)) return (mu__byte::value(val-1)+1);
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
friend int CompareWeight(mu_1_AgentId& a, mu_1_AgentId& b)
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
char *mu_1_AgentId::values[] = {"InitiatorId_1","ResponderId_1","IntruderId_1","IntruderId_2","IntruderId_3",NULL };

/*** end union declaration ***/
mu_1_AgentId mu_1_AgentId_undefined_var;

class mu_1_MessageType: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_MessageType& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_MessageType& val)
  {
    if (val.defined())
      return ( s << mu_1_MessageType::values[ int(val) - 6] );
    else return ( s << "Undefined" );
  };

  mu_1_MessageType (char *name, int os): mu__byte(6, 8, 2, name, os) {};
  mu_1_MessageType (void): mu__byte(6, 8, 2) {};
  mu_1_MessageType (int val): mu__byte(6, 8, 2, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -6]; };
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
      cout << name << ":" << values[ value() -6] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1_MessageType::values[] = {"M_NonceAddress","M_NonceNonceAddress","M_Nonce",NULL };

/*** end of enum declaration ***/
mu_1_MessageType mu_1_MessageType_undefined_var;

class mu_1_Message
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1_AgentId mu_source;
  mu_1_AgentId mu_dest;
  mu_1_AgentId mu_key;
  mu_1_MessageType mu_mType;
  mu_1_AgentId mu_nonce1;
  mu_1_AgentId mu_nonce2;
  mu_1_AgentId mu_address;
  mu_1_Message ( char *n, int os ) { set_self(n,os); };
  mu_1_Message ( void ) {};

  virtual ~mu_1_Message(); 
friend int CompareWeight(mu_1_Message& a, mu_1_Message& b)
  {
    int w;
    w = CompareWeight(a.mu_source, b.mu_source);
    if (w!=0) return w;
    w = CompareWeight(a.mu_dest, b.mu_dest);
    if (w!=0) return w;
    w = CompareWeight(a.mu_key, b.mu_key);
    if (w!=0) return w;
    w = CompareWeight(a.mu_mType, b.mu_mType);
    if (w!=0) return w;
    w = CompareWeight(a.mu_nonce1, b.mu_nonce1);
    if (w!=0) return w;
    w = CompareWeight(a.mu_nonce2, b.mu_nonce2);
    if (w!=0) return w;
    w = CompareWeight(a.mu_address, b.mu_address);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_Message& a, mu_1_Message& b)
  {
    int w;
    w = Compare(a.mu_source, b.mu_source);
    if (w!=0) return w;
    w = Compare(a.mu_dest, b.mu_dest);
    if (w!=0) return w;
    w = Compare(a.mu_key, b.mu_key);
    if (w!=0) return w;
    w = Compare(a.mu_mType, b.mu_mType);
    if (w!=0) return w;
    w = Compare(a.mu_nonce1, b.mu_nonce1);
    if (w!=0) return w;
    w = Compare(a.mu_nonce2, b.mu_nonce2);
    if (w!=0) return w;
    w = Compare(a.mu_address, b.mu_address);
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
    mu_source.MultisetSort();
    mu_dest.MultisetSort();
    mu_key.MultisetSort();
    mu_mType.MultisetSort();
    mu_nonce1.MultisetSort();
    mu_nonce2.MultisetSort();
    mu_address.MultisetSort();
  }
  void print_statistic()
  {
    mu_source.print_statistic();
    mu_dest.print_statistic();
    mu_key.print_statistic();
    mu_mType.print_statistic();
    mu_nonce1.print_statistic();
    mu_nonce2.print_statistic();
    mu_address.print_statistic();
  }
  void clear() {
    mu_source.clear();
    mu_dest.clear();
    mu_key.clear();
    mu_mType.clear();
    mu_nonce1.clear();
    mu_nonce2.clear();
    mu_address.clear();
 };
  void undefine() {
    mu_source.undefine();
    mu_dest.undefine();
    mu_key.undefine();
    mu_mType.undefine();
    mu_nonce1.undefine();
    mu_nonce2.undefine();
    mu_address.undefine();
 };
  void reset() {
    mu_source.reset();
    mu_dest.reset();
    mu_key.reset();
    mu_mType.reset();
    mu_nonce1.reset();
    mu_nonce2.reset();
    mu_address.reset();
 };
  void print() {
    mu_source.print();
    mu_dest.print();
    mu_key.print();
    mu_mType.print();
    mu_nonce1.print();
    mu_nonce2.print();
    mu_address.print();
  };
  void print_diff(state *prevstate) {
    mu_source.print_diff(prevstate);
    mu_dest.print_diff(prevstate);
    mu_key.print_diff(prevstate);
    mu_mType.print_diff(prevstate);
    mu_nonce1.print_diff(prevstate);
    mu_nonce2.print_diff(prevstate);
    mu_address.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_source.to_state(thestate);
    mu_dest.to_state(thestate);
    mu_key.to_state(thestate);
    mu_mType.to_state(thestate);
    mu_nonce1.to_state(thestate);
    mu_nonce2.to_state(thestate);
    mu_address.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_Message& operator= (const mu_1_Message& from) {
    mu_source.value(from.mu_source.value());
    mu_dest.value(from.mu_dest.value());
    mu_key.value(from.mu_key.value());
    mu_mType.value(from.mu_mType.value());
    mu_nonce1.value(from.mu_nonce1.value());
    mu_nonce2.value(from.mu_nonce2.value());
    mu_address.value(from.mu_address.value());
    return *this;
  };
};

  void mu_1_Message::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_Message::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_Message::set_self(char *n, int os)
{
  name = n;
  mu_source.set_self_2(name, ".source", os + 0 );
  mu_dest.set_self_2(name, ".dest", os + 3 );
  mu_key.set_self_2(name, ".key", os + 6 );
  mu_mType.set_self_2(name, ".mType", os + 9 );
  mu_nonce1.set_self_2(name, ".nonce1", os + 11 );
  mu_nonce2.set_self_2(name, ".nonce2", os + 14 );
  mu_address.set_self_2(name, ".address", os + 17 );
}

mu_1_Message::~mu_1_Message()
{
}

/*** end record declaration ***/
mu_1_Message mu_1_Message_undefined_var;

class mu_1_InitiatorStates: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_InitiatorStates& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_InitiatorStates& val)
  {
    if (val.defined())
      return ( s << mu_1_InitiatorStates::values[ int(val) - 9] );
    else return ( s << "Undefined" );
  };

  mu_1_InitiatorStates (char *name, int os): mu__byte(9, 11, 2, name, os) {};
  mu_1_InitiatorStates (void): mu__byte(9, 11, 2) {};
  mu_1_InitiatorStates (int val): mu__byte(9, 11, 2, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -9]; };
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
      cout << name << ":" << values[ value() -9] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1_InitiatorStates::values[] = {"I_SLEEP","I_WAIT","I_COMMIT",NULL };

/*** end of enum declaration ***/
mu_1_InitiatorStates mu_1_InitiatorStates_undefined_var;

class mu_1_Initiator
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1_InitiatorStates mu_state;
  mu_1_AgentId mu_responder;
  mu_1_Initiator ( char *n, int os ) { set_self(n,os); };
  mu_1_Initiator ( void ) {};

  virtual ~mu_1_Initiator(); 
friend int CompareWeight(mu_1_Initiator& a, mu_1_Initiator& b)
  {
    int w;
    w = CompareWeight(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = CompareWeight(a.mu_responder, b.mu_responder);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_Initiator& a, mu_1_Initiator& b)
  {
    int w;
    w = Compare(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = Compare(a.mu_responder, b.mu_responder);
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
    mu_state.MultisetSort();
    mu_responder.MultisetSort();
  }
  void print_statistic()
  {
    mu_state.print_statistic();
    mu_responder.print_statistic();
  }
  void clear() {
    mu_state.clear();
    mu_responder.clear();
 };
  void undefine() {
    mu_state.undefine();
    mu_responder.undefine();
 };
  void reset() {
    mu_state.reset();
    mu_responder.reset();
 };
  void print() {
    mu_state.print();
    mu_responder.print();
  };
  void print_diff(state *prevstate) {
    mu_state.print_diff(prevstate);
    mu_responder.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_state.to_state(thestate);
    mu_responder.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_Initiator& operator= (const mu_1_Initiator& from) {
    mu_state.value(from.mu_state.value());
    mu_responder.value(from.mu_responder.value());
    return *this;
  };
};

  void mu_1_Initiator::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_Initiator::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_Initiator::set_self(char *n, int os)
{
  name = n;
  mu_state.set_self_2(name, ".state", os + 0 );
  mu_responder.set_self_2(name, ".responder", os + 2 );
}

mu_1_Initiator::~mu_1_Initiator()
{
}

/*** end record declaration ***/
mu_1_Initiator mu_1_Initiator_undefined_var;

class mu_1_ResponderStates: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_ResponderStates& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_ResponderStates& val)
  {
    if (val.defined())
      return ( s << mu_1_ResponderStates::values[ int(val) - 12] );
    else return ( s << "Undefined" );
  };

  mu_1_ResponderStates (char *name, int os): mu__byte(12, 14, 2, name, os) {};
  mu_1_ResponderStates (void): mu__byte(12, 14, 2) {};
  mu_1_ResponderStates (int val): mu__byte(12, 14, 2, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -12]; };
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
      cout << name << ":" << values[ value() -12] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1_ResponderStates::values[] = {"R_SLEEP","R_WAIT","R_COMMIT",NULL };

/*** end of enum declaration ***/
mu_1_ResponderStates mu_1_ResponderStates_undefined_var;

class mu_1_Responder
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1_ResponderStates mu_state;
  mu_1_AgentId mu_initiator;
  mu_1_Responder ( char *n, int os ) { set_self(n,os); };
  mu_1_Responder ( void ) {};

  virtual ~mu_1_Responder(); 
friend int CompareWeight(mu_1_Responder& a, mu_1_Responder& b)
  {
    int w;
    w = CompareWeight(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = CompareWeight(a.mu_initiator, b.mu_initiator);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_Responder& a, mu_1_Responder& b)
  {
    int w;
    w = Compare(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = Compare(a.mu_initiator, b.mu_initiator);
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
    mu_state.MultisetSort();
    mu_initiator.MultisetSort();
  }
  void print_statistic()
  {
    mu_state.print_statistic();
    mu_initiator.print_statistic();
  }
  void clear() {
    mu_state.clear();
    mu_initiator.clear();
 };
  void undefine() {
    mu_state.undefine();
    mu_initiator.undefine();
 };
  void reset() {
    mu_state.reset();
    mu_initiator.reset();
 };
  void print() {
    mu_state.print();
    mu_initiator.print();
  };
  void print_diff(state *prevstate) {
    mu_state.print_diff(prevstate);
    mu_initiator.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_state.to_state(thestate);
    mu_initiator.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_Responder& operator= (const mu_1_Responder& from) {
    mu_state.value(from.mu_state.value());
    mu_initiator.value(from.mu_initiator.value());
    return *this;
  };
};

  void mu_1_Responder::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_Responder::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_Responder::set_self(char *n, int os)
{
  name = n;
  mu_state.set_self_2(name, ".state", os + 0 );
  mu_initiator.set_self_2(name, ".initiator", os + 2 );
}

mu_1_Responder::~mu_1_Responder()
{
}

/*** end record declaration ***/
mu_1_Responder mu_1_Responder_undefined_var;

class mu_1__type_0
{
 public:
  mu_0_boolean array[ 5 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_0 (char *n, int os) { set_self(n, os); };
  mu_1__type_0 ( void ) {};
  virtual ~mu_1__type_0 ();
  mu_0_boolean& operator[] (int index) /* const */
  {
    if ( ( index >= 1 ) && ( index <= 1 ) )
      return array[ index - (1) ];
    if ( ( index >= 2 ) && ( index <= 2 ) )
      return array[ index - (1) ];
    if ( ( index >= 3 ) && ( index <= 5 ) )
      return array[ index - (1) ];
    if (index==UNDEFVAL) 
      Error.Error("Indexing to %s using an undefined value.", name);
    else
      Error.Error("Funny index value %d for %s. (Internal Error in Type Checking.",index, name);
    return array[0];
  }
  mu_1__type_0& operator= (const mu_1__type_0& from)
  {
    for (int i = 0; i < 5; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1__type_0& a, mu_1__type_0& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_0& a, mu_1__type_0& b)
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
    int i=0;
    name = n;
array[i].set_self_ar(n,"InitiatorId_1", i * 2 + os);i++;
array[i].set_self_ar(n,"ResponderId_1", i * 2 + os);i++;
array[i].set_self_ar(n,"IntruderId_1", i * 2 + os);i++;
array[i].set_self_ar(n,"IntruderId_2", i * 2 + os);i++;
array[i].set_self_ar(n,"IntruderId_3", i * 2 + os);i++;
}
mu_1__type_0::~mu_1__type_0()
{
}
/*** end array declaration ***/
mu_1__type_0 mu_1__type_0_undefined_var;

/*** begin multiset declaration ***/
class mu_1__type_1_id: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_1_id& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  mu_1__type_1_id () : mu__byte(0,9,0) {};
  mu_1__type_1_id (int val) : mu__byte(0,9,0, "Parameter or function result.",0) {operator=(val); };
  char * Name() { return tsprintf("%d", value()); };
};
class mu_1__type_1
{
 public:
  mu_1_Message array[ 10 ];
  int max_size;
  int current_size;
 public:
  mu_0_boolean valid[ 10 ];
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_1 (char *n, int os): current_size(0), max_size(0) { set_self(n, os); };
  mu_1__type_1 ( void ): current_size(0), max_size(0) {};
  virtual ~mu_1__type_1 ();
  mu_1_Message& operator[] (int index) /* const */
  {
    if ((index >= 0) && (index <= 9) && valid[index].value())
      return array[ index ];
    else {
      Error.Error("Internal Error::%d not in index range of %s.", index, name);
      return array[0];
    }
  };
  mu_1__type_1& operator= (const mu_1__type_1& from)
  {
    for (int i = 0; i < 10; i++)
    {
       array[i] = from.array[i];
       valid[i].value(from.valid[i].value());
    };
    current_size = from.get_current_size();
    return *this;
  }

friend int CompareWeight(mu_1__type_1& a, mu_1__type_1& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_1& a, mu_1__type_1& b)
  {
    int w;
    for (int i=0; i<10; i++) {
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
  void clear() { for (int i = 0; i < 10; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void undefine() { for (int i = 0; i < 10; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void reset() { for (int i = 0; i < 10; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 10; i++)
     {
       array[i].to_state(thestate);
       valid[i].to_state(thestate);
     }
  };

  int get_current_size() const  {
    int tmp = 0;
    for (int i = 0; i < 10; i++)
      if (valid[i].value()) tmp++;
    return tmp;
  };

   void update_size()
  {
    current_size = 0;
    for (int i = 0; i < 10; i++)
      if (valid[i].value()) current_size++;
    if (max_size<current_size) max_size = current_size;
  };

   inline bool in(const mu_1__type_1_id& id)
  { return valid[(int)id].value(); }
  void print()
  {
    for (int i = 0; i < 10; i++)
      if (valid[i].value())
        array[i].print();
  };

  void print_statistic()
  {
    cout << "	The maximum size for the multiset \"" 
         << name << "\" is: " << max_size << ".\n"; 
  };
  void print_diff(state *prevstate)
  {
    bool prevvalid;
    static state temp;
    StateCopy(&temp, workingstate);
    for (int i = 0; i < 10; i++)
      {
        StateCopy(workingstate, prevstate);
        prevvalid = valid[i].value();
        StateCopy(workingstate, &temp);
        if (prevvalid && !valid[i].value())
          array[i].print();
        if (!prevvalid && valid[i].value())
          array[i].print();
        if (prevvalid && valid[i].value())
          array[i].print_diff(prevstate);
      }
  };
  int multisetadd(const mu_1_Message &element)
  {
    update_size();
    if (current_size >= 10) Error.Error("Maximum size of MultiSet (%s) exceeded.",name);
    int i;
    for (i = 0; i < 10; i++)
      if (!valid[i].value())
        {
          array[i] = element;
          valid[i].value(TRUE);
          break;
        }
    current_size++;
    return i;
  };
  void multisetremove(const mu_1__type_1_id &id)
  {
    update_size();
    if (!valid[(int)id].value()) Error.Error("Internal Error: Illegal Multiset element selected.");
    valid[(int)id].value(FALSE);
    array[(int)id].undefine();
    current_size--;
  };
  void MultisetSort()
  {
    static mu_1_Message temp;

    // compact
    int i,j;
    for (i = 0, j = 0; i < 10; i++)
      if (valid[i].value())
        {
          if (j!=i)
            array[j++] = array[i];
          else
            j++;
        }
    if (j != current_size) current_size = j;
    for (i = j; i < 10; i++)
      array[i].undefine();
    for (i = 0; i < j; i++)
      valid[i].value(TRUE);
    for (i = j; i < 10; i++)
      valid[i].value(FALSE);

    // bubble sort
    for (i = 0; i < current_size; i++)
      for (j = i+1; j < current_size; j++)
        if (Compare(array[i],array[j])>0)
          {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
          }
  }
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
  int i,k;
  name = n;
  for(i = 0; i < 10; i++)
    array[i].set_self(tsprintf("%s{%d}", n,i), i * 20 + os);
  k = os + i * 20;
  for(i = 0; i < 10; i++)
    valid[i].set_self("", i * 2 + k);
};
mu_1__type_1::~mu_1__type_1()
{
}
/*** end multiset declaration ***/
mu_1__type_1 mu_1__type_1_undefined_var;

class mu_1_Intruder
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1__type_0 mu_nonces;
  mu_1__type_1 mu_messages;
  mu_1_Intruder ( char *n, int os ) { set_self(n,os); };
  mu_1_Intruder ( void ) {};

  virtual ~mu_1_Intruder(); 
friend int CompareWeight(mu_1_Intruder& a, mu_1_Intruder& b)
  {
    int w;
    w = CompareWeight(a.mu_nonces, b.mu_nonces);
    if (w!=0) return w;
    w = CompareWeight(a.mu_messages, b.mu_messages);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_Intruder& a, mu_1_Intruder& b)
  {
    int w;
    w = Compare(a.mu_nonces, b.mu_nonces);
    if (w!=0) return w;
    w = Compare(a.mu_messages, b.mu_messages);
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
    mu_nonces.MultisetSort();
    mu_messages.MultisetSort();
  }
  void print_statistic()
  {
    mu_nonces.print_statistic();
    mu_messages.print_statistic();
  }
  void clear() {
    mu_nonces.clear();
    mu_messages.clear();
 };
  void undefine() {
    mu_nonces.undefine();
    mu_messages.undefine();
 };
  void reset() {
    mu_nonces.reset();
    mu_messages.reset();
 };
  void print() {
    mu_nonces.print();
    mu_messages.print();
  };
  void print_diff(state *prevstate) {
    mu_nonces.print_diff(prevstate);
    mu_messages.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_nonces.to_state(thestate);
    mu_messages.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_Intruder& operator= (const mu_1_Intruder& from) {
    mu_nonces = from.mu_nonces;
    mu_messages = from.mu_messages;
    return *this;
  };
};

  void mu_1_Intruder::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_Intruder::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_Intruder::set_self(char *n, int os)
{
  name = n;
  mu_nonces.set_self_2(name, ".nonces", os + 0 );
  mu_messages.set_self_2(name, ".messages", os + 10 );
}

mu_1_Intruder::~mu_1_Intruder()
{
}

/*** end record declaration ***/
mu_1_Intruder mu_1_Intruder_undefined_var;

/*** begin multiset declaration ***/
class mu_1__type_2_id: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_2_id& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  mu_1__type_2_id () : mu__byte(0,1,0) {};
  mu_1__type_2_id (int val) : mu__byte(0,1,0, "Parameter or function result.",0) {operator=(val); };
  char * Name() { return tsprintf("%d", value()); };
};
class mu_1__type_2
{
 public:
  mu_1_Message array[ 2 ];
  int max_size;
  int current_size;
 public:
  mu_0_boolean valid[ 2 ];
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_2 (char *n, int os): current_size(0), max_size(0) { set_self(n, os); };
  mu_1__type_2 ( void ): current_size(0), max_size(0) {};
  virtual ~mu_1__type_2 ();
  mu_1_Message& operator[] (int index) /* const */
  {
    if ((index >= 0) && (index <= 1) && valid[index].value())
      return array[ index ];
    else {
      Error.Error("Internal Error::%d not in index range of %s.", index, name);
      return array[0];
    }
  };
  mu_1__type_2& operator= (const mu_1__type_2& from)
  {
    for (int i = 0; i < 2; i++)
    {
       array[i] = from.array[i];
       valid[i].value(from.valid[i].value());
    };
    current_size = from.get_current_size();
    return *this;
  }

friend int CompareWeight(mu_1__type_2& a, mu_1__type_2& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_2& a, mu_1__type_2& b)
  {
    int w;
    for (int i=0; i<2; i++) {
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
  void clear() { for (int i = 0; i < 2; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void undefine() { for (int i = 0; i < 2; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void reset() { for (int i = 0; i < 2; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 2; i++)
     {
       array[i].to_state(thestate);
       valid[i].to_state(thestate);
     }
  };

  int get_current_size() const  {
    int tmp = 0;
    for (int i = 0; i < 2; i++)
      if (valid[i].value()) tmp++;
    return tmp;
  };

   void update_size()
  {
    current_size = 0;
    for (int i = 0; i < 2; i++)
      if (valid[i].value()) current_size++;
    if (max_size<current_size) max_size = current_size;
  };

   inline bool in(const mu_1__type_2_id& id)
  { return valid[(int)id].value(); }
  void print()
  {
    for (int i = 0; i < 2; i++)
      if (valid[i].value())
        array[i].print();
  };

  void print_statistic()
  {
    cout << "	The maximum size for the multiset \"" 
         << name << "\" is: " << max_size << ".\n"; 
  };
  void print_diff(state *prevstate)
  {
    bool prevvalid;
    static state temp;
    StateCopy(&temp, workingstate);
    for (int i = 0; i < 2; i++)
      {
        StateCopy(workingstate, prevstate);
        prevvalid = valid[i].value();
        StateCopy(workingstate, &temp);
        if (prevvalid && !valid[i].value())
          array[i].print();
        if (!prevvalid && valid[i].value())
          array[i].print();
        if (prevvalid && valid[i].value())
          array[i].print_diff(prevstate);
      }
  };
  int multisetadd(const mu_1_Message &element)
  {
    update_size();
    if (current_size >= 2) Error.Error("Maximum size of MultiSet (%s) exceeded.",name);
    int i;
    for (i = 0; i < 2; i++)
      if (!valid[i].value())
        {
          array[i] = element;
          valid[i].value(TRUE);
          break;
        }
    current_size++;
    return i;
  };
  void multisetremove(const mu_1__type_2_id &id)
  {
    update_size();
    if (!valid[(int)id].value()) Error.Error("Internal Error: Illegal Multiset element selected.");
    valid[(int)id].value(FALSE);
    array[(int)id].undefine();
    current_size--;
  };
  void MultisetSort()
  {
    static mu_1_Message temp;

    // compact
    int i,j;
    for (i = 0, j = 0; i < 2; i++)
      if (valid[i].value())
        {
          if (j!=i)
            array[j++] = array[i];
          else
            j++;
        }
    if (j != current_size) current_size = j;
    for (i = j; i < 2; i++)
      array[i].undefine();
    for (i = 0; i < j; i++)
      valid[i].value(TRUE);
    for (i = j; i < 2; i++)
      valid[i].value(FALSE);

    // bubble sort
    for (i = 0; i < current_size; i++)
      for (j = i+1; j < current_size; j++)
        if (Compare(array[i],array[j])>0)
          {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
          }
  }
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
void mu_1__type_2::set_self( char *n, int os)
{
  int i,k;
  name = n;
  for(i = 0; i < 2; i++)
    array[i].set_self(tsprintf("%s{%d}", n,i), i * 20 + os);
  k = os + i * 20;
  for(i = 0; i < 2; i++)
    valid[i].set_self("", i * 2 + k);
};
mu_1__type_2::~mu_1__type_2()
{
}
/*** end multiset declaration ***/
mu_1__type_2 mu_1__type_2_undefined_var;

class mu_1__type_3
{
 public:
  mu_1_Initiator array[ 1 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_3 (char *n, int os) { set_self(n, os); };
  mu_1__type_3 ( void ) {};
  virtual ~mu_1__type_3 ();
  mu_1_Initiator& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 1 ) )
      return array[ index - 1 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: InitiatorId is internally represented from 1 to 1.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 1 ];
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
array[i].set_self_ar(n,"InitiatorId_1", i * 5 + os);i++;
}
mu_1__type_3::~mu_1__type_3()
{
}
/*** end array declaration ***/
mu_1__type_3 mu_1__type_3_undefined_var;

class mu_1__type_4
{
 public:
  mu_1_Responder array[ 1 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_4 (char *n, int os) { set_self(n, os); };
  mu_1__type_4 ( void ) {};
  virtual ~mu_1__type_4 ();
  mu_1_Responder& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 2 ) && ( index <= 2 ) )
      return array[ index - 2 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: ResponderId is internally represented from 2 to 2.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 2 ];
#endif
  };
  mu_1__type_4& operator= (const mu_1__type_4& from)
  {
      array[0] = from.array[0];
    return *this;
  }

friend int CompareWeight(mu_1__type_4& a, mu_1__type_4& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_4& a, mu_1__type_4& b)
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
void mu_1__type_4::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"ResponderId_1", i * 5 + os);i++;
}
mu_1__type_4::~mu_1__type_4()
{
}
/*** end array declaration ***/
mu_1__type_4 mu_1__type_4_undefined_var;

class mu_1__type_5
{
 public:
  mu_1_Intruder array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_5 (char *n, int os) { set_self(n, os); };
  mu_1__type_5 ( void ) {};
  virtual ~mu_1__type_5 ();
  mu_1_Intruder& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 3 ) && ( index <= 5 ) )
      return array[ index - 3 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: IntruderId is internally represented from 5 to 3.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 3 ];
#endif
  };
  mu_1__type_5& operator= (const mu_1__type_5& from)
  {
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_5& a, mu_1__type_5& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_5& a, mu_1__type_5& b)
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
array[i].set_self_ar(n,"IntruderId_1", i * 230 + os);i++;
array[i].set_self_ar(n,"IntruderId_2", i * 230 + os);i++;
array[i].set_self_ar(n,"IntruderId_3", i * 230 + os);i++;
}
mu_1__type_5::~mu_1__type_5()
{
}
/*** end array declaration ***/
mu_1__type_5 mu_1__type_5_undefined_var;

const int mu_FIXED = 1;
const int mu_NumInitiators = 1;
const int mu_NumResponders = 1;
const int mu_NumIntruders = 3;
const int mu_NetworkSize = 2;
const int mu_MaxKnowledge = 10;
const int mu_InitiatorId_1 = 1;
const int mu_ResponderId_1 = 2;
const int mu_IntruderId_1 = 3;
const int mu_IntruderId_2 = 4;
const int mu_IntruderId_3 = 5;
const int mu_M_NonceAddress = 6;
const int mu_M_NonceNonceAddress = 7;
const int mu_M_Nonce = 8;
const int mu_I_SLEEP = 9;
const int mu_I_WAIT = 10;
const int mu_I_COMMIT = 11;
const int mu_R_SLEEP = 12;
const int mu_R_WAIT = 13;
const int mu_R_COMMIT = 14;
/*** Variable declaration ***/
mu_1__type_2 mu_net("net",0);

/*** Variable declaration ***/
mu_1__type_3 mu_ini("ini",44);

/*** Variable declaration ***/
mu_1__type_4 mu_res("res",49);

/*** Variable declaration ***/
mu_1__type_5 mu_int("int",54);





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_net.clear();
  mu_ini.clear();
  mu_res.clear();
  mu_int.clear();
}
void world_class::undefine()
{
  mu_net.undefine();
  mu_ini.undefine();
  mu_res.undefine();
  mu_int.undefine();
}
void world_class::reset()
{
  mu_net.reset();
  mu_ini.reset();
  mu_res.reset();
  mu_int.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_net.print();
  mu_ini.print();
  mu_res.print();
  mu_int.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_net.print_statistic();
  mu_ini.print_statistic();
  mu_res.print_statistic();
  mu_int.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_net.print_diff(prevstate);
    mu_ini.print_diff(prevstate);
    mu_res.print_diff(prevstate);
    mu_int.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_net.to_state( newstate );
  mu_ini.to_state( newstate );
  mu_res.to_state( newstate );
  mu_int.to_state( newstate );
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
    return 90;
  }
  char * Name(unsigned r)
  {
    static mu_1_MessageType mu_l;
    mu_l.value((r % 3) + 6);
    r = r / 3;
    static mu_1_AgentId mu_o;
    mu_o.unionassign(r % 5);
    r = r / 5;
    static mu_1_AgentId mu_n;
    mu_n.unionassign(r % 5);
    r = r / 5;
    static mu_1_AgentId mu_m;
    mu_m.unionassign(r % 5);
    r = r / 5;
    static mu_1_AgentId mu_j;
    mu_j.unionassign(r % 5);
    r = r / 5;
    static mu_1_IntruderId mu_i;
    mu_i.value((r % 3) + 3);
    r = r / 3;
    return tsprintf("intruder generates message, l:%s, o:%s, n:%s, m:%s, j:%s, i:%s", mu_l.Name(), mu_o.Name(), mu_n.Name(), mu_m.Name(), mu_j.Name(), mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_MessageType mu_l;
    mu_l.value((r % 3) + 6);
    r = r / 3;
    static mu_1_AgentId mu_o;
    mu_o.unionassign(r % 5);
    r = r / 5;
    static mu_1_AgentId mu_n;
    mu_n.unionassign(r % 5);
    r = r / 5;
    static mu_1_AgentId mu_m;
    mu_m.unionassign(r % 5);
    r = r / 5;
    static mu_1_AgentId mu_j;
    mu_j.unionassign(r % 5);
    r = r / 5;
    static mu_1_IntruderId mu_i;
    mu_i.value((r % 3) + 3);
    r = r / 3;
bool mu__boolexpr6;
bool mu__boolexpr7;
bool mu__boolexpr8;
  if (!(!((mu_j>=3 && mu_j<=5)))) mu__boolexpr8 = FALSE ;
  else {
  mu__boolexpr8 = ((mu_int[mu_i].mu_nonces[mu_m]) == (mu_true)) ; 
}
  if (!(mu__boolexpr8)) mu__boolexpr7 = FALSE ;
  else {
  mu__boolexpr7 = ((mu_int[mu_i].mu_nonces[mu_n]) == (mu_true)) ; 
}
  if (!(mu__boolexpr7)) mu__boolexpr6 = FALSE ;
  else {
/*** begin multisetcount 3 declaration ***/
  int mu__intexpr9 = 0;
  {
  mu_1__type_2_id mu_t;
  for (mu_t = 0; ; mu_t=mu_t+1)
    {
      if (mu_net.valid[(int)mu_t].value())
        {
          if ( mu_true ) mu__intexpr9++;
        }
      if (mu_t == 2-1) break;
    }
  }
/*** end multisetcount 3 declaration ***/
  mu__boolexpr6 = ((mu__intexpr9) < (mu_NetworkSize)) ; 
}
  return mu__boolexpr6;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    static mu_1_MessageType mu_l;
    mu_l.value((r % 3) + 6);
    r = r / 3;
    static mu_1_AgentId mu_o;
    mu_o.unionassign(r % 5);
    r = r / 5;
    static mu_1_AgentId mu_n;
    mu_n.unionassign(r % 5);
    r = r / 5;
    static mu_1_AgentId mu_m;
    mu_m.unionassign(r % 5);
    r = r / 5;
    static mu_1_AgentId mu_j;
    mu_j.unionassign(r % 5);
    r = r / 5;
    static mu_1_IntruderId mu_i;
    mu_i.value((r % 3) + 3);
    r = r / 3;
    while (what_rule < 5625 )
      {
        if ( ( TRUE  ) ) {
bool mu__boolexpr10;
bool mu__boolexpr11;
bool mu__boolexpr12;
  if (!(!((mu_j>=3 && mu_j<=5)))) mu__boolexpr12 = FALSE ;
  else {
  mu__boolexpr12 = ((mu_int[mu_i].mu_nonces[mu_m]) == (mu_true)) ; 
}
  if (!(mu__boolexpr12)) mu__boolexpr11 = FALSE ;
  else {
  mu__boolexpr11 = ((mu_int[mu_i].mu_nonces[mu_n]) == (mu_true)) ; 
}
  if (!(mu__boolexpr11)) mu__boolexpr10 = FALSE ;
  else {
/*** begin multisetcount 3 declaration ***/
  int mu__intexpr13 = 0;
  {
  mu_1__type_2_id mu_t;
  for (mu_t = 0; ; mu_t=mu_t+1)
    {
      if (mu_net.valid[(int)mu_t].value())
        {
          if ( mu_true ) mu__intexpr13++;
        }
      if (mu_t == 2-1) break;
    }
  }
/*** end multisetcount 3 declaration ***/
  mu__boolexpr10 = ((mu__intexpr13) < (mu_NetworkSize)) ; 
}
              if (mu__boolexpr10) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 15;
        }
        else
          what_rule += 15;
    r = what_rule - 0;
    mu_l.value((r % 3) + 6);
    r = r / 3;
    mu_o.unionassign(r % 5);
    r = r / 5;
    mu_n.unionassign(r % 5);
    r = r / 5;
    mu_m.unionassign(r % 5);
    r = r / 5;
    mu_j.unionassign(r % 5);
    r = r / 5;
    mu_i.value((r % 3) + 3);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_MessageType mu_l;
    mu_l.value((r % 3) + 6);
    r = r / 3;
    static mu_1_AgentId mu_o;
    mu_o.unionassign(r % 5);
    r = r / 5;
    static mu_1_AgentId mu_n;
    mu_n.unionassign(r % 5);
    r = r / 5;
    static mu_1_AgentId mu_m;
    mu_m.unionassign(r % 5);
    r = r / 5;
    static mu_1_AgentId mu_j;
    mu_j.unionassign(r % 5);
    r = r / 5;
    static mu_1_IntruderId mu_i;
    mu_i.value((r % 3) + 3);
    r = r / 3;
/*** Variable declaration ***/
mu_1_Message mu_outM("outM",0);

mu_outM.undefine();
mu_outM.mu_source = mu_i;
mu_outM.mu_dest = mu_j;
mu_outM.mu_key = mu_j;
mu_outM.mu_mType = mu_l;
switch ((int) mu_l) {
case mu_M_NonceAddress:
mu_outM.mu_nonce1 = mu_m;
mu_outM.mu_nonce2 = mu_o;
break;
case mu_M_NonceNonceAddress:
mu_outM.mu_nonce1 = mu_m;
mu_outM.mu_nonce2 = mu_n;
mu_outM.mu_address = mu_o;
break;
case mu_M_Nonce:
mu_outM.mu_nonce1 = mu_m;
break;
}
mu_net.multisetadd(mu_outM);
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
    return 90;
  }
  char * Name(unsigned r)
  {
    static mu_1_IntruderId mu_i;
    mu_i.value((r % 3) + 3);
    r = r / 3;
    static mu_1__type_1_id mu_j;
    mu_j.value((r % 10) + 0);
    r = r / 10;
    static mu_1_AgentId mu_k;
    mu_k.unionassign(r % 5);
    r = r / 5;
    return tsprintf("intruder sends recorded message, i:%s, j:%s, k:%s", mu_i.Name(), mu_j.Name(), mu_k.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_IntruderId mu_i;
    mu_i.value((r % 3) + 3);
    r = r / 3;
    static mu_1__type_1_id mu_j;
    mu_j.value((r % 10) + 0);
    r = r / 10;
    static mu_1_AgentId mu_k;
    mu_k.unionassign(r % 5);
    r = r / 5;
  if (!mu_int[mu_i].mu_messages.in(mu_j)) { return FALSE; }
bool mu__boolexpr14;
  if (!(!((mu_k>=3 && mu_k<=5)))) mu__boolexpr14 = FALSE ;
  else {
/*** begin multisetcount 2 declaration ***/
  int mu__intexpr15 = 0;
  {
  mu_1__type_2_id mu_l;
  for (mu_l = 0; ; mu_l=mu_l+1)
    {
      if (mu_net.valid[(int)mu_l].value())
        {
          if ( mu_true ) mu__intexpr15++;
        }
      if (mu_l == 2-1) break;
    }
  }
/*** end multisetcount 2 declaration ***/
  mu__boolexpr14 = ((mu__intexpr15) < (mu_NetworkSize)) ; 
}
  return mu__boolexpr14;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 5625;
    static mu_1_IntruderId mu_i;
    mu_i.value((r % 3) + 3);
    r = r / 3;
    static mu_1__type_1_id mu_j;
    mu_j.value((r % 10) + 0);
    r = r / 10;
    static mu_1_AgentId mu_k;
    mu_k.unionassign(r % 5);
    r = r / 5;
    while (what_rule < 5775 && mu_j.value()<10 )
      {
        if ( ( TRUE  ) ) {
bool mu__boolexpr16;
  if (!(!((mu_k>=3 && mu_k<=5)))) mu__boolexpr16 = FALSE ;
  else {
/*** begin multisetcount 2 declaration ***/
  int mu__intexpr17 = 0;
  {
  mu_1__type_2_id mu_l;
  for (mu_l = 0; ; mu_l=mu_l+1)
    {
      if (mu_net.valid[(int)mu_l].value())
        {
          if ( mu_true ) mu__intexpr17++;
        }
      if (mu_l == 2-1) break;
    }
  }
/*** end multisetcount 2 declaration ***/
  mu__boolexpr16 = ((mu__intexpr17) < (mu_NetworkSize)) ; 
}
              if (mu__boolexpr16) {
                if ( ( TRUE && mu_int[mu_i].mu_messages.in(mu_j) ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 30;
        }
        else
          what_rule += 30;
    r = what_rule - 5625;
    mu_i.value((r % 3) + 3);
    r = r / 3;
    mu_j.value((r % 10) + 0);
    r = r / 10;
    mu_k.unionassign(r % 5);
    r = r / 5;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_IntruderId mu_i;
    mu_i.value((r % 3) + 3);
    r = r / 3;
    static mu_1__type_1_id mu_j;
    mu_j.value((r % 10) + 0);
    r = r / 10;
    static mu_1_AgentId mu_k;
    mu_k.unionassign(r % 5);
    r = r / 5;
/*** Variable declaration ***/
mu_1_Message mu_outM("outM",0);

mu_outM = mu_int[mu_i].mu_messages[mu_j];
mu_outM.mu_source = mu_i;
mu_outM.mu_dest = mu_k;
mu_net.multisetadd(mu_outM);
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
    return 10;
  }
  char * Name(unsigned r)
  {
    static mu_1_IntruderId mu_i;
    mu_i.value((r % 3) + 3);
    r = r / 3;
    static mu_1__type_2_id mu_j;
    mu_j.value((r % 2) + 0);
    r = r / 2;
    return tsprintf("intruder intercepts, i:%s, j:%s", mu_i.Name(), mu_j.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_IntruderId mu_i;
    mu_i.value((r % 3) + 3);
    r = r / 3;
    static mu_1__type_2_id mu_j;
    mu_j.value((r % 2) + 0);
    r = r / 2;
  if (!mu_net.in(mu_j)) { return FALSE; }
  return !((mu_net[mu_j].mu_source>=3 && mu_net[mu_j].mu_source<=5));
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 5775;
    static mu_1_IntruderId mu_i;
    mu_i.value((r % 3) + 3);
    r = r / 3;
    static mu_1__type_2_id mu_j;
    mu_j.value((r % 2) + 0);
    r = r / 2;
    while (what_rule < 5781 && mu_j.value()<2 )
      {
        if ( ( TRUE && mu_net.in(mu_j) ) ) {
              if (!((mu_net[mu_j].mu_source>=3 && mu_net[mu_j].mu_source<=5))) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 3;
        }
        else
          what_rule += 3;
    r = what_rule - 5775;
    mu_i.value((r % 3) + 3);
    r = r / 3;
    mu_j.value((r % 2) + 0);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_IntruderId mu_i;
    mu_i.value((r % 3) + 3);
    r = r / 3;
    static mu_1__type_2_id mu_j;
    mu_j.value((r % 2) + 0);
    r = r / 2;
/*** Variable declaration ***/
mu_1_Message mu_temp("temp",0);

{
  mu_1_Message& mu_msg = mu_net[mu_j];
if ( (mu_msg.mu_key) == (mu_i) )
{
mu_int[mu_i].mu_nonces[mu_msg.mu_nonce1] = mu_true;
if ( (mu_msg.mu_mType) == (mu_M_NonceNonceAddress) )
{
mu_int[mu_i].mu_nonces[mu_msg.mu_nonce2] = mu_true;
}
}
else
{
{
  mu_1__type_1& mu_messages = mu_int[mu_i].mu_messages;
mu_temp = mu_msg;
mu_temp.mu_source.undefine();
mu_temp.mu_dest.undefine();
/*** begin multisetcount 1 declaration ***/
  int mu__intexpr18 = 0;
  {
  mu_1__type_1_id mu_l;
  for (mu_l = 0; ; mu_l=mu_l+1)
    {
      if (mu_messages.valid[(int)mu_l].value())
        {
bool mu__boolexpr19;
bool mu__boolexpr20;
bool mu__boolexpr21;
bool mu__boolexpr22;
  if (!((mu_messages[mu_l].mu_key) == (mu_temp.mu_key))) mu__boolexpr22 = FALSE ;
  else {
  mu__boolexpr22 = ((mu_messages[mu_l].mu_mType) == (mu_temp.mu_mType)) ; 
}
  if (!(mu__boolexpr22)) mu__boolexpr21 = FALSE ;
  else {
  mu__boolexpr21 = ((mu_messages[mu_l].mu_nonce1) == (mu_temp.mu_nonce1)) ; 
}
  if (!(mu__boolexpr21)) mu__boolexpr20 = FALSE ;
  else {
bool mu__boolexpr23;
  if (!((mu_messages[mu_l].mu_mType) != (mu_M_Nonce))) mu__boolexpr23 = TRUE ;
  else {
  mu__boolexpr23 = ((mu_messages[mu_l].mu_nonce2) == (mu_temp.mu_nonce2)) ; 
}
  mu__boolexpr20 = (mu__boolexpr23) ; 
}
  if (!(mu__boolexpr20)) mu__boolexpr19 = FALSE ;
  else {
bool mu__boolexpr24;
  if (!((mu_messages[mu_l].mu_mType) == (mu_M_NonceNonceAddress))) mu__boolexpr24 = TRUE ;
  else {
  mu__boolexpr24 = ((mu_messages[mu_l].mu_address) == (mu_temp.mu_address)) ; 
}
  mu__boolexpr19 = (mu__boolexpr24) ; 
}
          if ( mu__boolexpr19 ) mu__intexpr18++;
        }
      if (mu_l == 10-1) break;
    }
  }
/*** end multisetcount 1 declaration ***/
if ( (mu__intexpr18) == (0) )
{
mu_int[mu_i].mu_messages.multisetadd(mu_temp);
}
}
}
mu_net.multisetremove(mu_j);
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
    return 20;
  }
  char * Name(unsigned r)
  {
    static mu_1__type_2_id mu_j;
    mu_j.value((r % 2) + 0);
    r = r / 2;
    static mu_1_ResponderId mu_i;
    mu_i.value((r % 1) + 2);
    r = r / 1;
    return tsprintf("responder reacts to own nonce (step 7), j:%s, i:%s", mu_j.Name(), mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1__type_2_id mu_j;
    mu_j.value((r % 2) + 0);
    r = r / 2;
    static mu_1_ResponderId mu_i;
    mu_i.value((r % 1) + 2);
    r = r / 1;
  if (!mu_net.in(mu_j)) { return FALSE; }
bool mu__boolexpr25;
bool mu__boolexpr26;
  if (!((mu_res[mu_i].mu_state) == (mu_R_WAIT))) mu__boolexpr26 = FALSE ;
  else {
  mu__boolexpr26 = ((mu_net[mu_j].mu_dest) == (mu_i)) ; 
}
  if (!(mu__boolexpr26)) mu__boolexpr25 = FALSE ;
  else {
  mu__boolexpr25 = ((mu_net[mu_j].mu_source>=3 && mu_net[mu_j].mu_source<=5)) ; 
}
  return mu__boolexpr25;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 5781;
    static mu_1__type_2_id mu_j;
    mu_j.value((r % 2) + 0);
    r = r / 2;
    static mu_1_ResponderId mu_i;
    mu_i.value((r % 1) + 2);
    r = r / 1;
    while (what_rule < 5783 && mu_j.value()<2 )
      {
        if ( ( TRUE && mu_net.in(mu_j) ) ) {
bool mu__boolexpr27;
bool mu__boolexpr28;
  if (!((mu_res[mu_i].mu_state) == (mu_R_WAIT))) mu__boolexpr28 = FALSE ;
  else {
  mu__boolexpr28 = ((mu_net[mu_j].mu_dest) == (mu_i)) ; 
}
  if (!(mu__boolexpr28)) mu__boolexpr27 = FALSE ;
  else {
  mu__boolexpr27 = ((mu_net[mu_j].mu_source>=3 && mu_net[mu_j].mu_source<=5)) ; 
}
              if (mu__boolexpr27) {
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
    r = what_rule - 5781;
    mu_j.value((r % 2) + 0);
    r = r / 2;
    mu_i.value((r % 1) + 2);
    r = r / 1;
    }
  }

  void Code(unsigned r)
  {
    static mu_1__type_2_id mu_j;
    mu_j.value((r % 2) + 0);
    r = r / 2;
    static mu_1_ResponderId mu_i;
    mu_i.value((r % 1) + 2);
    r = r / 1;
{
  mu_1_Message& mu_inM = mu_net[mu_j];
if ( (mu_inM.mu_key) == (mu_i) )
{
if ( (mu_inM.mu_mType) == (mu_M_Nonce) )
{
if ( (mu_inM.mu_nonce1) == (mu_i) )
{
mu_res[mu_i].mu_state = mu_R_COMMIT;
}
}
}
mu_net.multisetremove(mu_j);
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
    return 20;
  }
  char * Name(unsigned r)
  {
    static mu_1__type_2_id mu_j;
    mu_j.value((r % 2) + 0);
    r = r / 2;
    static mu_1_ResponderId mu_i;
    mu_i.value((r % 1) + 2);
    r = r / 1;
    return tsprintf("responder reacts to initiator's nonce (steps 3/6), j:%s, i:%s", mu_j.Name(), mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1__type_2_id mu_j;
    mu_j.value((r % 2) + 0);
    r = r / 2;
    static mu_1_ResponderId mu_i;
    mu_i.value((r % 1) + 2);
    r = r / 1;
  if (!mu_net.in(mu_j)) { return FALSE; }
bool mu__boolexpr29;
bool mu__boolexpr30;
  if (!((mu_res[mu_i].mu_state) == (mu_R_SLEEP))) mu__boolexpr30 = FALSE ;
  else {
  mu__boolexpr30 = ((mu_net[mu_j].mu_dest) == (mu_i)) ; 
}
  if (!(mu__boolexpr30)) mu__boolexpr29 = FALSE ;
  else {
  mu__boolexpr29 = ((mu_net[mu_j].mu_source>=3 && mu_net[mu_j].mu_source<=5)) ; 
}
  return mu__boolexpr29;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 5783;
    static mu_1__type_2_id mu_j;
    mu_j.value((r % 2) + 0);
    r = r / 2;
    static mu_1_ResponderId mu_i;
    mu_i.value((r % 1) + 2);
    r = r / 1;
    while (what_rule < 5785 && mu_j.value()<2 )
      {
        if ( ( TRUE && mu_net.in(mu_j) ) ) {
bool mu__boolexpr31;
bool mu__boolexpr32;
  if (!((mu_res[mu_i].mu_state) == (mu_R_SLEEP))) mu__boolexpr32 = FALSE ;
  else {
  mu__boolexpr32 = ((mu_net[mu_j].mu_dest) == (mu_i)) ; 
}
  if (!(mu__boolexpr32)) mu__boolexpr31 = FALSE ;
  else {
  mu__boolexpr31 = ((mu_net[mu_j].mu_source>=3 && mu_net[mu_j].mu_source<=5)) ; 
}
              if (mu__boolexpr31) {
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
    r = what_rule - 5783;
    mu_j.value((r % 2) + 0);
    r = r / 2;
    mu_i.value((r % 1) + 2);
    r = r / 1;
    }
  }

  void Code(unsigned r)
  {
    static mu_1__type_2_id mu_j;
    mu_j.value((r % 2) + 0);
    r = r / 2;
    static mu_1_ResponderId mu_i;
    mu_i.value((r % 1) + 2);
    r = r / 1;
/*** Variable declaration ***/
mu_1_Message mu_outM("outM",0);

/*** Variable declaration ***/
mu_1_Message mu_inM("inM",20);

mu_inM = mu_net[mu_j];
mu_net.multisetremove(mu_j);
if ( (mu_inM.mu_key) == (mu_i) )
{
if ( (mu_inM.mu_mType) == (mu_M_NonceAddress) )
{
mu_outM.undefine();
mu_outM.mu_source = mu_i;
mu_outM.mu_dest = mu_inM.mu_nonce2;
mu_outM.mu_key = mu_inM.mu_nonce2;
mu_outM.mu_mType = mu_M_NonceNonceAddress;
mu_outM.mu_nonce1 = mu_inM.mu_nonce1;
mu_outM.mu_nonce2 = mu_i;
mu_outM.mu_address = mu_i;
mu_net.multisetadd(mu_outM);
mu_res[mu_i].mu_state = mu_R_WAIT;
mu_res[mu_i].mu_initiator = mu_inM.mu_nonce2;
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
    return 20;
  }
  char * Name(unsigned r)
  {
    static mu_1__type_2_id mu_j;
    mu_j.value((r % 2) + 0);
    r = r / 2;
    static mu_1_InitiatorId mu_i;
    mu_i.value((r % 1) + 1);
    r = r / 1;
    return tsprintf("initiator reacts to nonce received (steps 6/7), j:%s, i:%s", mu_j.Name(), mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1__type_2_id mu_j;
    mu_j.value((r % 2) + 0);
    r = r / 2;
    static mu_1_InitiatorId mu_i;
    mu_i.value((r % 1) + 1);
    r = r / 1;
  if (!mu_net.in(mu_j)) { return FALSE; }
bool mu__boolexpr33;
bool mu__boolexpr34;
  if (!((mu_ini[mu_i].mu_state) == (mu_I_WAIT))) mu__boolexpr34 = FALSE ;
  else {
  mu__boolexpr34 = ((mu_net[mu_j].mu_dest) == (mu_i)) ; 
}
  if (!(mu__boolexpr34)) mu__boolexpr33 = FALSE ;
  else {
  mu__boolexpr33 = ((mu_net[mu_j].mu_source>=3 && mu_net[mu_j].mu_source<=5)) ; 
}
  return mu__boolexpr33;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 5785;
    static mu_1__type_2_id mu_j;
    mu_j.value((r % 2) + 0);
    r = r / 2;
    static mu_1_InitiatorId mu_i;
    mu_i.value((r % 1) + 1);
    r = r / 1;
    while (what_rule < 5787 && mu_j.value()<2 )
      {
        if ( ( TRUE && mu_net.in(mu_j) ) ) {
bool mu__boolexpr35;
bool mu__boolexpr36;
  if (!((mu_ini[mu_i].mu_state) == (mu_I_WAIT))) mu__boolexpr36 = FALSE ;
  else {
  mu__boolexpr36 = ((mu_net[mu_j].mu_dest) == (mu_i)) ; 
}
  if (!(mu__boolexpr36)) mu__boolexpr35 = FALSE ;
  else {
  mu__boolexpr35 = ((mu_net[mu_j].mu_source>=3 && mu_net[mu_j].mu_source<=5)) ; 
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
    r = what_rule - 5785;
    mu_j.value((r % 2) + 0);
    r = r / 2;
    mu_i.value((r % 1) + 1);
    r = r / 1;
    }
  }

  void Code(unsigned r)
  {
    static mu_1__type_2_id mu_j;
    mu_j.value((r % 2) + 0);
    r = r / 2;
    static mu_1_InitiatorId mu_i;
    mu_i.value((r % 1) + 1);
    r = r / 1;
/*** Variable declaration ***/
mu_1_Message mu_outM("outM",0);

/*** Variable declaration ***/
mu_1_Message mu_inM("inM",20);

mu_inM = mu_net[mu_j];
mu_net.multisetremove(mu_j);
if ( (mu_inM.mu_key) == (mu_i) )
{
if ( (mu_inM.mu_mType) == (mu_M_NonceNonceAddress) )
{
bool mu__boolexpr37;
  if (!((mu_inM.mu_nonce1) == (mu_i))) mu__boolexpr37 = FALSE ;
  else {
bool mu__boolexpr38;
  if (!(mu_FIXED)) mu__boolexpr38 = TRUE ;
  else {
  mu__boolexpr38 = ((mu_inM.mu_address) == (mu_ini[mu_i].mu_responder)) ; 
}
  mu__boolexpr37 = (mu__boolexpr38) ; 
}
if ( mu__boolexpr37 )
{
mu_outM.undefine();
mu_outM.mu_source = mu_i;
mu_outM.mu_dest = mu_ini[mu_i].mu_responder;
mu_outM.mu_key = mu_ini[mu_i].mu_responder;
mu_outM.mu_mType = mu_M_Nonce;
mu_outM.mu_nonce1 = mu_inM.mu_nonce2;
mu_net.multisetadd(mu_outM);
mu_ini[mu_i].mu_state = mu_I_COMMIT;
}
}
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
    return 20;
  }
  char * Name(unsigned r)
  {
    static mu_1_AgentId mu_j;
    mu_j.unionassign(r % 5);
    r = r / 5;
    static mu_1_InitiatorId mu_i;
    mu_i.value((r % 1) + 1);
    r = r / 1;
    return tsprintf("initiator starts protocol (step 3), j:%s, i:%s", mu_j.Name(), mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_AgentId mu_j;
    mu_j.unionassign(r % 5);
    r = r / 5;
    static mu_1_InitiatorId mu_i;
    mu_i.value((r % 1) + 1);
    r = r / 1;
bool mu__boolexpr39;
bool mu__boolexpr40;
  if (!((mu_ini[mu_i].mu_state) == (mu_I_SLEEP))) mu__boolexpr40 = FALSE ;
  else {
  mu__boolexpr40 = (!((mu_j>=1 && mu_j<=1))) ; 
}
  if (!(mu__boolexpr40)) mu__boolexpr39 = FALSE ;
  else {
/*** begin multisetcount 0 declaration ***/
  int mu__intexpr41 = 0;
  {
  mu_1__type_2_id mu_l;
  for (mu_l = 0; ; mu_l=mu_l+1)
    {
      if (mu_net.valid[(int)mu_l].value())
        {
          if ( mu_true ) mu__intexpr41++;
        }
      if (mu_l == 2-1) break;
    }
  }
/*** end multisetcount 0 declaration ***/
  mu__boolexpr39 = ((mu__intexpr41) < (mu_NetworkSize)) ; 
}
  return mu__boolexpr39;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 5787;
    static mu_1_AgentId mu_j;
    mu_j.unionassign(r % 5);
    r = r / 5;
    static mu_1_InitiatorId mu_i;
    mu_i.value((r % 1) + 1);
    r = r / 1;
    while (what_rule < 5792 )
      {
        if ( ( TRUE  ) ) {
bool mu__boolexpr42;
bool mu__boolexpr43;
  if (!((mu_ini[mu_i].mu_state) == (mu_I_SLEEP))) mu__boolexpr43 = FALSE ;
  else {
  mu__boolexpr43 = (!((mu_j>=1 && mu_j<=1))) ; 
}
  if (!(mu__boolexpr43)) mu__boolexpr42 = FALSE ;
  else {
/*** begin multisetcount 0 declaration ***/
  int mu__intexpr44 = 0;
  {
  mu_1__type_2_id mu_l;
  for (mu_l = 0; ; mu_l=mu_l+1)
    {
      if (mu_net.valid[(int)mu_l].value())
        {
          if ( mu_true ) mu__intexpr44++;
        }
      if (mu_l == 2-1) break;
    }
  }
/*** end multisetcount 0 declaration ***/
  mu__boolexpr42 = ((mu__intexpr44) < (mu_NetworkSize)) ; 
}
              if (mu__boolexpr42) {
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
    r = what_rule - 5787;
    mu_j.unionassign(r % 5);
    r = r / 5;
    mu_i.value((r % 1) + 1);
    r = r / 1;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_AgentId mu_j;
    mu_j.unionassign(r % 5);
    r = r / 5;
    static mu_1_InitiatorId mu_i;
    mu_i.value((r % 1) + 1);
    r = r / 1;
/*** Variable declaration ***/
mu_1_Message mu_outM("outM",0);

mu_outM.undefine();
mu_outM.mu_source = mu_i;
mu_outM.mu_dest = mu_j;
mu_outM.mu_key = mu_j;
mu_outM.mu_mType = mu_M_NonceAddress;
mu_outM.mu_nonce1 = mu_i;
mu_outM.mu_nonce2 = mu_i;
mu_net.multisetadd(mu_outM);
mu_ini[mu_i].mu_state = mu_I_WAIT;
mu_ini[mu_i].mu_responder = mu_j;
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
public:
void SetNextEnabledRule(unsigned & what_rule)
{
  category = CONDITION;
  if (what_rule<5625)
    { R0.NextRule(what_rule);
      if (what_rule<5625) return; }
  if (what_rule>=5625 && what_rule<5775)
    { R1.NextRule(what_rule);
      if (what_rule<5775) return; }
  if (what_rule>=5775 && what_rule<5781)
    { R2.NextRule(what_rule);
      if (what_rule<5781) return; }
  if (what_rule>=5781 && what_rule<5783)
    { R3.NextRule(what_rule);
      if (what_rule<5783) return; }
  if (what_rule>=5783 && what_rule<5785)
    { R4.NextRule(what_rule);
      if (what_rule<5785) return; }
  if (what_rule>=5785 && what_rule<5787)
    { R5.NextRule(what_rule);
      if (what_rule<5787) return; }
  if (what_rule>=5787 && what_rule<5792)
    { R6.NextRule(what_rule);
      if (what_rule<5792) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=5624) return R0.Condition(r-0);
  if (r>=5625 && r<=5774) return R1.Condition(r-5625);
  if (r>=5775 && r<=5780) return R2.Condition(r-5775);
  if (r>=5781 && r<=5782) return R3.Condition(r-5781);
  if (r>=5783 && r<=5784) return R4.Condition(r-5783);
  if (r>=5785 && r<=5786) return R5.Condition(r-5785);
  if (r>=5787 && r<=5791) return R6.Condition(r-5787);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
}
void Code(unsigned r)
{
  if (r<=5624) { R0.Code(r-0); return; } 
  if (r>=5625 && r<=5774) { R1.Code(r-5625); return; } 
  if (r>=5775 && r<=5780) { R2.Code(r-5775); return; } 
  if (r>=5781 && r<=5782) { R3.Code(r-5781); return; } 
  if (r>=5783 && r<=5784) { R4.Code(r-5783); return; } 
  if (r>=5785 && r<=5786) { R5.Code(r-5785); return; } 
  if (r>=5787 && r<=5791) { R6.Code(r-5787); return; } 
}
int Priority(unsigned short r)
{
  if (r<=5624) { return R0.Priority(); } 
  if (r>=5625 && r<=5774) { return R1.Priority(); } 
  if (r>=5775 && r<=5780) { return R2.Priority(); } 
  if (r>=5781 && r<=5782) { return R3.Priority(); } 
  if (r>=5783 && r<=5784) { return R4.Priority(); } 
  if (r>=5785 && r<=5786) { return R5.Priority(); } 
  if (r>=5787 && r<=5791) { return R6.Priority(); } 
}
char * Name(unsigned r)
{
  if (r<=5624) return R0.Name(r-0);
  if (r>=5625 && r<=5774) return R1.Name(r-5625);
  if (r>=5775 && r<=5780) return R2.Name(r-5775);
  if (r>=5781 && r<=5782) return R3.Name(r-5781);
  if (r>=5783 && r<=5784) return R4.Name(r-5783);
  if (r>=5785 && r<=5786) return R5.Name(r-5785);
  if (r>=5787 && r<=5791) return R6.Name(r-5787);
  return NULL;
}
};
const unsigned numrules = 5792;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 5792


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
mu_ini.undefine();
{
for(int mu_i = 1; mu_i <= 1; mu_i++) {
mu_ini[mu_i].mu_state = mu_I_SLEEP;
mu_ini[mu_i].mu_responder = mu_i;
};
};
mu_res.undefine();
{
for(int mu_i = 2; mu_i <= 2; mu_i++) {
mu_res[mu_i].mu_state = mu_R_SLEEP;
mu_res[mu_i].mu_initiator = mu_i;
};
};
mu_int.undefine();
{
for(int mu_i = 3; mu_i <= 5; mu_i++) {
{
for(int mu_j = 1; mu_j <= 5; mu_j++)
  if (( ( mu_j >= 3 ) && ( mu_j <= 5 ) )|| ( ( mu_j >= 2 ) && ( mu_j <= 2 ) )|| ( ( mu_j >= 1 ) && ( mu_j <= 1 ) )) {
mu_int[mu_i].mu_nonces[mu_j] = mu_false;
};
};
mu_int[mu_i].mu_nonces[mu_i] = mu_true;
};
};
mu_net.undefine();
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
int mu__invariant_45() // Invariant "initiator correctly authenticated"
{
bool mu__quant46; 
mu__quant46 = TRUE;
{
for(int mu_i = 2; mu_i <= 2; mu_i++) {
bool mu__boolexpr47;
bool mu__boolexpr48;
  if (!((mu_res[mu_i].mu_state) == (mu_R_COMMIT))) mu__boolexpr48 = FALSE ;
  else {
  mu__boolexpr48 = ((mu_res[mu_i].mu_initiator>=1 && mu_res[mu_i].mu_initiator<=1)) ; 
}
  if (!(mu__boolexpr48)) mu__boolexpr47 = TRUE ;
  else {
bool mu__boolexpr49;
  if (!((mu_ini[mu_res[mu_i].mu_initiator].mu_responder) == (mu_i))) mu__boolexpr49 = FALSE ;
  else {
  mu__boolexpr49 = ((mu_ini[mu_res[mu_i].mu_initiator].mu_state) == (mu_I_COMMIT)) ; 
}
  mu__boolexpr47 = (mu__boolexpr49) ; 
}
if ( !(mu__boolexpr47) )
  { mu__quant46 = FALSE; break; }
};
};
return mu__quant46;
};

bool mu__condition_50() // Condition for Rule "initiator correctly authenticated"
{
  return mu__invariant_45( );
}

/**** end rule declaration ****/

int mu__invariant_51() // Invariant "responder correctly authenticated"
{
bool mu__quant52; 
mu__quant52 = TRUE;
{
for(int mu_i = 1; mu_i <= 1; mu_i++) {
bool mu__boolexpr53;
bool mu__boolexpr54;
  if (!((mu_ini[mu_i].mu_state) == (mu_I_COMMIT))) mu__boolexpr54 = FALSE ;
  else {
  mu__boolexpr54 = ((mu_ini[mu_i].mu_responder>=2 && mu_ini[mu_i].mu_responder<=2)) ; 
}
  if (!(mu__boolexpr54)) mu__boolexpr53 = TRUE ;
  else {
bool mu__boolexpr55;
  if (!((mu_res[mu_ini[mu_i].mu_responder].mu_initiator) == (mu_i))) mu__boolexpr55 = FALSE ;
  else {
bool mu__boolexpr56;
  if ((mu_res[mu_ini[mu_i].mu_responder].mu_state) == (mu_R_WAIT)) mu__boolexpr56 = TRUE ;
  else {
  mu__boolexpr56 = ((mu_res[mu_ini[mu_i].mu_responder].mu_state) == (mu_R_COMMIT)) ; 
}
  mu__boolexpr55 = (mu__boolexpr56) ; 
}
  mu__boolexpr53 = (mu__boolexpr55) ; 
}
if ( !(mu__boolexpr53) )
  { mu__quant52 = FALSE; break; }
};
};
return mu__quant52;
};

bool mu__condition_57() // Condition for Rule "responder correctly authenticated"
{
  return mu__invariant_51( );
}

/**** end rule declaration ****/

const rulerec invariants[] = {
{"responder correctly authenticated", &mu__condition_57, NULL, FALSE},
{"initiator correctly authenticated", &mu__condition_50, NULL, FALSE},
};
const unsigned short numinvariants = 2;

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
ini:ScalarsetVariable
res:ScalarsetVariable
net:Complex
int:Complex
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
  int class_mu_1_IntruderId[3];
  int undefined_class_mu_1_IntruderId;// has the highest class number

  void Print_class_mu_1_IntruderId();
  bool OnlyOneRemain_mu_1_IntruderId;
  bool MTO_class_mu_1_IntruderId()
  {
    int i,j;
    if (OnlyOneRemain_mu_1_IntruderId)
      return FALSE;
    for (i=0; i<3; i++)
      for (j=0; j<3; j++)
        if (i!=j && class_mu_1_IntruderId[i]== class_mu_1_IntruderId[j])
	    return TRUE;
    OnlyOneRemain_mu_1_IntruderId = TRUE;
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
  int * in_mu_1_IntruderId;
  typedef int arr_mu_1_IntruderId[3];
  arr_mu_1_IntruderId * perm_mu_1_IntruderId;
  arr_mu_1_IntruderId * revperm_mu_1_IntruderId;

  int size_mu_1_IntruderId[3];
  bool reversed_sorted_mu_1_IntruderId(int start, int end);
  void reverse_reversed_mu_1_IntruderId(int start, int end);

  // procedure for explicit representation
  bool ok0(mu_1_IntruderId* perm, int size, mu_1_IntruderId k);
  void GenPerm0(mu_1_IntruderId* perm, int size, unsigned long& index);

  // General procedure
  PermSet();
  bool In(int i) const { return in[i]; };
  void Add(int i) { for (int j=0; j<i; j++) in[j] = FALSE;};
  void Remove(int i) { in[i] = FALSE; };
};
void PermSet::Print_class_mu_1_IntruderId()
{
  cout << "class_mu_1_IntruderId:\t";
  for (int i=0; i<3; i++)
    cout << class_mu_1_IntruderId[i];
  cout << " " << undefined_class_mu_1_IntruderId << "\n";
}
bool PermSet::MoreThanOneRemain()
{
  int i,j;
  if (AlreadyOnlyOneRemain)
    return FALSE;
  else {
    for (i=0; i<3; i++)
      for (j=0; j<3; j++)
        if (i!=j && class_mu_1_IntruderId[i]== class_mu_1_IntruderId[j])
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
    mu_1_IntruderId Perm0[3];

  /********************
   declaration of class variables
  ********************/
  in = new bool[6];
 in_mu_1_IntruderId = new int[6];
 perm_mu_1_IntruderId = new arr_mu_1_IntruderId[6];
 revperm_mu_1_IntruderId = new arr_mu_1_IntruderId[6];

    // Set perm and revperm
    count = 0;
    for (i=3; i<=5; i++)
      {
        Perm0[0].value(i);
        GenPerm0(Perm0, 1, count);
      }
    if (count!=6)
      Error.Error( "unable to initialize PermSet");
    for (i=0; i<6; i++)
      for (j=3; j<=5; j++)
        for (k=3; k<=5; k++)
          if (revperm_mu_1_IntruderId[i][k-3]==j)   // k - base 
            perm_mu_1_IntruderId[i][j-3]=k; // j - base 

    // setting up combination of permutations
    // for different scalarset
    int carry;
    int i_mu_1_IntruderId = 0;
    size = 6;
    count = 6;
    for (i=0; i<6; i++)
      {
        carry = 1;
        in[i]= TRUE;
      in_mu_1_IntruderId[i] = i_mu_1_IntruderId;
      i_mu_1_IntruderId += carry;
      if (i_mu_1_IntruderId >= 6) { i_mu_1_IntruderId = 0; carry = 1; } 
      else { carry = 0; } 
    }
  }
  else
  {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];
 in_mu_1_IntruderId = new int[1];
 perm_mu_1_IntruderId = new arr_mu_1_IntruderId[1];
 revperm_mu_1_IntruderId = new arr_mu_1_IntruderId[1];
  in[0] = TRUE;
    in_mu_1_IntruderId[0] = 0;
  }
}
void PermSet::ResetToSimple()
{
  int i;
  for (i=0; i<3; i++)
    class_mu_1_IntruderId[i]=0;
  undefined_class_mu_1_IntruderId=0;
  OnlyOneRemain_mu_1_IntruderId = FALSE;

  AlreadyOnlyOneRemain = FALSE;
  Presentation = Simple;
}
void PermSet::ResetToExplicit()
{
  for (int i=0; i<6; i++) in[i] = TRUE;
  Presentation = Explicit;
}
void PermSet::SimpleToExplicit()
{
  int i,j,k;
  int start, class_size;
  int start_mu_1_IntruderId[3];
  int size_mu_1_IntruderId[3];
  bool should_be_in_mu_1_IntruderId[6];

  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_IntruderId; j++) // class number
    {
      class_size = 0;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_IntruderId[k]==j)
	  class_size++;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_IntruderId[k]==j)
	  {
	    size_mu_1_IntruderId[k] = class_size;
	    start_mu_1_IntruderId[k] = start;
	  }
      start+=class_size;
    }

  // To be In or not to be
  for (i=0; i<6; i++) // set up
    should_be_in_mu_1_IntruderId[i] = TRUE;
  for (i=0; i<6; i++) // to be in or not to be
    for (k=0; k<3; k++) // step through class_mu_1_pid[k]
      if (! (perm_mu_1_IntruderId[i][k]-3 >=start_mu_1_IntruderId[k] 
	     && perm_mu_1_IntruderId[i][k]-3 < start_mu_1_IntruderId[k] + size_mu_1_IntruderId[k]) )
  	    {
	      should_be_in_mu_1_IntruderId[i] = FALSE;
	      break;
	    }

  // setup explicit representation 
  // Set perm and revperm
  for (i=0; i<6; i++)
    {
      in[i] = TRUE;
      if (in[i] && !should_be_in_mu_1_IntruderId[in_mu_1_IntruderId[i]]) in[i] = FALSE;
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
  for (j=0; j<=undefined_class_mu_1_IntruderId; j++) // class number
    {
      class_size = 0;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_IntruderId[k]==j)
	  class_size++;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_IntruderId[k]==j)
	  {
	    size_mu_1_IntruderId[k] = class_size;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_IntruderId; j++) // class number
    {
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	    if (class_mu_1_IntruderId[k]==j)
	      revperm_mu_1_IntruderId[0][start++] = k+3;
    }
  for (j=0; j<3; j++)
    for (k=0; k<3; k++)
      if (revperm_mu_1_IntruderId[0][k]==j+3)
        perm_mu_1_IntruderId[0][j]=k+3;
  Presentation = Explicit;
}
bool PermSet::ok0(mu_1_IntruderId* Perm, int size, mu_1_IntruderId k)
{
  for (int i=0; i<size; i++)
    if(Perm[i].value()==k)
      return FALSE;
  return TRUE;
}
void PermSet::GenPerm0(mu_1_IntruderId* Perm,int size, unsigned long& count)
{
  int i;
  if (size!=3)
    {
      for (i=3; i<=5; i++)
        if(ok0(Perm,size,i))
          {
            Perm[size].value(i);
            GenPerm0(Perm, size+1, count);
          }
    }
  else
    {
      for (i=3; i<=5; i++)
        revperm_mu_1_IntruderId[count][i-3]=Perm[i-3].value();// i - base
      count++;
    }
}
bool PermSet::reversed_sorted_mu_1_IntruderId(int start, int end)
{
  int i,j;

  for (i=start; i<end; i++)
    if (revperm_mu_1_IntruderId[0][i]<revperm_mu_1_IntruderId[0][i+1])
      return FALSE;
  return TRUE;
}
void PermSet::reverse_reversed_mu_1_IntruderId(int start, int end)
{
  int i,j;
  int temp;

  for (i=start, j=end; i<j; i++,j--) 
    {
      temp = revperm_mu_1_IntruderId[0][j];
      revperm_mu_1_IntruderId[0][j] = revperm_mu_1_IntruderId[0][i];
      revperm_mu_1_IntruderId[0][i] = temp;
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
  for (start = 0; start < 3; )
    {
      end = start-1+size_mu_1_IntruderId[revperm_mu_1_IntruderId[0][start]-3];
      if (reversed_sorted_mu_1_IntruderId(start,end))
	       {
	  reverse_reversed_mu_1_IntruderId(start,end);
	  start = end+1;
	}
      else
	{
	  nexted = TRUE;
	  for (j = start; j<end; j++)
	    {
	      if (reversed_sorted_mu_1_IntruderId(j+1,end))
		{
		  for (k = end; k>j; k--)
		    {
		      if (revperm_mu_1_IntruderId[0][j]<revperm_mu_1_IntruderId[0][k])
			{
			  // swap j, k
			  temp = revperm_mu_1_IntruderId[0][j];
			  revperm_mu_1_IntruderId[0][j] = revperm_mu_1_IntruderId[0][k];
			  revperm_mu_1_IntruderId[0][k] = temp;
			  break;
			}
		    }
		  reverse_reversed_mu_1_IntruderId(j+1,end);
		  break;
		}
	    }
	  break;
	}
    }
if (!nexted) return FALSE;
  for (j=0; j<3; j++)
    for (k=0; k<3; k++)
      if (revperm_mu_1_IntruderId[0][k]==j+3)   // k - base 
	perm_mu_1_IntruderId[0][j]=k+3; // j - base 
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
        mu_ini.MultisetSort();
        mu_res.MultisetSort();
        mu_net.MultisetSort();
        mu_int.MultisetSort();
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
void mu_1_InitiatorId::Permute(PermSet& Perm, int i) {}
void mu_1_InitiatorId::SimpleCanonicalize(PermSet& Perm) {}
void mu_1_InitiatorId::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_InitiatorId::SimpleLimit(PermSet& Perm) {}
void mu_1_InitiatorId::ArrayLimit(PermSet& Perm) {}
void mu_1_InitiatorId::Limit(PermSet& Perm) {}
void mu_1_InitiatorId::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
void mu_1_ResponderId::Permute(PermSet& Perm, int i) {}
void mu_1_ResponderId::SimpleCanonicalize(PermSet& Perm) {}
void mu_1_ResponderId::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_ResponderId::SimpleLimit(PermSet& Perm) {}
void mu_1_ResponderId::ArrayLimit(PermSet& Perm) {}
void mu_1_ResponderId::Limit(PermSet& Perm) {}
void mu_1_ResponderId::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
void mu_1_IntruderId::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined())
    value(Perm.perm_mu_1_IntruderId[Perm.in_mu_1_IntruderId[i]][value()-3]); // value - base
};
void mu_1_IntruderId::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_IntruderId[value()-3]==Perm.undefined_class_mu_1_IntruderId) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<3; i++)
          if (Perm.class_mu_1_IntruderId[i] == Perm.undefined_class_mu_1_IntruderId && i!=value()-3)
            Perm.class_mu_1_IntruderId[i]++;
        value(3 + Perm.undefined_class_mu_1_IntruderId++);
      }
    else 
      {
        value(Perm.class_mu_1_IntruderId[value()-3]+3);
      }
}
void mu_1_IntruderId::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_IntruderId::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_IntruderId[value()-3]==Perm.undefined_class_mu_1_IntruderId) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<3; i++)
          if (Perm.class_mu_1_IntruderId[i] == Perm.undefined_class_mu_1_IntruderId && i!=value()-3)
            Perm.class_mu_1_IntruderId[i]++;
        Perm.undefined_class_mu_1_IntruderId++;
      }
}
void mu_1_IntruderId::ArrayLimit(PermSet& Perm) {}
void mu_1_IntruderId::Limit(PermSet& Perm) {}
void mu_1_IntruderId::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
void mu_1_AgentId::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 3 ) && ( value() <= 5 ) )
      value(Perm.perm_mu_1_IntruderId[Perm.in_mu_1_IntruderId[i]][value()-3]+(0)); // value - base
  }
}
void mu_1_AgentId::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 3 ) && ( value() <= 5 ) )
      {
        if (Perm.class_mu_1_IntruderId[value()-3]==Perm.undefined_class_mu_1_IntruderId) // value - base
          {
            // it has not been mapped to any particular value
            for (i=0; i<3; i++)
              if (Perm.class_mu_1_IntruderId[i] == Perm.undefined_class_mu_1_IntruderId && i!=value()-3)
                Perm.class_mu_1_IntruderId[i]++;
            value(3 + Perm.undefined_class_mu_1_IntruderId++);
          }
        else 
          {
            value(Perm.class_mu_1_IntruderId[value()-3]+3);
          }
      }
  }
}
void mu_1_AgentId::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_AgentId::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 3 ) && ( value() <= 5 ) )
      if (Perm.class_mu_1_IntruderId[value()-3]==Perm.undefined_class_mu_1_IntruderId) // value - base
        {
          // it has not been mapped to any particular value
          for (i=0; i<3; i++)
            if (Perm.class_mu_1_IntruderId[i] == Perm.undefined_class_mu_1_IntruderId && i!=value()-3)
              Perm.class_mu_1_IntruderId[i]++;
          Perm.undefined_class_mu_1_IntruderId++;
        }
  }
}
void mu_1_AgentId::ArrayLimit(PermSet& Perm) {}
void mu_1_AgentId::Limit(PermSet& Perm) {}
void mu_1_AgentId::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for union type.\n"); };
void mu_1_MessageType::Permute(PermSet& Perm, int i) {};
void mu_1_MessageType::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_MessageType::Canonicalize(PermSet& Perm) {};
void mu_1_MessageType::SimpleLimit(PermSet& Perm) {};
void mu_1_MessageType::ArrayLimit(PermSet& Perm) {};
void mu_1_MessageType::Limit(PermSet& Perm) {};
void mu_1_MessageType::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_Message::Permute(PermSet& Perm, int i)
{
  mu_source.Permute(Perm,i);
  mu_dest.Permute(Perm,i);
  mu_key.Permute(Perm,i);
  mu_nonce1.Permute(Perm,i);
  mu_nonce2.Permute(Perm,i);
  mu_address.Permute(Perm,i);
};
void mu_1_Message::SimpleCanonicalize(PermSet& Perm)
{
  mu_source.SimpleCanonicalize(Perm);
  mu_dest.SimpleCanonicalize(Perm);
  mu_key.SimpleCanonicalize(Perm);
  mu_nonce1.SimpleCanonicalize(Perm);
  mu_nonce2.SimpleCanonicalize(Perm);
  mu_address.SimpleCanonicalize(Perm);
};
void mu_1_Message::Canonicalize(PermSet& Perm)
{
};
void mu_1_Message::SimpleLimit(PermSet& Perm)
{
  mu_source.SimpleLimit(Perm);
  mu_dest.SimpleLimit(Perm);
  mu_key.SimpleLimit(Perm);
  mu_nonce1.SimpleLimit(Perm);
  mu_nonce2.SimpleLimit(Perm);
  mu_address.SimpleLimit(Perm);
};
void mu_1_Message::ArrayLimit(PermSet& Perm){}
void mu_1_Message::Limit(PermSet& Perm)
{
};
void mu_1_Message::MultisetLimit(PermSet& Perm)
{
};
void mu_1_InitiatorStates::Permute(PermSet& Perm, int i) {};
void mu_1_InitiatorStates::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_InitiatorStates::Canonicalize(PermSet& Perm) {};
void mu_1_InitiatorStates::SimpleLimit(PermSet& Perm) {};
void mu_1_InitiatorStates::ArrayLimit(PermSet& Perm) {};
void mu_1_InitiatorStates::Limit(PermSet& Perm) {};
void mu_1_InitiatorStates::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_Initiator::Permute(PermSet& Perm, int i)
{
  mu_responder.Permute(Perm,i);
};
void mu_1_Initiator::SimpleCanonicalize(PermSet& Perm)
{
  mu_responder.SimpleCanonicalize(Perm);
};
void mu_1_Initiator::Canonicalize(PermSet& Perm)
{
};
void mu_1_Initiator::SimpleLimit(PermSet& Perm)
{
  mu_responder.SimpleLimit(Perm);
};
void mu_1_Initiator::ArrayLimit(PermSet& Perm){}
void mu_1_Initiator::Limit(PermSet& Perm)
{
};
void mu_1_Initiator::MultisetLimit(PermSet& Perm)
{
};
void mu_1_ResponderStates::Permute(PermSet& Perm, int i) {};
void mu_1_ResponderStates::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_ResponderStates::Canonicalize(PermSet& Perm) {};
void mu_1_ResponderStates::SimpleLimit(PermSet& Perm) {};
void mu_1_ResponderStates::ArrayLimit(PermSet& Perm) {};
void mu_1_ResponderStates::Limit(PermSet& Perm) {};
void mu_1_ResponderStates::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_Responder::Permute(PermSet& Perm, int i)
{
  mu_initiator.Permute(Perm,i);
};
void mu_1_Responder::SimpleCanonicalize(PermSet& Perm)
{
  mu_initiator.SimpleCanonicalize(Perm);
};
void mu_1_Responder::Canonicalize(PermSet& Perm)
{
};
void mu_1_Responder::SimpleLimit(PermSet& Perm)
{
  mu_initiator.SimpleLimit(Perm);
};
void mu_1_Responder::ArrayLimit(PermSet& Perm){}
void mu_1_Responder::Limit(PermSet& Perm)
{
};
void mu_1_Responder::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_0::Permute(PermSet& Perm, int i)
{
  static mu_1__type_0 temp("Permute_mu_1__type_0",-1);
  int j;
  for (j=0; j<5; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=3; j<=5; j++)
      (*this)[j].value(temp[Perm.revperm_mu_1_IntruderId[Perm.in_mu_1_IntruderId[i]][j-3]].value());
};
void mu_1__type_0::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_0::Canonicalize(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  static mu_0_boolean value[5];
  int compare;
  // limit
  bool exists;
  bool split;
  // range mapping
  int start;
  int class_size;
  // canonicalization
  static mu_1__type_0 temp;
  int count_mu_1_IntruderId;
  bool pos_mu_1_IntruderId[3][3];
  bool goodset_mu_1_IntruderId[3];
  int size_mu_1_IntruderId[3];
  int start_mu_1_IntruderId[3];
  // sorting mu_1_IntruderId
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_IntruderId())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_IntruderId[i][j]=FALSE;
      count_mu_1_IntruderId = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_IntruderId; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+3]);
              if (compare==0)
                {
                  pos_mu_1_IntruderId[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_IntruderId; k>j; k--)
                    {
                      value[k].value(value[k-1].value());
                      for (z=0; z<3; z++)
                        pos_mu_1_IntruderId[k][z] = pos_mu_1_IntruderId[k-1][z];
                    }
                  value[j].value((*this)[i+3].value());
                  for (z=0; z<3; z++)
                    pos_mu_1_IntruderId[j][z] = FALSE;
                  pos_mu_1_IntruderId[j][i] = TRUE;
                  count_mu_1_IntruderId++;
                  break;
                }
            }
          if (j==count_mu_1_IntruderId)
            {
                value[j].value((*this)[i+3].value());
              for (z=0; z<3; z++)
                pos_mu_1_IntruderId[j][z] = FALSE;
              pos_mu_1_IntruderId[j][i] = TRUE;
              count_mu_1_IntruderId++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_IntruderId() && count_mu_1_IntruderId>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_IntruderId; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_IntruderId[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_IntruderId[i][k] && Perm.class_mu_1_IntruderId[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_IntruderId[k] = TRUE;
                    pos_mu_1_IntruderId[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_IntruderId[k] == j && !goodset_mu_1_IntruderId[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_IntruderId[k]>j
                            || ( Perm.class_mu_1_IntruderId[k] == j && !goodset_mu_1_IntruderId[k] ) )
                          Perm.class_mu_1_IntruderId[k]++;
                      Perm.undefined_class_mu_1_IntruderId++;
                    }
                }
            }
        }
    }
  if (Perm.MTO_class_mu_1_IntruderId())
    {

      // setup range for maping
      start = 0;
      for (j=0; j<=Perm.undefined_class_mu_1_IntruderId; j++) // class number
        {
          class_size = 0;
          for (k=0; k<3; k++) // step through class[k]
            if (Perm.class_mu_1_IntruderId[k]==j)
              class_size++;
          for (k=0; k<3; k++) // step through class[k]
            if (Perm.class_mu_1_IntruderId[k]==j)
              {
                size_mu_1_IntruderId[k] = class_size;
                start_mu_1_IntruderId[k] = start;
              }
          start+=class_size;
        }

      // canonicalize
      temp = *this;
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
         if (i >=start_mu_1_IntruderId[j] 
             && i < start_mu_1_IntruderId[j] + size_mu_1_IntruderId[j])
           {
             array[i+2].value(temp[j+3].value());
             break;
           }
    }
  else
    {

      // fast canonicalize
      temp = *this;
      for (j=0; j<3; j++)
        array[Perm.class_mu_1_IntruderId[j]+2].value(temp[j+3].value());
    }
}
void mu_1__type_0::SimpleLimit(PermSet& Perm){}
void mu_1__type_0::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int compare;
  static mu_0_boolean value[5];
  // limit
  bool exists;
  bool split;
  int count_mu_1_IntruderId;
  bool pos_mu_1_IntruderId[3][3];
  bool goodset_mu_1_IntruderId[3];
  // sorting mu_1_IntruderId
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_IntruderId())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_IntruderId[i][j]=FALSE;
      count_mu_1_IntruderId = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_IntruderId; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+3]);
              if (compare==0)
                {
                  pos_mu_1_IntruderId[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_IntruderId; k>j; k--)
                    {
                      value[k].value(value[k-1].value());
                      for (z=0; z<3; z++)
                        pos_mu_1_IntruderId[k][z] = pos_mu_1_IntruderId[k-1][z];
                    }
                  value[j].value((*this)[i+3].value());
                  for (z=0; z<3; z++)
                    pos_mu_1_IntruderId[j][z] = FALSE;
                  pos_mu_1_IntruderId[j][i] = TRUE;
                  count_mu_1_IntruderId++;
                  break;
                }
            }
          if (j==count_mu_1_IntruderId)
            {
                value[j].value((*this)[i+3].value());
              for (z=0; z<3; z++)
                pos_mu_1_IntruderId[j][z] = FALSE;
              pos_mu_1_IntruderId[j][i] = TRUE;
              count_mu_1_IntruderId++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_IntruderId() && count_mu_1_IntruderId>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_IntruderId; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_IntruderId[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_IntruderId[i][k] && Perm.class_mu_1_IntruderId[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_IntruderId[k] = TRUE;
                    pos_mu_1_IntruderId[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_IntruderId[k] == j && !goodset_mu_1_IntruderId[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_IntruderId[k]>j
                            || ( Perm.class_mu_1_IntruderId[k] == j && !goodset_mu_1_IntruderId[k] ) )
                          Perm.class_mu_1_IntruderId[k]++;
                      Perm.undefined_class_mu_1_IntruderId++;
                    }
                }
            }
        }
    }
}
void mu_1__type_0::Limit(PermSet& Perm){}
void mu_1__type_0::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_1::Permute(PermSet& Perm, int i)
{
  static mu_1__type_1 temp("Permute_mu_1__type_1",-1);
  int j;
  for (j=0; j<10; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_1::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: calling SimpleCanonicalize for a multiset.\n"); };
void mu_1__type_1::Canonicalize(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_1::SimpleLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_1::ArrayLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_1::Limit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_1::MultisetLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_Message value[10];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_IntruderId, oldcount_mu_1_IntruderId;
  bool pos_mu_1_IntruderId[3][3];
  bool goodset_mu_1_IntruderId[3];
  int count_multisetindex, oldcount_multisetindex;
  bool pos_multisetindex[10][10];
  bool goodset_multisetindex[10];
  mu_1_Message temp;

  // compact
  for (i = 0, j = 0; i < 10; i++)
    if (valid[i].value())
      {
        if (j!=i)
          array[j++] = array[i];
        else
          j++;
      }
  if (j != current_size) current_size = j;
  for (i = j; i < 10; i++)
    array[i].undefine();
  for (i = 0; i < j; i++)
    valid[i].value(TRUE);
  for (i = j; i < 10; i++)
    valid[i].value(FALSE);

  // bubble sort
  for (i = 0; i < current_size; i++)
    for (j = i+1; j < current_size; j++)
      if (CompareWeight(array[i],array[j])>0)
        {
          temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }
  // initializing pos array
    for (i=0; i<current_size; i++)
      for (j=0; j<current_size; j++)
        pos_multisetindex[i][j]=FALSE;
    count_multisetindex = 1;
    pos_multisetindex[0][0] = TRUE;
    for (i = 1, j = 0 ; i < current_size; i++)
      if (CompareWeight(array[i-1],array[i])==0)
        pos_multisetindex[j][i] = TRUE;
      else
        { count_multisetindex++; pos_multisetindex[++j][i] = TRUE; }
  if (current_size == 1)
    {
      array[0].SimpleLimit(Perm);
    }
  else
    {

  // initializing pos array
  for (i=0; i<3; i++)
    for (j=0; j<3; j++)
      pos_mu_1_IntruderId[i][j]=FALSE;
  count_mu_1_IntruderId = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<3; i++)
       if (Perm.class_mu_1_IntruderId[i] == count_mu_1_IntruderId)
         {
           pos_mu_1_IntruderId[count_mu_1_IntruderId][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_IntruderId++;
      else break;
    }

  // refinement -- checking priority in general
  while_guard = (count_multisetindex < current_size);
  while_guard = while_guard || (Perm.MTO_class_mu_1_IntruderId() && count_mu_1_IntruderId<3);
  while ( while_guard )
    {
      oldcount_multisetindex = count_multisetindex;
      oldcount_mu_1_IntruderId = count_mu_1_IntruderId;

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_IntruderId() && count_mu_1_IntruderId<3) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].mu_source.isundefined())
                && (*this)[k].mu_source>=3
                && (*this)[k].mu_source<=5)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_IntruderId; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_IntruderId[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_source.isundefined()
                          && (*this)[k].mu_source>=3
                          && (*this)[k].mu_source<=5
                          && pos_mu_1_IntruderId[j][(*this)[k].mu_source-3])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_IntruderId[(*this)[k].mu_source-3] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_IntruderId[j][k] && !goodset_mu_1_IntruderId[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_IntruderId; z>j; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_IntruderId[z][k] = pos_mu_1_IntruderId[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_IntruderId[j][k] && !goodset_mu_1_IntruderId[k])
                                  pos_mu_1_IntruderId[j][k] = FALSE;
                                if (pos_mu_1_IntruderId[j+1][k] && goodset_mu_1_IntruderId[k])
                                  pos_mu_1_IntruderId[j+1][k] = FALSE;
                              }
                            count_mu_1_IntruderId++;
                          }
                      }
                  }
            }
        }

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_IntruderId() && count_mu_1_IntruderId<3) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].mu_dest.isundefined())
                && (*this)[k].mu_dest>=3
                && (*this)[k].mu_dest<=5)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_IntruderId; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_IntruderId[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_dest.isundefined()
                          && (*this)[k].mu_dest>=3
                          && (*this)[k].mu_dest<=5
                          && pos_mu_1_IntruderId[j][(*this)[k].mu_dest-3])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_IntruderId[(*this)[k].mu_dest-3] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_IntruderId[j][k] && !goodset_mu_1_IntruderId[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_IntruderId; z>j; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_IntruderId[z][k] = pos_mu_1_IntruderId[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_IntruderId[j][k] && !goodset_mu_1_IntruderId[k])
                                  pos_mu_1_IntruderId[j][k] = FALSE;
                                if (pos_mu_1_IntruderId[j+1][k] && goodset_mu_1_IntruderId[k])
                                  pos_mu_1_IntruderId[j+1][k] = FALSE;
                              }
                            count_mu_1_IntruderId++;
                          }
                      }
                  }
            }
        }

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_IntruderId() && count_mu_1_IntruderId<3) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].mu_key.isundefined())
                && (*this)[k].mu_key>=3
                && (*this)[k].mu_key<=5)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_IntruderId; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_IntruderId[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_key.isundefined()
                          && (*this)[k].mu_key>=3
                          && (*this)[k].mu_key<=5
                          && pos_mu_1_IntruderId[j][(*this)[k].mu_key-3])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_IntruderId[(*this)[k].mu_key-3] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_IntruderId[j][k] && !goodset_mu_1_IntruderId[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_IntruderId; z>j; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_IntruderId[z][k] = pos_mu_1_IntruderId[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_IntruderId[j][k] && !goodset_mu_1_IntruderId[k])
                                  pos_mu_1_IntruderId[j][k] = FALSE;
                                if (pos_mu_1_IntruderId[j+1][k] && goodset_mu_1_IntruderId[k])
                                  pos_mu_1_IntruderId[j+1][k] = FALSE;
                              }
                            count_mu_1_IntruderId++;
                          }
                      }
                  }
            }
        }

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_IntruderId() && count_mu_1_IntruderId<3) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].mu_nonce1.isundefined())
                && (*this)[k].mu_nonce1>=3
                && (*this)[k].mu_nonce1<=5)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_IntruderId; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_IntruderId[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_nonce1.isundefined()
                          && (*this)[k].mu_nonce1>=3
                          && (*this)[k].mu_nonce1<=5
                          && pos_mu_1_IntruderId[j][(*this)[k].mu_nonce1-3])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_IntruderId[(*this)[k].mu_nonce1-3] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_IntruderId[j][k] && !goodset_mu_1_IntruderId[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_IntruderId; z>j; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_IntruderId[z][k] = pos_mu_1_IntruderId[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_IntruderId[j][k] && !goodset_mu_1_IntruderId[k])
                                  pos_mu_1_IntruderId[j][k] = FALSE;
                                if (pos_mu_1_IntruderId[j+1][k] && goodset_mu_1_IntruderId[k])
                                  pos_mu_1_IntruderId[j+1][k] = FALSE;
                              }
                            count_mu_1_IntruderId++;
                          }
                      }
                  }
            }
        }

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_IntruderId() && count_mu_1_IntruderId<3) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].mu_nonce2.isundefined())
                && (*this)[k].mu_nonce2>=3
                && (*this)[k].mu_nonce2<=5)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_IntruderId; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_IntruderId[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_nonce2.isundefined()
                          && (*this)[k].mu_nonce2>=3
                          && (*this)[k].mu_nonce2<=5
                          && pos_mu_1_IntruderId[j][(*this)[k].mu_nonce2-3])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_IntruderId[(*this)[k].mu_nonce2-3] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_IntruderId[j][k] && !goodset_mu_1_IntruderId[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_IntruderId; z>j; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_IntruderId[z][k] = pos_mu_1_IntruderId[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_IntruderId[j][k] && !goodset_mu_1_IntruderId[k])
                                  pos_mu_1_IntruderId[j][k] = FALSE;
                                if (pos_mu_1_IntruderId[j+1][k] && goodset_mu_1_IntruderId[k])
                                  pos_mu_1_IntruderId[j+1][k] = FALSE;
                              }
                            count_mu_1_IntruderId++;
                          }
                      }
                  }
            }
        }

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_IntruderId() && count_mu_1_IntruderId<3) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].mu_address.isundefined())
                && (*this)[k].mu_address>=3
                && (*this)[k].mu_address<=5)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_IntruderId; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_IntruderId[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_address.isundefined()
                          && (*this)[k].mu_address>=3
                          && (*this)[k].mu_address<=5
                          && pos_mu_1_IntruderId[j][(*this)[k].mu_address-3])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_IntruderId[(*this)[k].mu_address-3] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_IntruderId[j][k] && !goodset_mu_1_IntruderId[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_IntruderId; z>j; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_IntruderId[z][k] = pos_mu_1_IntruderId[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_IntruderId[j][k] && !goodset_mu_1_IntruderId[k])
                                  pos_mu_1_IntruderId[j][k] = FALSE;
                                if (pos_mu_1_IntruderId[j+1][k] && goodset_mu_1_IntruderId[k])
                                  pos_mu_1_IntruderId[j+1][k] = FALSE;
                              }
                            count_mu_1_IntruderId++;
                          }
                      }
                  }
            }
        }
      while_guard = oldcount_multisetindex!=count_multisetindex;
      while_guard = while_guard || (oldcount_mu_1_IntruderId!=count_mu_1_IntruderId);
      while_guard_temp = while_guard;
      while_guard = (count_multisetindex < current_size);
      while_guard = while_guard || count_mu_1_IntruderId<3;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_IntruderId())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          if (pos_mu_1_IntruderId[i][j])
            Perm.class_mu_1_IntruderId[j] = i;
      Perm.undefined_class_mu_1_IntruderId=0;
      for (j=0; j<3; j++)
        if (Perm.class_mu_1_IntruderId[j]>Perm.undefined_class_mu_1_IntruderId)
          Perm.undefined_class_mu_1_IntruderId=Perm.class_mu_1_IntruderId[j];
    }
  }
}
void mu_1_Intruder::Permute(PermSet& Perm, int i)
{
  mu_nonces.Permute(Perm,i);
  mu_messages.Permute(Perm,i);
};
void mu_1_Intruder::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1_Intruder::Canonicalize(PermSet& Perm)
{
  mu_nonces.Canonicalize(Perm);
};
void mu_1_Intruder::SimpleLimit(PermSet& Perm){}
void mu_1_Intruder::ArrayLimit(PermSet& Perm)
{
  mu_nonces.ArrayLimit(Perm);
};
void mu_1_Intruder::Limit(PermSet& Perm)
{
  mu_messages.Limit(Perm);
};
void mu_1_Intruder::MultisetLimit(PermSet& Perm)
{
  mu_messages.MultisetLimit(Perm);
};
void mu_1__type_2::Permute(PermSet& Perm, int i)
{
  static mu_1__type_2 temp("Permute_mu_1__type_2",-1);
  int j;
  for (j=0; j<2; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_2::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: calling SimpleCanonicalize for a multiset.\n"); };
void mu_1__type_2::Canonicalize(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_2::SimpleLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_2::ArrayLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_2::Limit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_2::MultisetLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_Message value[2];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_IntruderId, oldcount_mu_1_IntruderId;
  bool pos_mu_1_IntruderId[3][3];
  bool goodset_mu_1_IntruderId[3];
  int count_multisetindex, oldcount_multisetindex;
  bool pos_multisetindex[2][2];
  bool goodset_multisetindex[2];
  mu_1_Message temp;

  // compact
  for (i = 0, j = 0; i < 2; i++)
    if (valid[i].value())
      {
        if (j!=i)
          array[j++] = array[i];
        else
          j++;
      }
  if (j != current_size) current_size = j;
  for (i = j; i < 2; i++)
    array[i].undefine();
  for (i = 0; i < j; i++)
    valid[i].value(TRUE);
  for (i = j; i < 2; i++)
    valid[i].value(FALSE);

  // bubble sort
  for (i = 0; i < current_size; i++)
    for (j = i+1; j < current_size; j++)
      if (CompareWeight(array[i],array[j])>0)
        {
          temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }
  // initializing pos array
    for (i=0; i<current_size; i++)
      for (j=0; j<current_size; j++)
        pos_multisetindex[i][j]=FALSE;
    count_multisetindex = 1;
    pos_multisetindex[0][0] = TRUE;
    for (i = 1, j = 0 ; i < current_size; i++)
      if (CompareWeight(array[i-1],array[i])==0)
        pos_multisetindex[j][i] = TRUE;
      else
        { count_multisetindex++; pos_multisetindex[++j][i] = TRUE; }
  if (current_size == 1)
    {
      array[0].SimpleLimit(Perm);
    }
  else
    {

  // initializing pos array
  for (i=0; i<3; i++)
    for (j=0; j<3; j++)
      pos_mu_1_IntruderId[i][j]=FALSE;
  count_mu_1_IntruderId = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<3; i++)
       if (Perm.class_mu_1_IntruderId[i] == count_mu_1_IntruderId)
         {
           pos_mu_1_IntruderId[count_mu_1_IntruderId][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_IntruderId++;
      else break;
    }

  // refinement -- checking priority in general
  while_guard = (count_multisetindex < current_size);
  while_guard = while_guard || (Perm.MTO_class_mu_1_IntruderId() && count_mu_1_IntruderId<3);
  while ( while_guard )
    {
      oldcount_multisetindex = count_multisetindex;
      oldcount_mu_1_IntruderId = count_mu_1_IntruderId;

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_IntruderId() && count_mu_1_IntruderId<3) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].mu_source.isundefined())
                && (*this)[k].mu_source>=3
                && (*this)[k].mu_source<=5)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_IntruderId; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_IntruderId[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_source.isundefined()
                          && (*this)[k].mu_source>=3
                          && (*this)[k].mu_source<=5
                          && pos_mu_1_IntruderId[j][(*this)[k].mu_source-3])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_IntruderId[(*this)[k].mu_source-3] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_IntruderId[j][k] && !goodset_mu_1_IntruderId[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_IntruderId; z>j; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_IntruderId[z][k] = pos_mu_1_IntruderId[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_IntruderId[j][k] && !goodset_mu_1_IntruderId[k])
                                  pos_mu_1_IntruderId[j][k] = FALSE;
                                if (pos_mu_1_IntruderId[j+1][k] && goodset_mu_1_IntruderId[k])
                                  pos_mu_1_IntruderId[j+1][k] = FALSE;
                              }
                            count_mu_1_IntruderId++;
                          }
                      }
                  }
            }
        }

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_IntruderId() && count_mu_1_IntruderId<3) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].mu_dest.isundefined())
                && (*this)[k].mu_dest>=3
                && (*this)[k].mu_dest<=5)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_IntruderId; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_IntruderId[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_dest.isundefined()
                          && (*this)[k].mu_dest>=3
                          && (*this)[k].mu_dest<=5
                          && pos_mu_1_IntruderId[j][(*this)[k].mu_dest-3])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_IntruderId[(*this)[k].mu_dest-3] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_IntruderId[j][k] && !goodset_mu_1_IntruderId[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_IntruderId; z>j; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_IntruderId[z][k] = pos_mu_1_IntruderId[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_IntruderId[j][k] && !goodset_mu_1_IntruderId[k])
                                  pos_mu_1_IntruderId[j][k] = FALSE;
                                if (pos_mu_1_IntruderId[j+1][k] && goodset_mu_1_IntruderId[k])
                                  pos_mu_1_IntruderId[j+1][k] = FALSE;
                              }
                            count_mu_1_IntruderId++;
                          }
                      }
                  }
            }
        }

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_IntruderId() && count_mu_1_IntruderId<3) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].mu_key.isundefined())
                && (*this)[k].mu_key>=3
                && (*this)[k].mu_key<=5)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_IntruderId; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_IntruderId[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_key.isundefined()
                          && (*this)[k].mu_key>=3
                          && (*this)[k].mu_key<=5
                          && pos_mu_1_IntruderId[j][(*this)[k].mu_key-3])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_IntruderId[(*this)[k].mu_key-3] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_IntruderId[j][k] && !goodset_mu_1_IntruderId[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_IntruderId; z>j; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_IntruderId[z][k] = pos_mu_1_IntruderId[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_IntruderId[j][k] && !goodset_mu_1_IntruderId[k])
                                  pos_mu_1_IntruderId[j][k] = FALSE;
                                if (pos_mu_1_IntruderId[j+1][k] && goodset_mu_1_IntruderId[k])
                                  pos_mu_1_IntruderId[j+1][k] = FALSE;
                              }
                            count_mu_1_IntruderId++;
                          }
                      }
                  }
            }
        }

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_IntruderId() && count_mu_1_IntruderId<3) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].mu_nonce1.isundefined())
                && (*this)[k].mu_nonce1>=3
                && (*this)[k].mu_nonce1<=5)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_IntruderId; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_IntruderId[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_nonce1.isundefined()
                          && (*this)[k].mu_nonce1>=3
                          && (*this)[k].mu_nonce1<=5
                          && pos_mu_1_IntruderId[j][(*this)[k].mu_nonce1-3])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_IntruderId[(*this)[k].mu_nonce1-3] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_IntruderId[j][k] && !goodset_mu_1_IntruderId[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_IntruderId; z>j; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_IntruderId[z][k] = pos_mu_1_IntruderId[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_IntruderId[j][k] && !goodset_mu_1_IntruderId[k])
                                  pos_mu_1_IntruderId[j][k] = FALSE;
                                if (pos_mu_1_IntruderId[j+1][k] && goodset_mu_1_IntruderId[k])
                                  pos_mu_1_IntruderId[j+1][k] = FALSE;
                              }
                            count_mu_1_IntruderId++;
                          }
                      }
                  }
            }
        }

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_IntruderId() && count_mu_1_IntruderId<3) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].mu_nonce2.isundefined())
                && (*this)[k].mu_nonce2>=3
                && (*this)[k].mu_nonce2<=5)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_IntruderId; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_IntruderId[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_nonce2.isundefined()
                          && (*this)[k].mu_nonce2>=3
                          && (*this)[k].mu_nonce2<=5
                          && pos_mu_1_IntruderId[j][(*this)[k].mu_nonce2-3])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_IntruderId[(*this)[k].mu_nonce2-3] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_IntruderId[j][k] && !goodset_mu_1_IntruderId[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_IntruderId; z>j; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_IntruderId[z][k] = pos_mu_1_IntruderId[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_IntruderId[j][k] && !goodset_mu_1_IntruderId[k])
                                  pos_mu_1_IntruderId[j][k] = FALSE;
                                if (pos_mu_1_IntruderId[j+1][k] && goodset_mu_1_IntruderId[k])
                                  pos_mu_1_IntruderId[j+1][k] = FALSE;
                              }
                            count_mu_1_IntruderId++;
                          }
                      }
                  }
            }
        }

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_IntruderId() && count_mu_1_IntruderId<3) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].mu_address.isundefined())
                && (*this)[k].mu_address>=3
                && (*this)[k].mu_address<=5)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_IntruderId; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_IntruderId[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_address.isundefined()
                          && (*this)[k].mu_address>=3
                          && (*this)[k].mu_address<=5
                          && pos_mu_1_IntruderId[j][(*this)[k].mu_address-3])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_IntruderId[(*this)[k].mu_address-3] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_IntruderId[j][k] && !goodset_mu_1_IntruderId[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_IntruderId; z>j; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_IntruderId[z][k] = pos_mu_1_IntruderId[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_IntruderId[j][k] && !goodset_mu_1_IntruderId[k])
                                  pos_mu_1_IntruderId[j][k] = FALSE;
                                if (pos_mu_1_IntruderId[j+1][k] && goodset_mu_1_IntruderId[k])
                                  pos_mu_1_IntruderId[j+1][k] = FALSE;
                              }
                            count_mu_1_IntruderId++;
                          }
                      }
                  }
            }
        }
      while_guard = oldcount_multisetindex!=count_multisetindex;
      while_guard = while_guard || (oldcount_mu_1_IntruderId!=count_mu_1_IntruderId);
      while_guard_temp = while_guard;
      while_guard = (count_multisetindex < current_size);
      while_guard = while_guard || count_mu_1_IntruderId<3;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_IntruderId())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          if (pos_mu_1_IntruderId[i][j])
            Perm.class_mu_1_IntruderId[j] = i;
      Perm.undefined_class_mu_1_IntruderId=0;
      for (j=0; j<3; j++)
        if (Perm.class_mu_1_IntruderId[j]>Perm.undefined_class_mu_1_IntruderId)
          Perm.undefined_class_mu_1_IntruderId=Perm.class_mu_1_IntruderId[j];
    }
  }
}
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
void mu_1__type_4::Permute(PermSet& Perm, int i)
{
  static mu_1__type_4 temp("Permute_mu_1__type_4",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_4::SimpleCanonicalize(PermSet& Perm)
{
  for (int j=0; j<1; j++)
    array[j].SimpleCanonicalize(Perm);
}
void mu_1__type_4::Canonicalize(PermSet& Perm){};
void mu_1__type_4::SimpleLimit(PermSet& Perm)
{
  for (int j=0; j<1; j++) {
    array[j].SimpleLimit(Perm);
  }
}
void mu_1__type_4::ArrayLimit(PermSet& Perm) {}
void mu_1__type_4::Limit(PermSet& Perm){}
void mu_1__type_4::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_5::Permute(PermSet& Perm, int i)
{
  static mu_1__type_5 temp("Permute_mu_1__type_5",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=3; j<=5; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_IntruderId[Perm.in_mu_1_IntruderId[i]][j-3]];};
void mu_1__type_5::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_5::Canonicalize(PermSet& Perm){};
void mu_1__type_5::SimpleLimit(PermSet& Perm){}
void mu_1__type_5::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_IntruderId;
  int compare;
  static mu_1_Intruder value[3];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_IntruderId[3];
  bool pos_mu_1_IntruderId[3][3];
  // sorting mu_1_IntruderId
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_IntruderId())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_IntruderId[i][j]=FALSE;
      count_mu_1_IntruderId = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_IntruderId; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+3]);
              if (compare==0)
                {
                  pos_mu_1_IntruderId[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_IntruderId; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<3; z++)
                        pos_mu_1_IntruderId[k][z] = pos_mu_1_IntruderId[k-1][z];
                    }
                  value[j] = (*this)[i+3];
                  for (z=0; z<3; z++)
                    pos_mu_1_IntruderId[j][z] = FALSE;
                  pos_mu_1_IntruderId[j][i] = TRUE;
                  count_mu_1_IntruderId++;
                  break;
                }
            }
          if (j==count_mu_1_IntruderId)
            {
              value[j] = (*this)[i+3];
              for (z=0; z<3; z++)
                pos_mu_1_IntruderId[j][z] = FALSE;
              pos_mu_1_IntruderId[j][i] = TRUE;
              count_mu_1_IntruderId++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_IntruderId() && count_mu_1_IntruderId>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_IntruderId; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_IntruderId[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_IntruderId[i][k] && Perm.class_mu_1_IntruderId[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_IntruderId[k] = TRUE;
                    pos_mu_1_IntruderId[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_IntruderId[k] == j && !goodset_mu_1_IntruderId[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_IntruderId[k]>j
                            || ( Perm.class_mu_1_IntruderId[k] == j && !goodset_mu_1_IntruderId[k] ) )
                          Perm.class_mu_1_IntruderId[k]++;
                      Perm.undefined_class_mu_1_IntruderId++;
                    }
                }
            }
        }
    }
}
void mu_1__type_5::Limit(PermSet& Perm){}
void mu_1__type_5::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };

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
              
              mu_ini.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_ini.MultisetSort();
              mu_res.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_res.MultisetSort();
              mu_net.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_net.MultisetSort();
              mu_int.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_int.MultisetSort();
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

          mu_ini.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_ini.MultisetSort();
          mu_res.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_res.MultisetSort();
          mu_net.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_net.MultisetSort();
          mu_int.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_int.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_ini.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_ini.MultisetSort();
              mu_res.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_res.MultisetSort();
              mu_net.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_net.MultisetSort();
              mu_int.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_int.MultisetSort();
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
      mu_ini.MultisetSort();
      mu_res.MultisetSort();
      mu_net.MultisetSort();
      mu_int.MultisetSort();
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
        mu_ini.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_ini.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_res.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_res.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_net.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_net.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_int.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_int.MultisetSort();
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

  mu_ini.SimpleCanonicalize(Perm);

  mu_res.SimpleCanonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_net.MultisetLimit(Perm);
  }

  Perm.SimpleToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_net.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_net.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_int.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_int.MultisetSort();
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

  mu_ini.SimpleCanonicalize(Perm);

  mu_res.SimpleCanonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_net.MultisetLimit(Perm);
  }

  Perm.SimpleToOne();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  mu_net.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_net.MultisetSort();
  mu_int.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_int.MultisetSort();
  BestPermutedState = *workingstate;
  BestInitialized = TRUE;

  cycle=1;
  while (Perm.NextPermutation())
    {
      if (args->perm_limit.value != 0
          && cycle++ >= args->perm_limit.value) break;
      StateCopy(workingstate, &temp);
      mu_net.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_net.MultisetSort();
      mu_int.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_int.MultisetSort();
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

  mu_ini.SimpleCanonicalize(Perm);

  mu_res.SimpleCanonicalize(Perm);

  Perm.SimpleToOne();

  mu_net.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_net.MultisetSort();

  mu_int.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_int.MultisetSort();

};

/********************
  Include
 ********************/
#include "mu_epilog.inc"
