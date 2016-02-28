
struct Date {
   unsigned nWeekDay  : 3;    // 0..7   (3 bits)
   unsigned nMonthDay : 6;    // 0..31  (6 bits)
   unsigned           : 0;    // Force alignment to next boundary.
   unsigned nMonth    : 5;    // 0..12  (5 bits)
   unsigned nYear     : 8;    // 0..100 (8 bits)
};

typedef int (*Func) (int);
struct S
{
   unsigned int i;
   Func         f;
};

int main( int argc, char** argv )
{
   struct Date d;
   struct  S    s1;
   return 0;
}
