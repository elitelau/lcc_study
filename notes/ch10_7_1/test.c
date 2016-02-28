void copy( int* x, int* y, int n ) {
   switch(n%4) 
     while( n > 0 ) 
     {
       case 0: *x++ = *y++; n--;  // n -= 2
       case 3: *x++ = *y++; n--;
       case 2: *x++ = *y++; n--;
       case 1: *x++ = *y++; n--;
     }
}

void print(int* a, int* b, int n) {
  int i;
  for( i = 0; i < n-1; ++i ) {
     printf("%d ", a[i]);
  }
  printf("%d.\n", a[i]);
  
  for( i = 0; i < n-1; ++i ) {
     printf("%d ", b[i]);
  }
  printf("%d.\n", b[i]);
  
}

#define SIZE 20
int main() {
  int a[SIZE], b[SIZE];
  int i = 0, n  = SIZE;
  for( i = 0; i < n; ++i ) {
     a[i] = i + 1;
     b[i] = n - i;
  }

  printf("print a[%d], b[%d], before copy:\n", n, n);
  print(a, b, n);

  copy(a, b , n);


  printf("print a[%d], b[%d], after copy:\n", n, n);
  print(a, b, n);
  return 0;
}
