int x[];

int x[10];

// following code may not be commented:
// issue an error info from decl.c, line 219
 int x[20];

int main( int argc, char** argv ) {
  int i;
  
  x[0] = 10;
  x[9] = 1;
  
  for( i = 0; i < 10; ++i ) {
     printf("%d ", x[i]);
  }
  return 0;  
}
