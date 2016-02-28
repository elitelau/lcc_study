int dist(char a, char b) {
   return a - b;
}

int f( int(char, char), char, char);
int f( int (*pf)(char, char), char a, char b) {
   return (*pf)(a, b);
}

