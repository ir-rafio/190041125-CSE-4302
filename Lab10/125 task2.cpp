#include <bits/stdc++.h>
using namespace std;

class Counter
{
private:
    int count, step;
public:
    Counter(int s=1, int c=0): count(c), step(s)
    {}

    Counter(const Counter& c): count(0), step(c.step)
    {}

    Counter& operator=(const Counter& c)
    {
        count=c.count;
        step=1;
        return *this;
    }

    void setCount(int c)
    {
        count=c;
    }

    void setStep(int s)
    {
        step=s;
    }

    int getCount() const
    {
        return count;
    }

    int getStep() const
    {
        return step;
    }

    Counter& operator++(int)
    {
        count+=step;
        return *this;
    }
};

class ConstantNum
{
private:
    int num;

    ConstantNum(const ConstantNum& n): num(n.num)
    {}

    ConstantNum& operator=(const ConstantNum& n)
    {
        num=n.num;
        return *this;
    }

public:
    ConstantNum(int n=0): num(n)
    {}

    int value() const
    {
        return num;
    }
};

int main()
{
    Counter c1(5, 10);
    c1++;
    cout << c1.getCount() << endl;

    Counter c2(c1);
    c2++;
    cout << c2.getCount() << endl;

    Counter c3=c1;
    c3++;
    cout << c3.getCount() << endl;

    Counter c4;
    c4=c1;
    c4++;
    cout << c4.getCount() << endl;

    ConstantNum n1(5);
    //ConstantNum n2(n1), n3=n1; //This will cause an error.
    ConstantNum n4;
    //n4=n1; //This will cause an error.

    return 0;
}
