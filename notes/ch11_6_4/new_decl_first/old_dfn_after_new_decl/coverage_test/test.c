// incompatible, since old-style defintion cause integral promotions for sym.protos[]
// fields, when symbol 'k' is added to global scope
void k(float, int);   // void k(double, int); is ok!!
void k(a, b) float a; int b; {
}

