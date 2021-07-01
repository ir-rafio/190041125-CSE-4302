#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

class Calculator
{
private:
    int num;

public:

    Calculator(): num(0)
    {}

    Calculator(const int val): num(val)
    {}

    int getValue() const
    {
        return num;
    }

    void setValue(const int Value)
    {
        num=Value;
    }

    void add(const int Value)
    {
        num+=Value;
    }

    void subtract(const int Value)
    {
        num-=Value;
    }

    void multiply(const int Value)
    {
        num*=Value;
    }

    void divideBy(const int Value)
    {
        if(Value) num/=Value;
        else cout << "ERROR! Divide by 0 is undefined.\n";
    }

    void clear()
    {
        num=0;
    }

    void display() const
    {
        cout << "Calculator Display: " << num << "\n--------------------------------------------------\n";
    }

    ~Calculator()
    {
        cout << "\nCalculator object is destroyed.\n--------------------------------------------------\n";
    }
};

int main()
{
    Calculator c;
    int choice, num;

    do
    {
        cout << "1. Set Value.\n";
        cout << "2. Add.\n";
        cout << "3. Subtract.\n";
        cout << "4. Multiply.\n";
        cout << "5. Divide.\n";
        cout << "6. Clear.\n";
        cout << "7. Exit.\n";
        cout << "Insert Choice: ";
        choice=getche()-'0';
        choice%=7;
        putchar(' ');

        switch(choice)
        {
        case 1:
            cin >> num;
            c.setValue(num);
            break;
        case 2:
            cin >> num;
            c.add(num);
            break;
        case 3:
            cin >> num;
            c.subtract(num);
            break;
        case 4:
            cin >> num;
            c.multiply(num);
            break;
        case 5:
            cin >> num;
            c.divideBy(num);
            break;
        case 6:
            c.clear();
            putchar('\n');
        }

        if(choice) c.display();

    } while(choice);

    return 0;
}
