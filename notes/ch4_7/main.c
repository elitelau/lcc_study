typedef char* (*strings)[10];

typedef char* (*unkn_strings)[];

char f( unkn_strings  ptr_to_arr ) {
   
   return *(*ptr_to_arr)[1];
}

int main( int argc, char** argv ) {
  char str[20] = "hello world!";

  f( &str );

  return 0;
}
