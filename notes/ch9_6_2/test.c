struct student {
   int   id;
   char* name;
};

int main() {
  const void * p;  // const is a qualifer on void type
  const struct student b;
  return 0;
}
