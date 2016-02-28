int f() {
   extern float g();
   return 0;
}

int g() {
  return 0;
}

int h() {
  extern double g();
  return 1;
}

int k() {
   extern int k;
   return 0;
}
