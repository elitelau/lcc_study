int f(void) {
  extern int a[10];  // a is an array of 10 integers
  return sizeof a;
}
