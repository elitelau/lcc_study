void f(void) {
   int a, b, c;
   ++b < c;
   ++b < ++c;
   a, ++b < c;
   ++b < c, a;
   ++b < c++, a;  // !!!! generate condtree, but optimized in compile time by root1()
                  //      considering: COND(LT_exp, RIGHT(CNST(0), CNST(1))) dag delivered to 
                  //      be processed by root1() !!
                   
   a, ++b < c++;  // !!!! does not generate condtree!  
}
