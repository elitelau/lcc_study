// old-style declaration
// in new style, it should be:
// int t(void);
int t();

#include <stdio.h>

int t(a, b, c) unsigned int a; signed char b; int* c; {
  printf("id(%d) grade(%f).\n", b, c );
  return 0;
} 

int tt(unsigned int a, signed char b, int* c) {
  return 0;
} 

int main() {
  unsigned int id = 0x7fffffff;
  double grade = 87.25;
  
  // lcc run result:
  // print result in old-style function:
  // id(-1) grade(-1.998032).
  //
  // gcc run result:
  // print result in old-style function:
  // id(-1) grade(-1.565781).
  printf("print result in old-style function:\n");
  t(1, id, "lily", grade);  // undefined behavior that: double->int*
                            
  printf("print result in new-style function:\n");
  // tt(1, id, grade);  // !!! fail to pass compile

  return 0;
}
