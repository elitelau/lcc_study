int add(int a, int b) {
   return a + b;
}

int minus(int a, int b) {
   return a - b;
}

int multiple(int a, int b) {
   return a * b;
}

int divide( int a, int b ) {
   return a /b;
}

typedef int (*pf)(int, int);

typedef enum act_constants {
   ADD,
   MINUS,
   MUL,
   DIV
} act_constants;

// int ()(int, int) get_act_ptr(act_constants act) {
//   return add;
// 
//

int f( int(int, int), int a, int b);

/*
int act(int a, int b) {
   int ret = 0;
   pf* f;

   (int ()(int, int));
   // (*f)(2, 3);
   //ret = (*f)(1, 2);
   return ret;
}
*/
