#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

class ZooAnimal
{
private:
    string name;
    unsigned birth, cage, height;
    float weight;
public:

    ZooAnimal(string species="Monkey", unsigned year=2015, unsigned cg=100, unsigned ht=60, float wt=25): name(species), birth(year>2021? 2021: year), cage(cg), height(ht), weight(wt<0? 25: wt)
    {}

    void getInformation()
    {
        cout << "Name: " << name << '\n';
        cout << "Birth Year: " << birth << '\n';
        cout << "Cage No.: " << cage << '\n';
        cout << "Height: " << height << " cm\n";
        cout << "Weight: " << weight << " kg\n";

        int age=getAge();
        cout << "Age: " << age << " year";
        if(age-1) putchar('s');

        putchar('\n');
    }

    string getName() const
    {
        return name;
    }

    int getBirthYear() const
    {
        return birth;
    }

    int getCageNo() const
    {
        return cage;
    }

    int getHeight() const
    {
        return height;
    }

    float getWeight() const
    {
        return weight;
    }

    void setName()
    {
        cout << "Name of Animal: ";
        cin >> name;
    }

    void setBirthYear()
    {
        do
        {
            cout << "Birth Year: ";
            cin >> birth;
        } while(birth>2021);
    }

    void setCageNo()
    {
        cout << "Cage No. : ";
        cin >> cage;
    }

    void setHeight()
    {
        cout << "Height: ";
        cin >> height;
    }

    void setWeight()
    {
        cout << "Weight: ";
        cin >> weight;

        if(weight<0)
        {
            cout << "Weight can not be negative!\n";
            weight=25;
        }
    }

    int getAge() const
    {
        return 2021-birth;
    }

    bool operator==(int data) const
    {
        return data==static_cast<int>(weight);
    }

    void operator--(int dec)
    {
        height-=dec;
    }
};

int main()
{
    ZooAnimal z;
    int choice, temp;

    do
    {
        cout << "1. Set Name.\n";
        cout << "2. Set Birth Year.\n";
        cout << "3. Set Cage No.\n";
        cout << "4. Set Height.\n";
        cout << "5. Set Weight.\n";
        cout << "6. Display All Info.\n";
        cout << "7. Check Weight.\n";
        cout << "8. Decrease Height.\n";
        cout << "9. Exit.\n";
        cout << "Insert Choice: ";
        choice=getche()-'0';
        choice%=9;
        putchar('\n');

        switch(choice)
        {
        case 1:
            z.setName();
            break;
        case 2:
            z.setBirthYear();
            break;
        case 3:
            z.setCageNo();
            break;
        case 4:
            z.setHeight();
            break;
        case 5:
            z.setWeight();
            break;
        case 6:
            z.getInformation();
            break;
        case 7:
            cout << "Enter Weight: ";
            cin >> temp;
            puts(z==temp? "Correct!": "Wrong!");
            break;
        case 8:
            cout << "Enter Error: ";
            cin >> temp;
            z.operator--(temp);
        }

        if(choice) putchar('\n');

    } while(choice);

    return 0;
}
