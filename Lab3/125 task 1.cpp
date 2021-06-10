#include <bits/stdc++.h>
using namespace std;

class Counter
{
private:
    int count, step;

public:

    Counter(): count(0), step(1)
    {}

    void setIncrementStep(int step_val)
    {
        step=step_val;
    }

    void increment()
    {
        count+=step;
    }

    int getCount()
    {
        return count;
    }

    void resetCount()
    {
        count=0;
    }
};

int main()
{
    Counter c;
    c.setIncrementStep(2);

    c.increment();
    cout<<c.getCount()<<'\n';

    c.resetCount();
    cout<<c.getCount();

    return 0;
}
