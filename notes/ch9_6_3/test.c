int main() {
  int i = 0;
  int* const p1 = &i;
  const int* p2 = &i;
  int* p3 = &i;
  unsigned char flag = 0;

  *(flag ? p1 : p3) = 10;
  *(flag ? p3 : p2) = 10;
  *(flag ? p1 : p2) = 10;
  return 0;
}
