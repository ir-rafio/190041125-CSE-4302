#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

enum actype{current=1, savings=0};

class BankAccount
{
private:
    int ac;
    string user;
    actype type;
    double balance, min;
public:

    BankAccount()
    {}

    BankAccount(const int acnum, const string name, const actype t, const double curbalance, const double minbalance): ac(acnum), user(name), type(t), balance(curbalance), min(minbalance)
    {}

    void setAccount()
    {
        cout << "Account Number: ";
        cin >> ac;
        cout << "User Name: ";
        cin >> user;

        int t;
        cout << "1. Current Account.\n";
        cout << "2. Savings Account.\n";
        cout << "Account Type: ";
        t=getche(); putchar('\n');
        t&1? type=current: type=savings;

        cout << "Minimum Balance: ";
        cin >> min;

        do
        {
            cout << "Current Balance: ";
            cin >> balance;
        } while(balance<min);

        putchar('\n');
    }

    void display() const
    {
        cout << "Account Number: " << ac << '\n';
        cout << "User Name: " << user << '\n';
        if(type==current) cout << "Account Type: " << "Current" << '\n';
        else  cout << "Account Type: " << "Savings" << '\n';
        cout << "Balance: " << balance << '\n';
    }

    void showBalance() const
    {
        cout << "Balance: " << balance << '\n';
    }

    void deposit(const double amount)
    {
        if(amount<0)  cout << "Deposit Failed!\n";
        balance+=amount;
    }

    void withdraw(const double amount)
    {
        if(amount<0 || balance-amount<min)  cout << "Withdrawal Failed!\n";
        else balance-=amount;
    }

    void giveinterest(int rate=2.5)
    {
        balance+=balance*rate/100*0.9;
    }

    ~BankAccount()
    {
        cout << "Account of " << user << " with account no " << ac << " is destroyed with a balance BDT " << balance << '\n';
    }
};

int main()
{
    BankAccount b;
    b.setAccount();
    int choice, num;

    do
    {
        cout << "1. Display All Info.\n";
        cout << "2. Display Current Balance.\n";
        cout << "3. Deposit.\n";
        cout << "4. Withdraw.\n";
        cout << "5. Give Interest.\n";
        cout << "6. Exit.\n";
        cout << "Insert Choice: ";
        choice=getche()-'0';
        choice%=6;
        putchar('\n');

        switch(choice)
        {
        case 1:
            b.display();
            break;
        case 2:
            b.showBalance();
            break;
        case 3:
            cout << "Amount: ";
            cin >> num;
            b.deposit(num);
            break;
        case 4:
            cout << "Amount: ";
            cin >> num;
            b.withdraw(num);
            break;
        case 5:
            cout << "Rate: ";
            cin >> num;
            b.giveinterest(num);
            break;
        }

        if(choice) putchar('\n');

    } while(choice);

    return 0;
}
