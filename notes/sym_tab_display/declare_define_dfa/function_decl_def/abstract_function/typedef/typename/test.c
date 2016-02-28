int g(char, char);
int main(int argc, char** argv) {
   (int (char, char))g;  // g is transformed into POINTER->FUNCTION(rty=INT, proto=(CHAR,CHAR))
   printf("sizeof function is: %d.\n", 
          sizeof (g)     // cannot function type assigned to sizeof 
          )
}
