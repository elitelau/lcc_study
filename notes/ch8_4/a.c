// compile use command:  lcc -A -A test.c -c

#include <stdio.h>

int f(void) {
  static int counter  = 0;
  return counter++;
}

int main(int argc, char** argv) 
{
   printf("counter %d zero!\n", 
          f ? 0 : 1
   );
   return 0;
}
