///*
unsigned int f(register unsigned int a) {
   a >>= 16;
   return a & 0x0f;
}
//*/

/*
unsigned int g(a) register unsigned int a; {
   a >>= 16;
   return a & 0x0f;
}
*/
