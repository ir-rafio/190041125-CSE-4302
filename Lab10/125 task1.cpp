#include <bits/stdc++.h>
using namespace std;

class Item
{
private:
    int x, y;
public:
    virtual void setPosition(int _x, int _y)
    {
        x=_x;
        y=_y;
    }
    virtual void bonus(int *stat)=0;
};

class Coin: public Item
{
public:
    Coin(int _x, int _y)
    {
        setPosition(_x, _y);
    }

    void bonus(int *_score)
    {
        *_score+=100+rand()%200;
    }
};

class Boost: public Item
{
public:
    Boost(int _x, int _y)
    {
        setPosition(_x, _y);
    }

    void bonus(int *_isBoosted)
    {
        *_isBoosted+=19+(rand()&31);
    }
};

class Gem: public Item
{
public:
    Gem(int _x, int _y)
    {
        setPosition(_x, _y);
    }

    void bonus(int *_life)
    {
        *_life=std::min(*_life+1, 6);
    }
};

class Protection: public Item
{
public:
    Protection(int _x, int _y)
    {
        setPosition(_x, _y);
    }

    void bonus(int *_protection)
    {
        *_protection+=19+(rand()&31);
    }
};

class SlowDown: public Item
{
public:
    SlowDown(int _x, int _y)
    {
        setPosition(_x, _y);
    }

    void bonus(int *_slowdowntime)
    {
        *_slowdowntime+=19+(rand()&31);
    }
};

class Megacoin: public Coin
{
public:
    Megacoin(int _x, int _y): Coin(_x, _y)
    {}

    void bonus(int *_score)
    {
        *_score+=300+rand()%200;
    }
};

int main()
{
    //Item i(500, 100); //This will cause an error.

    Coin c(500, 100);
    Megacoin mc(500, 100);

    Boost b(500, 100);
    Gem g(500, 100);
    Protection p(500, 100);
    SlowDown s(500, 100);

    Item *i;    //All
    i=&c;       //of
    i=&mc;      //these
    i=&b;       //will
    i=&g;       //run
    i=&p;       //without
    i=&s;       //errors

    return 0;
}
