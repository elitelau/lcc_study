#include <stdio.h>
int f() {
   return 0;
}

int main() {
   int ret = 0;
   if( f ) {
      printf("success!\n");
   }

   ret = ( f ? 1 : 0 );
   if( ret ) {
      printf("success!\n");
   }


   return 0;
}
