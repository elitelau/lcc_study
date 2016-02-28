#include <stdio.h>

void print_sex_info( unsigned int* sex ) {
   if( *sex ) {
      printf("male");
   }
   else {
      printf("female");
   }
}

void f() {
  register int i;
  int* ptr = 0;
  char* name;
  unsigned int* flag_ptr;

  struct Student {
     unsigned int id;
     char name[100];
     unsigned int sex : 1; 
  };

  struct Student andrea = {2000601122, "Andrea Kroll", 1};
  name = andrea.name;
  print_sex_info( &andrea.id);
  print_sex_info( &andrea.sex);


  i = 10;
  ptr = &i;
}
