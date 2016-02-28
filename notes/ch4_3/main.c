
void g( a ) struct S1 { int i; int j; } a;
{
   int i;
     
   {
      struct S1 {
         int i;
         int j;
      } a;
   }
}

void f( a ) struct S1 { int i; int j; } a;
{
   int i;
      
   struct S1 {
      int i;
      int j;
   } a;
}

int main(int argc, char** argv )
{
   return 0;
}
