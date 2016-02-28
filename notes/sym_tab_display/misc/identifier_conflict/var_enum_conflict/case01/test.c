enum sclass {  // !! sclass is installed in `types' symbol table
  AUTO,
  REGISTER,
  STATIC,
  EXTERN
};

int sclass;

void f(void)  {
  sclass = 0;
}

void g(void) {
  enum sclass s = AUTO;
}
