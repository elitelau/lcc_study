int main() {
   int i;
   int *const p = &i;

   *p = 10;
   printf("value of integer i is: %d.\n", i);
   p = (void*)0;

   return 0;
}
