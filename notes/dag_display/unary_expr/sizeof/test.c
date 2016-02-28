void f(void) {
   int a, b, c;
   a < b;
   sizeof( a < b );   // does not generate dag, since it's has no side-effect
   c = sizeof( a < b); 
}
