int f(void) {
   extern int a[10];
   extern int a[];

   return sizeof a;  // !! a is an array of 10 elements
}
