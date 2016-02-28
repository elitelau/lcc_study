typedef enum animal_kind 
{
   TIGER,
   MOUSE,
   DOG
} animal_kind;


void f(animal_kind k) {
   switch(k)  
   case TIGER:
     printf("tiger\n");
     break;
   case MOUSE:
     printf("mouse\n");
     break;
   default:
     break;
}

