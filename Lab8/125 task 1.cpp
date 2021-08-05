#include <bits/stdc++.h>
using namespace std;

class Account
{
private:
    string accountNo, accountName;
    float balance;

public:
    Account(int prefix, int num): accountName(""), balance(0)
    {
        accountNo=to_string(prefix)+"-"+to_string(num);
    }

    string getAccountNo() const
    {
        return accountNo;
    }

    string getAccountName() const
    {
        return accountName;
    }

    float getBalance() const
    {
        return balance;
    }

    void setAccountName(const string name)
    {
        accountName=name;
    }

    void setBalance(float num)
    {
        balance=num;
    }

    virtual void description()=0;
};

class CurrentAccount: public Account
{
private:
    const static int accountPrefix;
    const static int serviceCharge;
    static int nextAccount;

public:
    CurrentAccount(): Account(accountPrefix, nextAccountNo())
    { }

    int getServiceCharge() const
    {
        return serviceCharge;
    }

    int nextAccountNo()
    {
        return nextAccount++;
    }

    void description()
    {
        cout << "Account Number: " << getAccountNo() << '\n';
        cout << "Name: " << getAccountName() << '\n';
        cout << "Account Type: Current\n";
        cout << "Balance: " << getBalance() << '\n';
        cout << "Service Charge: " << serviceCharge << '\n';
        cout << '\n';
    }
};
const int CurrentAccount::serviceCharge=100;
const int CurrentAccount::accountPrefix=100;
int CurrentAccount::nextAccount=1001;

class SavingsAccount: public Account
{
private:
    float interestRate;
    float monthlyDepositAmount;
    const static int accountPrefix;
    static int nextAccount;

public:
    SavingsAccount(): Account(accountPrefix, nextAccountNo())
    { }

    float getInterestRate() const
    {
        return interestRate;
    }

    float getMonthlyDepositAmount() const
    {
        return monthlyDepositAmount;
    }

    int nextAccountNo()
    {
        return nextAccount++;
    }

    void setInterestRate(const float rate)
    {
        interestRate=rate;
    }

    void setMonthlyDepositAmount(const float num)
    {
        monthlyDepositAmount=num;
    }

    void description()
    {
        cout << "Account Number: " << getAccountNo() << '\n';
        cout << "Name: " << getAccountName() << '\n';
        cout << "Account Type: Savings\n";
        cout << "Interest Rate: " << interestRate << '\n';
        cout << "Monthly Deposit Amount: " << monthlyDepositAmount << '\n';
        cout << "Balance: " << getBalance() << '\n';
        cout << '\n';
    }
};
const int SavingsAccount::accountPrefix=200;
int SavingsAccount::nextAccount=1001;

class MonthlyDepositScheme: public Account
{
private:
    float interestRate;
    float monthlyDepositAmount;
    const static int accountPrefix;
    static int nextAccount;
public:
    MonthlyDepositScheme(): Account(accountPrefix, nextAccountNo())
    { }

    float getInterestRate() const
    {
        return interestRate;
    }

    float getMonthlyDepositAmount() const
    {
        return monthlyDepositAmount;
    }

    int nextAccountNo()
    {
        return nextAccount++;
    }

    void setInterestRate(const float rate)
    {
        interestRate=rate;
    }

    void setMonthlyDepositAmount(const float num)
    {
        monthlyDepositAmount=num;
    }
};
const int MonthlyDepositScheme::accountPrefix=300;
int MonthlyDepositScheme::nextAccount=1001;

class LoanAccount: public Account
{
private:
    float interestRate;
    float monthlyDepositAmount;
    const static int accountPrefix;
    static int nextAccount;
public:
    LoanAccount(): Account(accountPrefix, nextAccountNo())
    { }

    float getInterestRate() const
    {
        return interestRate;
    }

    float getMonthlyDepositAmount() const
    {
        return monthlyDepositAmount;
    }

    int nextAccountNo()
    {
        return nextAccount++;
    }

    void setInterestRate(const float rate)
    {
        interestRate=rate;
        setMonthlyDepositAmount();
    }

    void setMonthlyDepositAmount()
    {
        monthlyDepositAmount=-getBalance()*interestRate/1200;
    }

    void description()
    {
        cout << "Account Number: " << getAccountNo() << '\n';
        cout << "Name: " << getAccountName() << '\n';
        cout << "Account Type: Loan\n";
        cout << "Interest Rate: " << interestRate << '\n';
        cout << "Monthly Deposit Amount: " << monthlyDepositAmount << '\n';
        cout << "Balance: " << getBalance() << '\n';
        cout << '\n';
    }
};
const int LoanAccount::accountPrefix=900;
int LoanAccount::nextAccount=1001;

class TwoYearMDS: public MonthlyDepositScheme
{
private:
    float maximumInterest;

public:
    float getMaximumInterest() const
    {
        return maximumInterest;
    }

    void setMaximumInterst(const float num)
    {
        maximumInterest=num;
    }

    void description()
    {
        cout << "Account Number: " << getAccountNo() << '\n';
        cout << "Name: " << getAccountName() << '\n';
        cout << "Account Type: Two Year Monthly Deposit Scheme\n";
        cout << "Interest Rate: " << getInterestRate() << '\n';
        cout << "Monthly Deposit Amount: " << getMonthlyDepositAmount() << '\n';
        cout << "Balance: " << getBalance() << '\n';
        cout << '\n';
    }
};

class FiveYearMDS: public MonthlyDepositScheme
{
private:
    float maximumInterest;

public:
    float getMaximumInterest() const
    {
        return maximumInterest;
    }

    void setMaximumInterst(const float num)
    {
        maximumInterest=num;
    }

    void description()
    {
        cout << "Account Number: " << getAccountNo() << '\n';
        cout << "Name: " << getAccountName() << '\n';
        cout << "Account Type: Five Year Monthly Deposit Scheme\n";
        cout << "Interest Rate: " << getInterestRate() << '\n';
        cout << "Monthly Deposit Amount: " << getMonthlyDepositAmount() << '\n';
        cout << "Balance: " << getBalance() << '\n';
        cout << '\n';
    }
};

class InitialDepositMDS: public MonthlyDepositScheme
{
private:
    float maximumInterest, initialDepositAmount;

public:
    float getMaximumInterest() const
    {
        return maximumInterest;
    }

    float getInitialDepositAmount() const
    {
        return maximumInterest;
    }

    void setInitialDepositAmount(const float num)
    {
        initialDepositAmount=num;
    }

    void description()
    {
        cout << "Account Number: " << getAccountNo() << '\n';
        cout << "Name: " << getAccountName() << '\n';
        cout << "Account Type: Initial Monthly Deposit Scheme\n";
        cout << "Interest Rate: " << getInterestRate() << '\n';
        cout << "Monthly Deposit Amount: " << getMonthlyDepositAmount() << '\n';
        cout << "Balance: " << getBalance() << '\n';
        cout << '\n';
    }
};

int main()
{
    CurrentAccount c;
    c.description();

    SavingsAccount s1, s2;
    s1.setInterestRate(7.5);
    s1.setMonthlyDepositAmount(10000);
    s2.setInterestRate(7.5);
    s2.setMonthlyDepositAmount(12000);
    s1.description();
    s2.description();

    TwoYearMDS d1;
    FiveYearMDS d2;
    InitialDepositMDS d3;
    d1.setInterestRate(7.5);
    d1.setMonthlyDepositAmount(1000);
    d2.setInterestRate(7.5);
    d2.setMonthlyDepositAmount(500);
    d3.setInterestRate(7.5);
    d3.setMonthlyDepositAmount(2000);
    d1.description();
    d2.description();
    d3.description();

    LoanAccount l;
    l.setBalance(-500000);
    l.setInterestRate(10);
    l.description();

    return 0;
}
