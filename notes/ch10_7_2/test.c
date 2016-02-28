void f(int* x, int* y, int n) {
   
   // debug on the switch-while mixture statement
   switch(n % 4 ) {
     while(n > 0) {
     case 0: *x++ = *y++; n--;
     case 3: *x++ = *y++; n--;
     case 2: *x++ = *y++; n--;
     case 1: *x++ = *y++; n--;
     }
   }
}

int main() {
#define SIZE 4
  int x[SIZE], y[SIZE];
  int i = 0;
  for( i = 0; i < SIZE; ++i ) {
     x[i] = i;
     y[i] = SIZE - i;
  }
  f(x, y, SIZE-1);

  printf("after copy, two arrays are:\n");
  for( i = 0; i < SIZE; ++i ) {
     printf("%d ", x[i]);
  }
  printf("\n");
  for( i = 0; i < SIZE; ++i ) {
     printf("%d ", y[i]);
  }
  printf("\n");
  return 0;
}
