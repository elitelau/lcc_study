unsigned int f(register unsigned int a) {
   unsigned int semi_byte = 0;
   a &= 0xffff0000;
   a >>= 16;
   return a & 0x0f;
}
