// cpp main.c >mai.c.out          :    have no effect
// lcc main.c -o run.x; ./run.x   :    print the content


int main() {
  const char* s = "\x4b" "3"
                  "\x4c";
  printf("%s\n", s);
  return 0;
}
