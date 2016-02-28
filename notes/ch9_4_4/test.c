// !! compile succeed in gcc/g++
#include <stdio.h>

int add( int a, int b) {
  return a + b;
}

int (*pf) (int, int);

int main() {
   void* sentinel = 0;
   pf = add;

   (void)(pf == 0);
   if( pf == sentinel ) {
     printf( "pf is uninitialized!\n" );
   }
   else {
     printf( "pf is initialized!\n" );
   }

   return 0;
}
