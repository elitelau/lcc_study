int a = 1;

int f() {
  return a;
}

int main() {
  int b = 10;
  b + f();
  return 0;
}
