#include <iostream>
using namespace std;

int a=2;

namespace my_namespace
{
    int a=3;
}

int main()
{
    cout << a << endl << my_namespace::a << endl;
    return 0;
}
