void f() {
   extern int g(int);  // add declaration into `externals table, see p300
   extern int l(int);
}

int g(int a, float b); // add declaration into `globals table, see p262
                       // check type compatibiltiy with external declaration, seep263

int l(int a, float b) { // add definition of symbol l into `globals table(p262)
                        // check type compatibility with external declaration(p263)
                        // there is an entrance to call dclglobal in p290, 
   return 0;
}

void h() {
   extern int g(int, float); // check type compatiblity with definition in `globals table, 
                             // see p301
   extern int l(int, float);
}

