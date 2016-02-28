int f(int, char);  // int f(int, int) is ok, see p289

int f(a, b) int a, b; {
  return a + b;
}

// compatible:
int g(double, int);

int g(a, b) float a; int b; {
   return a + b;
}


// conflicts:
int h(int, int, int);

int h(a, b) int a, b; {
   return 0;
}

// conflicts:
int i(int, int); 

int i(a, b, c) int a, b, c; {
   return 0;
}
