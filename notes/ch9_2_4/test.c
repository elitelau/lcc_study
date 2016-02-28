enum type {
    INT,
    FLOAT,
    UNSIGNED,
    VOID = 7,
};

enum kind {
    POINTER,
    STRUCT,
    ARRAY
};

int main() {
   enum type t = VOID;
   const enum kind k = (const enum kind)(t);
   printf("value of k with enumration type is: %d.\n", k);
   return 0;
}
