struct employee {
   unsigned int     id;
   unsigned char    age;
   unsigned char    state;
   unsigned int     sex : 1;
   unsigned int     marriage : 2;
   unsigned int     dept : 4;
#ifdef DEMO 
   void*            demo;
#endif
};

int main() {
#include <stdio.h>
   printf("sizeof(employee) is: %d bytes.\n", sizeof(struct employee));
   return 0;
}
