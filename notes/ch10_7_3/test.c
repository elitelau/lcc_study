typedef enum animal_kind 
{
   TIGER,
   MOUSE,
   DOG
} animal_kind;


void f(animal_kind k) {
   while(1) {
      switch(k) {
      case TIGER:
        printf("tiger\n");
        break;
        break;
      case MOUSE:
        printf("mouse\n");
        break;
        break;
      }
      printf("loop end!\n");
   }
}

int main(int argc, char** argv) {
  f(TIGER);
  return 0;
}
