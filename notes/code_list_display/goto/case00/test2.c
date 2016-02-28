void f(void) {
  int i = 0;
  int j = 0;
  ++i;
  goto L1;   // this jump will be dropped off
{
L1:
  ++j;
}
}
