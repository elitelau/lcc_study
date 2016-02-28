extern int a[];

int f(void) {
  extern int a[10];  // a is an incomplete type
  return sizeof a;
}
