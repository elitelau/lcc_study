void f(void) {
   extern int counter;
   ++counter;
}

void g(void) {
   extern int counter;
   ++counter;
}

int main(int argc, char** argv) {
  extern int counter;  // !!!cannot declare "int counter" here:
  void set_counter(void);
  
  set_counter();
  f();
  g();


  printf("counter value is: %d.\n", counter);

  return 0;
}
