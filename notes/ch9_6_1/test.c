int main() {
   int flag  =1;
   int a, b, c;
   a = 3, b =4;
   flag ? (void)(a + b) : (void)(a - b);
   //flag ? (a + b) : (a - b);
   return 0;
}
