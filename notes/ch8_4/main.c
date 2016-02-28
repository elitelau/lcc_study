// compile use command:  lcc -A -A test.c -c

#include <stdio.h>

int f(void) {
  return 0;
}

int main(int argc, char** argv) 
{
   printf("counter %s zero!\n", 
          f() ? "exceeds " : " is"
   );
   return 0;
}
