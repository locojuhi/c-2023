#include <iostream>

int calc(int a, int b)
{
    return a+b;
}

float calc(float x, float y)
{
    return x+y;
}

int main(int argc,char** argv)
{
    int answer = calc(1,5);
    std::cout << answer << std::endl;
    return 0;
}


