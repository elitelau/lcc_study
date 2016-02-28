extern int a[10];

int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

main() {
  extern int sum(void);
  sum();

  return 0;
}
