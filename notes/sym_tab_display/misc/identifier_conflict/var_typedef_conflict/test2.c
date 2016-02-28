
unsigned int get_first_byte( unsigned int v ) {
   typedef unsigned char byte;
   unsigned int byte = v >> 24;
   return byte;
}
