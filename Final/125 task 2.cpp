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
        cout << "Model No: " << modelno << endl << endl;
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
    Furniture *f[15];

    f[0]= new Almirah;
    f[1]= new Bed;
    f[2]= new DressingTable;
    f[3]= new Almirah;
    f[4]= new DressingTable;
    f[5]= new Almirah;
    f[6]= new Bed;
    f[7]= new Bed;
    f[8]= new DressingTable;
    f[9]= new Bed;
    f[10]= new DressingTable;
    f[11]= new DressingTable;
    f[12]= new Almirah;
    f[13]= new Almirah;
    f[14]= new Bed;

    cout << "-------------------------\n";
    sortByFurnitureType(f, 15);
    for(int i=0; i<15; i++) f[i]->display();
    for(int i=0; i<15; i++) delete f[i];

    return 0;
}
