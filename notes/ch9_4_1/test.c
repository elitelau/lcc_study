int main() {
  int i  =10;
  int *p = &i;
  void *q = 0;
  printf("4 + p = %u\n", 4+p);
  printf("4 + p = %u\n", p+4);
  q = q + 4;
  return 0;
}
