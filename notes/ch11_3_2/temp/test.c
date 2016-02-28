int f( int()(int, int) );
typedef int (*pf) (int, int);
int add(int, int);

int g() {
   pf  f1;
   f1 = (int()(int, int))add;

   return 0;
}

int ()(int, int);

/*
int g(void) {
   return sizeof(int()(int, int));
}*/

// int f( int()(int, int), int , int );
