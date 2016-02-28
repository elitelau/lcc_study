#define SIZE 10
int add(int a[SIZE]) {
   int sum = 0;
   int i = 0;
   for( i = 0; i < SIZE; ++i ) {
      sum += a[i];
   }

   return sum;
}
