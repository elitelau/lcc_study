
int main() {
  int a, b, c;
  a = 2, b = 3, c =4;
  0 & (c= a + b); // side effect of "c = a+b" should not happen
  printf("c is with value: %d\n", c);
  return 0;
}
