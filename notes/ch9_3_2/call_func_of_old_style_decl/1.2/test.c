// old-style declaration
// in new style, it should be:
// int t(void);
int t();

int t(a, b, c) int a, b, c; {
#include <stdio.h>
  if( a == 1 ) {
    printf("b = %d, c = %d.\n", b, c);
  }
  else {
    printf("b = %d, c = %d.\n", b, c);
  }
  return 0;
}

int main() {
  t(1, 3);
  t(0, 3, 5);
  t(0, 3, 5, 7);

  return 0;
}
