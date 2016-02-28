typedef unsigned char byte;
int byte;

void f(void) {
   ++byte;
}

unsigned int get_first_byte( unsigned int v ) {
   unsigned int byte = v >> 24;
   return byte;
}
