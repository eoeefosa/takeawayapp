#include <iostream>
using namespace std;

template <typename T>
T area(T a, T b)
{
    T result = a * b;
    return result;
}

int main()
{
    int x1 = area<int>(10.5, 5);
    double x2 = area<double>(10.5, 5);
    float x3 = area<float>(10.5, 5);
    cout << x1 << ", " << x2 << ", " << x3 << endl;

    return 0;
}