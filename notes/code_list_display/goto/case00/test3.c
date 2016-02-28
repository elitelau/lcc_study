void f(void) {
  int i = 0;
  int j = 0;
  ++i;
  goto L1;   // normal jump
L2:
{
  ++i;
L1:
  ++j;
}
}
