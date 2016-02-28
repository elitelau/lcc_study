int a1[10ul] = {10};
//       |--> require an integer here, not an unsigned. so apply cast here!!!

void f(void) {
   // const folding cause overflow, do not apply const folding here:
   int x = 0x7fff1234 + 0x7fed4321;
}

// !! must const folding here, so check overflow!
int a2[0x7fff1234 + 0x7fed4321];

int main() {
   f();
   return 0;
}
