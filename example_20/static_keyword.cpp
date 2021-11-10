#include <iostream>

int times_fun_called = 0;

void fun(int foo)
{
    static int times_fun_called = 0;

    std::cout << "i got passed in :" << foo+times_fun_called << std::endl;
    times_fun_called++;
}
int main()
{
    fun(10);
    fun(10);
    fun(10);
    //times_fun_called++; //compilation error
    fun(10);
}
