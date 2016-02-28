
struct S;  // forward declaration
typedef struct S S;

typedef struct SS {
   int a;
} SS;

int b[];   // ok!
S   a[];   // error!
SS  c[];   // ok!

extern S d[]; // ok!

