#include <bits/stdc++.h>
using namespace std;

class Bus
{
private:
    string modelno;
    double price;

public:
    void setModelno()
    {
        cin >> modelno;
    }

    void setPrice()
    {
        cin >> price;
    }

    string getModelno() const
    {
        return modelno;
    }

    double getPrice() const
    {
        return price;
    }

    void display() const
    {
        cout << "Model No: " << modelno << endl;
        cout << "Price: " << price << endl << endl;
    }
};

bool comp(Bus b1, Bus b2)
{
    return b1.getPrice()<b2.getPrice();
}

void sortbyprice(Bus buses[], int n)
{
    sort(buses, buses+n, comp);
}

int main()
{
    Bus buses[5];
    int i;

    for(i=0; i<5; i++)
    {
        cout << "Model No: ";
        buses[i].setModelno();
        cout << "Price: ";
        buses[i].setPrice();
        cout << endl;
    }

    sortbyprice(buses, 5);
    cout << "-------------------------\n";

    for(i=0; i<5; i++) buses[i].display();

    return 0;
}
