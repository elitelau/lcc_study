void f(void) {
   char* s;
   s = "hello world!\n"; //    {symbol table}----------------------->   sym[ARRAY->CHAR]
                         //                                             ("hello world") 
                         //                                                \
                         //                                                 \
                         //                                                  \
                         //                                                   \ sym.u.c.loc
                         //        ASGNP [PTR->CHAR]                           \
                         //           /           \                             |
                         //          /             \                            |
                         // ADDRLP[PTR->PTR->CHAR] ADDRGP[PTR->CHAR]            V
                         //       s             (points to a generated symbol: gen) 
}
