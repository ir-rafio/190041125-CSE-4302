#include <bits/stdc++.h>
using namespace std;

template<typename T> T amax(T arr[], int size, int n)
{
    T temp[size];
    copy(arr, arr+size, temp);
    sort(temp, temp+size);
    return temp[size-n];
}

int main()
{
    int a[5]={20, 50, 10, 40, 30};
    cout << amax(a, 5, 2) << endl;

    double b[5]={3.1, 3.2, 3, 3.05, 3.5};
    cout << amax(b, 5, 3) << endl;

    return 0;
}
