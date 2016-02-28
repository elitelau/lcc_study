void f(void) {
   int a, b;
   if( a < b ) 
      ++a;
   else
      ++b;
   a -= b;
}

void g(void) {
   int a, b;
   if( a < b ) 
      ++a;
   a = 0;
}
