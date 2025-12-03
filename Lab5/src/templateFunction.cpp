#include <iostream>

template <typename T>
T concat(T a, T b)
{
    return a + b;
}

template <typename T, typename... args>
void print(T firstElemnt, args...)
{
    std::cout << firstElemnt;
    print(args...);
}