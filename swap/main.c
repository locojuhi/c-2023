#include <stdio.h>

int main(int argc,char** argv)
{
    int a = 1;
    int b = 2;
    //swap(a,b);
    //int c = b; b = a; a = c;
    printf("%d %d\n", a, b);
    b = b + a;
    a = b - a;
    b = b - a;
    printf("%d %d\n", a, b);
    return 0;
}
