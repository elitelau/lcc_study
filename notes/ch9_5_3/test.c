void* const get_ptr() {
   return 0;
}

int* const * get_pptr() {
   return 0;
}

int main() {
   int *p;
  //(int* const)(get_ptr()) = p;
  *get_pptr() = p;
  return 0;
}
