#include <stdio.h>

struct student;

int main() {
  struct student *p1 = NULL, *p2;
  int arr1[3] = {1};
  int arr2[4] = {1};
  int (*p3)[];  // incomplete type
  int (*p4)[];

  p3 = &arr1;
  p4 = &arr2;

  if( p1 < p2 ) {
    printf("p1 < p2\n");
  }
  if( (void)(p3 < p4), 1) {
    printf("p3, p4 the two incomplete types involves in comparasion.\n");
  }
  return 0;
}
