#include <bits/stdc++.h>
using namespace std;

class FLOAT
{
private:
    float data;

public:
    FLOAT(float f=0.0): data(f) {}

    ~FLOAT()
    {
        cout << "Destroyed FLOAT Object\n";
    }

    void display() const
    {
        cout << data << '\n';
    }

    FLOAT operator+(const FLOAT f)
    {
        return FLOAT(data+f.data);
    }

    FLOAT operator-(const FLOAT f)
    {
        return FLOAT(data-f.data);
    }

    FLOAT operator*(const FLOAT f)
    {
        return FLOAT(data*f.data);
    }

    FLOAT operator/(const FLOAT f)
    {
        if(!f.data)
        {
            cout << "ERROR! Can't divide by 0\n";
            return rand();
        }
        return FLOAT(data/f.data);
    }

    operator int() const
    {
        int x=static_cast<int>(data);
        return x;
    }
};

int main()
{
    FLOAT f(5.502);
    int i=f;
    cout << i << '\n';

    return 0;
}
