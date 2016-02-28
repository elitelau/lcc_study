enum {
   A = 0,
   B,
   C,
   D
};

void test(int block) {
   switch(block) {
   case A:
      printf("block A covered!\n");
      break;
   case B:
      printf("block B covered!\n");
      break;
   case C:
      printf("block C covered!\n");
      break;
   case D:
      printf("block D covered!\n");
      break;
   default:
     break;
   }
}

int main(int argc, char** argv) {
   test(A);
   test(D);
   return 0;
}
