// L2->L3->L4->L2, cause infinite loop
// .L2->.L3 (jump to L2 is equivalent to jump to L3)
// .L4->.L2 (jump to L4 is equivalent to jump to L2)
// .L3->.L4 (jump to L3 is equivalent to jump to L4)
// finally, it calls equal(L3, L4); 
void f(void) {
L2:   
  goto L3;
L4:
  goto L2;
L3:
  goto L4;
}
