void g(int* val) {
   printf("value is %d.\n", *val);
   ++*val;
}

void f(int expr) {
   switch(expr) {
     int i = 4;
     g(&i);
   case 0:
     i = 17;
   default: 
     printf("i = %d\n", i);
   }
}

int main(int argc, char** argv) {
   f(0);
   f(1);
   return 0;
}
