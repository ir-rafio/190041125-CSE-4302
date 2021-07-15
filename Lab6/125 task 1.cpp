#include <bits/stdc++.h>
using namespace std;

class Coordinate
{
private:
    double x, y;

public:
    Coordinate(double _x=0, double _y=0): x(_x), y(_y) {}

    ~Coordinate()
    {
        cout << "Destroyed Coordinate Object\n";
    }

    float getDistance(const Coordinate &b) const
    {
        return sqrt((x-b.x)*(x-b.x)+(y-b.y)*(y-b.y));
    }


    float getDistance() const
    {
        return getDistance(Coordinate(0,0));
    }

    void display() const
    {
        cout << "(x,y) = " << '(' << x << ',' << y << ")\n";
    }

    void move_x(float val)
    {
        x+=val;
    }

    void move_y(float val)
    {
        y+=val;
    }

    void move(float val)
    {
        move_x(val); move_y(val);
    }

    Coordinate operator++()
    {
        return Coordinate(++x,++y);
    }

    Coordinate operator++(int)
    {
        return Coordinate(x++,y++);
    }

    Coordinate operator--()
    {
        --x; --y;
        return *this;
    }

    Coordinate operator--(int)
    {
        return Coordinate(x--,y--);
    }

    bool operator>(const Coordinate& c) const
    {
        float a=getDistance();
        float b=c.getDistance();


        return a>b;
    }

    bool operator<(const Coordinate& c) const
    {
        float a=getDistance();
        float b=c.getDistance();


        return a<b;
    }

    bool operator==(const Coordinate& c) const
    {
        float a=getDistance();
        float b=c.getDistance();


        return a==b;
    }

    bool operator!=(const Coordinate& c) const
    {
        return !(c==*this);
    }

    bool operator<=(const Coordinate& c) const
    {
        return !(c>*this);
    }

    bool operator>=(const Coordinate& c) const
    {
        return !(c<*this);
    }
};

int main()
{
    return 0;
}
