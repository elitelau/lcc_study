enum {
  S0 = 21,
  S1 = 22,
  S2 = 23,
  S3 = 27,
  S4 = 28,
  S5 = 29,
  S6 = 36,
  S7 = 37,
  S8 = 38,
  S9 = 39
};

void f(char kind) 
{
   int j = 0;  
   switch(kind) {  // set j of different value in case of elimination of common sub-exp
   case S0:
      j = 0; 
      break;
   case S1:
      j = 1; 
      break;
   case S2:
      j = 2; 
      break;
   case S3:
      j = 3; 
      break;
   case S4:
      j = 4; 
      break;
   case S5:
      j = 5; 
      break;
   case S6:
      j = 6; 
      break;
   case S7:
      j = 7; 
      break;
   case S8:
      j = 8; 
      break;
   case S9:
      j = 9; 
      break;
   default:
      j = 10;
      break;
   }
   ++j;
}
