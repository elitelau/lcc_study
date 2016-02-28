#define roundup(x,n) (((x)+((n)-1))&(~((n)-1)))

int main(int argc, char ** argv) {
   int a, b;
   a = 30;
   b = 1;
   printf("roundup(%d, %d) = %d\n", a, b, roundup(a, b)); 

   a = 30;
   b = 2;
   printf("roundup(%d, %d) = %d\n", a, b, roundup(a, b)); 

   a = 30;
   b = 4;
   printf("roundup(%d, %d) = %d\n", a, b, roundup(a, b)); 

   a = 30;
   b = 8;
   printf("roundup(%d, %d) = %d\n", a, b, roundup(a, b)); 

   a = 30;
   b = 16;
   printf("roundup(%d, %d) = %d\n", a, b, roundup(a, b)); 

   a = 30;
   b = 32;
   printf("roundup(%d, %d) = %d\n", a, b, roundup(a, b)); 

   a = 30;
   b = 64;
   printf("roundup(%d, %d) = %d\n", a, b, roundup(a, b)); 

   a = 30;
   b = 128;
   printf("roundup(%d, %d) = %d\n", a, b, roundup(a, b)); 
   
   //----------------------------------------------------
   a = 13;
   b = 4;
   printf("roundup(%d, %d) = %d\n", a, b, roundup(a, b)); 

   return 0;
}
