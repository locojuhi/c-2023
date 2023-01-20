#include <iostream>

auto calc(int a, int b)
{
    return a+b;
}

int main(int argc,char ** argv)
{
    auto a = calc(5,-1);
    auto x = 2.0;
    std::cout << "hello, world! - " << a << ", " << x << std::endl;
    return 0;
}

