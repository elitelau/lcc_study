void f() {
   extern int g(int);  // add declaration into `externals table, see p300
}

void h() {
   extern int g(int, float); // check type compatibility with the symbol defined in `externals
                             // see p300
}
