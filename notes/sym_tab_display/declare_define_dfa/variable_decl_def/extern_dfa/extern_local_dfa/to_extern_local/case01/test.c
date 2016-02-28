void f(void) {
   extern int a[];
}

int g(void) {
   extern int a[10];  // !! a is an incomplete type
   return sizeof a;  
}
