int main() {
   char c;
   int i;
   c = -63;
   printf("0x%u.\n", ~(unsigned)0);
   printf("0x%d.\n", ~0);
   i = (c&0200 ? (~0<<8) : 0)|(c&0377);
   printf("char %d after int convertion is: %d.\n", (int)c, i);
   c = 17;
   i = (c&0200 ? (~0<<8) : 0)|(c&0377);
   printf("char %d after int convertion is: %d.\n", (int)c, i);
   return 0;
}
