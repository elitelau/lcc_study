# 1 "test.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "test.c"


int main(int argc, char ** argv) {
   int a, b;
   a = 6;
   b = 2;
   printf("roundup(%d, %d) = %d\n", a, b, (((a)+((b)-1))&(~((b)-1))));

   a = 6;
   b = 3;
   printf("roundup(%d, %d) = %d\n", a, b, (((a)+((b)-1))&(~((b)-1))));

   a = 6;
   b = 4;
   printf("roundup(%d, %d) = %d\n", a, b, (((a)+((b)-1))&(~((b)-1))));

   a = 6;
   b = 5;
   printf("roundup(%d, %d) = %d\n", a, b, (((a)+((b)-1))&(~((b)-1))));

   a = 6;
   b = 6;
   printf("roundup(%d, %d) = %d\n", a, b, (((a)+((b)-1))&(~((b)-1))));

   a = 6;
   b = 7;
   printf("roundup(%d, %d) = %d\n", a, b, (((a)+((b)-1))&(~((b)-1))));

   a = 6;
   b = 8;
   printf("roundup(%d, %d) = %d\n", a, b, (((a)+((b)-1))&(~((b)-1))));

   a = 6;
   b = 9;
   printf("roundup(%d, %d) = %d\n", a, b, (((a)+((b)-1))&(~((b)-1))));

   a = 6;
   b = 10;
   printf("roundup(%d, %d) = %d\n", a, b, (((a)+((b)-1))&(~((b)-1))));

   return 0;
}
