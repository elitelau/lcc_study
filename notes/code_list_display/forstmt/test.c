void f(void) {
   int i, j;
   for( i = 0; i < 10; ++i ) 
     ++j;
   j = 0;
}

void g(void) {
   int i, j;
   for( i = j; i < 10; ++i ) 
     ++j;
   j = 0;
}
