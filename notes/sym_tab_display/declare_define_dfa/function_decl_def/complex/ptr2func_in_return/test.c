
// this example is adopted from spec ch6.7.5.3
int (*fpfi(int (*)(long), int))(int, ...);


// those examples are intentionally constructed.
// e.g f(&f1(&f2(100000l), 'a'), 0.5)
int f1(int (*)(int(*)(long), char), double);
int f2(int (*)(int(*)(char (*)(char)), char), double);

// this example is intentionally constructed
//fpfi(int (*)(long), int)
int (*(*pf2(int (*)(long), int))(char, char))(int, int);
double (*(*(*pf3(int (*)(long), int))(char, char))(int, int))(double, double);
