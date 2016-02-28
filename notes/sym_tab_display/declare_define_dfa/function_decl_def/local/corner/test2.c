extern int a[];

extern int a[10];

int sum(void) {
   int i = 0; 
   int val = 0;
   for(; i < 10; ++i ) {
      val += a[i];
   }

   return val;
}
