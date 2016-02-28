// invalid floating constant from the definition
#define NUM 3.14.15
int main() 
{
  float f1 = 3.14.15;
  float f2 = 3.14e+2.15;
  return 0;
}
