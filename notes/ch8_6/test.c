// note: sizeof is a compile time unary operator`

int f() {
  return 4;
}

int* g() {
  return 0;
}

long long int k() {
  return 0;
}

double x() {
  return 0.0;
}

int main(int argc, char** argv) {
  struct student {
     unsigned int id : 3;
     char* name;
  } lily;
  int byte = 1;
  printf("there are %d bytes of long long int type.\n", sizeof(long long int));
  printf("there are %d bytes of int type.\n", sizeof(int));
  printf("there are %d bytes of pointer type.\n", sizeof(int*));

  printf("there are %d bytes.\n", sizeof 4* byte);
  printf("there are %d bytes.\n", sizeof f()* byte);
  printf("there are %d bytes.\n", sizeof g()* byte);
  printf("there are %d bytes.\n", sizeof k()* byte);
  
  printf("there are %d bytes.\n", sizeof x()* byte);
  
  sizeof( lily.id );
  //byte = sizeof int;
  //printf("there are %d bytes.\n", byte);
  return 0;
}
