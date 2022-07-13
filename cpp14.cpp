#include <iostream>
#include <memory>
template <typename T>
T&& runfunc(T&& runnable)
{
    return runnable++;
}





