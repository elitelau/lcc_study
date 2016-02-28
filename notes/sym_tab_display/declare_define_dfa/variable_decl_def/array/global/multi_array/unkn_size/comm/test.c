extern int a[][];     // ! error, must specify size for the 2nd and/or 3rd dimension
extern int b[][10];   // ! ok, equals to "int b[0][10]"
static int c[][10];   // ! error, because of unknown size for the 1st dimension
int d[][10];          // ! ok, equals to "int d[1][10]"
