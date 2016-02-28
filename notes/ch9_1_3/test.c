int main() {
   float f = 3.1415;
   unsigned int i = 0;
   printf( "a float %f after convertion to unsigned is %u.\n", f, (unsigned)f);
   printf( "a float %f after convertion to int is %d.\n", f, (int)f);
   
   f = 3.74;
   printf( "a float %f after convertion to unsigned is %u.\n", f, (unsigned)f);
   printf( "a float %f after convertion to int is %d.\n", f, (int)f);
   return 0;
}
