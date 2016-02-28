int add();   // after parsing declaration: ty.ftry = INT, ty.proto = NULL

int add(e, f);  // after parsing declaration: ty.fty = INT, ty.proto = NULL.

int add(a, b) int b; int c; {
   return b + a;
}

int minus();
int minus(a, b, c) int a, b; {
   return a - b;
}

int multi();  // old style
int multi(a, b);  // old style
int multi(int, int);

int multi(a, b) int a, b; {
   return a * b;
}
