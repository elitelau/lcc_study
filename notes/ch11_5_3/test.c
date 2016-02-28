typedef struct S1 {
   char a[5];
   short s1, s2;
   unsigned code:3, used:1;
   unsigned : 26;
   int amt:7, last;
   short id;
} S1;

typedef struct S2 {
   char a[5];
   short s1, s2;
   unsigned code:3, used:1;
   unsigned : 26;
   int amt:7, last;
   int id;
} S2;

typedef struct S3 {
   int    i;
   short s;
} S3;

int main(int argc, char** argv) {
   printf( "size of struct S1 is: %d.\n", sizeof(S1) );
   printf( "size of struct S2 is: %d.\n", sizeof(S2) );
   printf( "size of struct S3 is: %d.\n", sizeof(S3) );
   return 0;
}
