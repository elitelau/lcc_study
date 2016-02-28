struct S
{
   int i;
   int j;
};

void f() {
   struct S {
     int i;
     int j;
   };
}

int main( int argc, char** argv ) {
   f();
   return 0;
}
