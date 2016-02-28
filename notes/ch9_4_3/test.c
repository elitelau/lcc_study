#include <stdio.h>

int add( int a, int b) {
  return a + b;
}

int (*pf) (int, int);

int main() {
   void* sentinel = 0;
   int (*p1)[10];
   int (*p2)[];

   int arr[10] = {1};
   p1= &arr;
   p2 = &arr;

   pf = add;

   (void)(pf == 0);

   if( p1 == p2 ) {  // !!! fail to compile if ( p1 < p2)
      printf("p1 == p2\n");
   }


   return 0;
}
