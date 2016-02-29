void bubble_sort( int arr[], int size) {
  int i, j, min;
 
  for (i = 0; i < size-1; ++i) {
    min = i;
    for (j = i+1; j < size; ++j) { 
      if (arr[j] < arr[min])
         min = j;
    }

    if (i != min) {
       arr[i] += arr[min];
       arr[min] = arr[i] - arr[min];
       arr[i] = arr[i] - arr[min];
    }
  }     
}

/*
int main() {
  #define SIZE 10
  int array[SIZE] = {7, 9, 4, 0, 8, 1, 5, 3, 6, 2};
  int i = 0;
  bubble_sort(array, SIZE);

  for( i = 0; i < SIZE; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");
  return 0;
}

*/
