#include <bits/stdc++.h>
using namespace std;

class RationalNumber
{
private:
    int a, b;
public:

    RationalNumber(): a(0), b(1)
    {}

    void assign(int numerator,int denominator)
    {
        if(!denominator)
        {
            cout << "MATH ERROR!\n";
            return;
        }

        a=numerator;
        b=denominator;
    }

    double convert()
    {
        return a*1.0/b;
    }

    void invert()
    {
        if(!a)
        {
            cout << "MATH ERROR!\n";
            return;
        }

        swap(a,b);
    }

    void print()
    {
        cout<<"The Rational Number is "<<a<<'/'<<b;
    }
};

int main()
{
    RationalNumber a;

    a.assign(3,2);
    cout<<a.convert()<<'\n';

    a.invert();
    a.print();

    return 0;
}
