typedef const unsigned char   cuc;
// typedef const cuc   ccuc;   // check redundent const when call 'qual(..)' function
//

int main(int argc, char** argv) 
{
    printf("sizeof int [3] is: %dbytes.\n", 
            sizeof (int [3]));
    printf("sizeof int [3] is: %dbytes.\n", 
            sizeof (int [3]));
    return 0;
}
