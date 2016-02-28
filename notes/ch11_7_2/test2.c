void f(int a, int b) {
   register int i  =1;
   // a is referred for 3 times
   ++a;
   a += b;
   a += i;
}
