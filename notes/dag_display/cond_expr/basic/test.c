int f(void) {
  return 0;
}

// !!! note:
// for conditional expression, expr2 & expr3 are interpreted as void type
int main(int argc, char** argv) {
   int a, b, c;
   
   c-- ? a : b;  // or c ? (void)a : (void)b;
   c = f ? a : b;
   c = f() ? a : b;

   return 0;
}
