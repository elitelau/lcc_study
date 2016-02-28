void f(void) {
   int i, j;
   ++i; // i = i + 1;
   i++; //      RIGHT
        //      /  \
        //     /  /
        // RIGHT(i, i=i+1);
   --i;
   i--;  // there is a specific on "e++ or e--" that the whole expression has no side effect
         // see root1(Tree p) on "RIGHT" branch.

   j = i++;
   j = ++i;
} 
