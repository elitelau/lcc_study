int x[10] = {8, 9, 7, 10, 5, 1, 2, 4, 3, 6};

int f(a, b) int a, b; {
   int a  =10;  // !! comment out!

   extern int x[];
   extern int x[10]; // more detailed type information about the array

   int i = 0;
   for( ; i < 10; ++i ) {
      printf("%d ", x[i]);
   }
   
   return a += b;
}

int main(int argc, char** argv) {
   return f(0, 1);
}
