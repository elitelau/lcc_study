#include <stdio.h>

void f() {
   int i = 0, j; 
   i = -3 * 4;
   j = -i + 3;
   printf("i is: %d\n", i );
   printf("j is: %d\n", j );
   i = -'a';
   j = -0xf -'a' + 017 + -1u;
   printf("i is: %d\n", i );
   printf("j is: %d\n", j );

   //i = -"asdf";
}

int main() {
  f();
  return 0;
}
