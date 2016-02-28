static int counter = 10;

main() {
   extern int counter;
   printf("counter = %d.\n", counter);
   return 0;
}
