
int g(void) {
  volatile int a = 13;
  return a;
}

main() {
   g();
   return 7;
}
