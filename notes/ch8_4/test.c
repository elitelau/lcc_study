// compile use command:  lcc -A -A test.c -c

#include <stdio.h>

int f(void) {
  static int counter  = 0;
  return counter++;
}

int main(int argc, char** argv) 
{
   printf("counter %s zero!\n", 
          f ? "exceeds " : " is"
   );
   printf("counter %s zero!\n", 
          f() ? "exceeds " : " is"
   );
   return 0;
}
