enum sclass {  // !! sclass is installed in `types' symbol table
   k_auto,
   k_register
};

int sclass;

void f(void)  {
  extern int k_auto;
}

int k_auto;

