// compile success & get correct result in gcc
// however, warning inforamtion in lcc

int main()
{
   //unsigned long long uval = 0xffffffff1ULL;
   // unsigned long long uval = 0xffffffff1;
   unsigned long long uval = 68719476721ull;
   printf( "value is %llu\n", uval );
   return 0;
}
