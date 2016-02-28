int f(register int i, int j) {
   return i + j;
}

int main(int argc, char** argv) {
   return f(3, 5);
}
