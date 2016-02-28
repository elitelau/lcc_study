void f(int i) {
   int j;
   switch(i) {
   case 1:
      ++j; 
      break;
   case 2:
   case 3:
      --j;
      break;
   case 10:
      break;
   default:
      break;
   }
}
