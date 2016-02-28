void f(void) {
   int g();

   int g(int, int);  // !! there is no type merge between extern symbols with 
                     //     scope level >= LOCAL.

   int a, b;
   a += b;
}
