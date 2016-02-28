#include <stdio.h>

int main() {
   unsigned int flag = 1;
   int *p, *q;
   int a, b;
   a = 3;
   b = 6;
   printf("a = %d, b = %d\n", a, b);

   p = &a;
   q = &b;
   *(flag ? p : q) += 3;
   printf("a = %d, b = %d\n", a, b);

   a = 3, b = 6;
   *(flag ? ++(*p), p : q) += 3;
   printf("a = %d, b = %d\n", a, b);

   return 0;
}
