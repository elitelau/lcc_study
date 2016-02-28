int f(int, int);

int g(int a, int a);  // duplicate declartion for "a"

int f(int, int) {
   return 0;
}

int k(a, b);   // valid old-stype declaration
int h(a, b) int a, b; // invalid old-stype declartion
