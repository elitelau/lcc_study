// after preprocessing, 
// it becomes that:
// 
// # 1 "b.c"
// # 1 "<built-in>"
// # 1 "<command line>"
// # 1 "b.c"
// 
// int main() {
//   const char* str = "a\                     b";
// 
//     return 0;
//     }
// so it will not report error
// however, below is not a valid c definition
//
int main() {
  const char* str = "a\
                     b";
  return 0;
}
