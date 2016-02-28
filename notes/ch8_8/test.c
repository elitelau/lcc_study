int f();

int main(int argc, char** argv ) {
  int bytes = 0;
  bytes = sizeof f() * 4;
  bytes = sizeof f * 4;
  return 0;
}
