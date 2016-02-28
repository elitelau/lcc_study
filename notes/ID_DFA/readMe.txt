when extracting ID token, it will check whether there is already a symbol exists.

token = stringn(token, (char*)rcp - token);
tsym = lookup(token, identifiers);

problem:
1) an ID maybe corresponding with may symbols(i.e, there are many symbols that 
   named by the ID name), how to determine which one is the match?
   => in lookup function(), its will search a symbol by the name in the specified 
      symbol table. symbols with the same name, stored in a table entry(a linked list).
      but tsym does not know where is the next one with the same string value!!

   e.g. 
   void f( int i, int j ) {}
      struct s {
         int a;
         int b;
      } i;

      {
        i.a = 1; // here, how to know the type of "i"?
      }
   }
