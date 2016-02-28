#define INIT  13
void f(int a) {
  //++a; 
}

void g(unsigned int a) {
  //++a;
}

main() {
   f(INIT);
   g(INIT);
   return 7;
}
