#include <bits/stdc++.h>
using namespace std;

class Furniture
{
private:
    string modelno;

public:
    Furniture()
    {
        cout << "Model No: ";
        cin >> modelno;
    }

    string getModelno() const
    {
        return modelno;
    }

    void display()
    {
        cout << getType() << endl;
        cout << "Model No: " << modelno << endl;
    }

    virtual string getType()=0;
};

class Bed: public Furniture
{
private:
    string type;

public:
    Bed(): type("Bed")
    {}

    string getType()
    {
        return type;
    }
};

class Almirah: public Furniture
{
private:
    string type;

public:
    Almirah(): type("Almirah")
    {}

    string getType()
    {
        return type;
    }
};

class DressingTable: public Furniture
{
private:
    string type;

public:
    DressingTable(): type("DressingTable")
    {}

    string getType()
    {
        return type;
    }
};

bool comp(Furniture* f1, Furniture* f2)
{
    if(f1->getType()=="Bed") return 1;
    if(f2->getType()=="Bed") return 0;

    if(f1->getType()=="Almirah") return 1;
    if(f2->getType()=="Almirah") return 0;

    return 1;
}

sortByFurnitureType(Furniture *f[], int n)
{
    sort(f, f+n, comp);
}

int main()
{
    Furniture *f[20];

    f[0]= new Almirah;
    f[1]= new Bed;

    sortByFurnitureType(f, 2);
    for(int i=0; i<2; i++) f[i]->display();

    return 0;
}
