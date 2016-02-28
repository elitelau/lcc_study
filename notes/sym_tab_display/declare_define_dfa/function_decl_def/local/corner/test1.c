extern int a[];

int sum(void) {
   extern int a[10];
   int i = 0; 
   int val = 0;
   for(; i < 10; ++i ) {
      val += a[i];
   }

   return val;
}
