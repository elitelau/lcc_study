// insertion sort?
// sort an array with items that are greater or equal than zero
void sort(int* arr) {
  int i = 0, j;
  int item;
  for( ; (item = arr[i]) > 0; i++ ) {
     for( j = i; j > 0 && arr[j-1] < item; j-- ) 
        arr[j] = arr[j-1];
     arr[j] = item;
  }
}

void print(int* arr, int size) {
   int i = 0;
   printf("%d", arr[i++]);

   for( ; i < size; ++i ) {
      printf(", %d", arr[i]);
   }
   printf("\n");
}

int main(int argc, char** argv) {
  int arr[] = {8, 10, 9, 7, 2, 5, 4, 6, -1};
  sort(arr);
  print(arr, sizeof(arr)/sizeof(int)-1);
  return 0;
}
