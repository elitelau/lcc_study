char captal( char c ) {
  if( c >= 'a' && c <= 'z' ) {
     return c + 'A' - 'a';
  }
  return c;
}

int main() {
  char c = 'n';
  printf("capitbal of letter `%c is: `%c.\n", 
         c,
         captal(c)
         );
  return 0;
}
