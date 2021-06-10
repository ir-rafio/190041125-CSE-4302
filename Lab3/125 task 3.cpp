#include <bits/stdc++.h>
using namespace std;

class Product
{
private:
    string name;
    double unitPrice, discountPercent;
public:

    Product(): name(""), unitPrice(10), discountPercent(0.5)
    {}

    void assignName(string pname)
    {
        name=pname;
    }

    void setPrice(double price)
    {
        unitPrice=price*(price>0)+unitPrice*(price<0);
    }

    void setDiscPercent(double percent)
    {
        bool flag=percent>0 && percent<=10;

        discountPercent=percent*(flag)+discountPercent*(!flag);
    }

    double getSellingPrice(int nos)
    {
        return nos*unitPrice*(100-discountPercent)/100;
    }

    void display()
    {
        cout<<name<<" has a unit price BDT "<<unitPrice<<". Current discount "<<discountPercent<<'%'<<".\n";
    }
};

int main()
{
    Product p;
    p.assignName("Cocola Noodles");
    p.setPrice(10);
    p.setDiscPercent(5);
    p.display();
    cout<<"Current Price of 5 items: BDT "<<p.getSellingPrice(5);

    return 0;
}
