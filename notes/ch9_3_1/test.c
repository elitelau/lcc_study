#include <stdio.h>
#include <string.h>

int numcmp(char * src, char * dst) {
  return 0;
}

int (*get_cmp_func(int name)) (void*, void*) {
  if( num ) {
    return (int (*)(void*, void*))numcmp;
  }
  return (int (*)(void*, void*))strcmp;
}

int main() {

  int num = 0; // check by number comparing
  char s1[] = "lily";
  char s2[] = "lucy";
  int result = -1;
  result = (*get_cmp_func(num))(s1, s2);
  printf("%s %s %s.\n", 
         s1,
         (result == 0 ? "=" : (result > 0 ? ">" : "<")),
         s2);
  return 0;
}
