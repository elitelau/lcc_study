void f() {
  int i, j;
  i = 0;
  j = 0;
  goto EXIT_FUNC;
  {
     int a, b, c;
     c = a + b;
  }
  ++i, ++j; // unreachable code
  ++i;
EXIT_FUNC:
  ++i, ++j;
}

void g() {
  int i = 0, j = 0;
  switch(i) {
    ++j;
  case 0:
    break;
    ++j;
  default: break;
  }
}

int main() {
  f();
  g();
  return 0;
}
