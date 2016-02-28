#include <stdio.h>

int main() {
  int i = 10, value;
  int a = 4, b = 5;
  ++a, (void)++b;
  value = (void)(i > 0 ? ++a : ++b);
  i > 0 ? (void)(++a) : ++b;
  printf( "the result is :%d\n" , value); 
  return 0;
}
