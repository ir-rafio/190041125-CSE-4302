#include <bits/stdc++.h>
using namespace std;

enum role {bat, bowl};
enum hand {lft, rt};
enum style {spin, fast};

class Cricketer
{
private:
    string name;
    int pos;
    hand batting;

    static int n;
    static Cricketer *squad[];

public:
    Cricketer()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Batting Position: ";
        cin >> pos;
        cout << "Enter Batting Hand (0 for Left and 1 for Right): ";
        int temp;
        cin >> temp;
        temp? batting=rt: batting=lft;
    }

    Cricketer(int i)
    {}

    virtual void print() const
    {
        cout << "Name: " << name << endl;
        cout << "Batting Position: " << pos << endl;
        batting? cout << "Right ": cout << "Left ";
        cout << "handed batsman\n";
    }

    virtual role getrole();

    static void add();
    static void display();
    static void read();
    static void write();
};

int Cricketer::n=0;
Cricketer* Cricketer::squad[16];

class Batsman: public Cricketer
{
public:
    Batsman()
    {}

    Batsman(int i): Cricketer(i)
    {}
};

class Bowler: public Cricketer
{
private:
    hand bowling;
    style bstyle;

public:
    Bowler()
    {
        cout << "Enter Bowling Hand (0 for Left and 1 for Right): ";
        int temp;
        cin >> temp;
        temp? bowling=rt: bowling=lft;

        cout << "Enter Bowling Style (0 for Spin and 1 for Fast): ";
        cin >> temp;
        temp? bstyle=spin: bstyle=fast;
    }

    Bowler(int i): Cricketer(i)
    {}

    void print() const
    {
        Cricketer::print();

        bowling? cout << "Right ": cout << "Left ";
        cout << "arm ";
        bstyle? cout << "Fast ": cout << "Spin ";
        cout << "bowler\n";
    }
};

role Cricketer::getrole()
{
    if(typeid(*this)==typeid(Batsman)) return bat;
    else if(typeid(*this)==typeid(Bowler)) return bowl;

    else
    {
        cout << "Player Role Error!\n";
        exit(1);
    }
    return bat;
}

void Cricketer::add()
{
    int temp;
    cout << "0. Batsman\n1. Bowler\nEnter Player Role: ";
    cin >> temp;
    if(temp) squad[n++]=new Bowler;
    else squad[n++]= new Batsman;
}

void Cricketer::display()
{
    cout << endl;
    for(int i=0; i<n; i++)
    {
        cout << i+1 << endl;
        squad[i]->print();
        cout << endl;
    }
}

void Cricketer::write()
{
    int size;

    ofstream out;
    role rol;

    out.open("Squad.DAT", ios::binary|ios::trunc);
    if(!out)
    {
        cout << "Couldn't open file!\n";
        return;
    }

    for(int i=0; i<n; i++)
    {
        rol=squad[i]->getrole();
        if(rol==bat) size=sizeof(Batsman);
        else size=sizeof(Bowler);

        out.write((char*) (&rol), sizeof(rol));
        out.write((char*) (squad[i]), size);

        if(!out)
        {
            cout << "Couldn't write to file!\n";
            return;
        }
    }
}

void Cricketer::read()
{
    int size;

    ifstream in;
    role rol;

    int n=0;
    delete[] squad;

    in.open("Squad.DAT", ios::binary);
    if(!in)
    {
        cout << "Couldn't open file!\n";
        return;
    }

    while(1)
    {
        in.read((char*) (&rol), sizeof(rol));
        if(in.eof()) break;
        if(!in)
        {
            cout << "Couldn't read from file!\n";
            return;
        }

        if(rol==bat)
        {
            squad[n]=new Batsman(0);
            size=sizeof(Batsman);
        }
        else
        {
            squad[n]=new Bowler(0);
            size=sizeof(Bowler);
        }

        in.read((char*) (squad[n++]), size);
        if(!in)
        {
            cout << "Couldn't read from file!\n";
            return;
        }
    }
}

int main()
{
    Cricketer::add();
    Cricketer::add();
    Cricketer::display();

    Cricketer::write();
    Cricketer::read();
    Cricketer::display();

    return 0;
}
