int main() {
  int (*p1)[10];
  int (*p2)[];
  int* const p3;
  int* const p4;
  const int a, b;

  p1= p2;
  p2 = p1;

  p3 = p4;
  a = b;
  return 0;
}
