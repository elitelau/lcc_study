
  enum kinds{
     INT = 0,
     FLOAT = 1
  };

int get_kind( enum kinds k )  {
  return k;
}

int main() {
  enum kinds k;
  int i = 0;

  get_kind(i);

  return 0;
}
