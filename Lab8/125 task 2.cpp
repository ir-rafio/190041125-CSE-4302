#include <bits/stdc++.h>
using namespace std;

class Lab;
class Lecturer_Room;

class N28_Building
{
private:
    Lab *lnode;
    Lecturer_Room *rnode;

public:
    friend class Lab;
    friend class Lecturer_Room;

    N28_Building(): lnode(nullptr), rnode(nullptr)
    {
        cout << "Welcome to N28 Building\n";
    }

    void showAllLabs() const;
    void showAllLecturerRoom() const;
} n28;

class Lab
{
private:
    string labName;
    int capacity;

public:
    Lab *next, *prev;

    Lab(): next(nullptr)
    {
        if(!n28.lnode) n28.lnode=this;

        else
        {
            for(prev=n28.lnode; prev->next; prev=prev->next);
            prev->next=this;
        }
    }

    string getLabName() const
    {
        return labName;
    }

    int getCapacity() const
    {
        return capacity;
    }

    void setLabName(const string name)
    {
        labName=name;
    }

    int setCapacity(const int num)
    {
        capacity=num;
    }
};

class Lecturer_Room
{
private:
    string roomName;
    int roomNo, capacity;

public:
    Lecturer_Room *next, *prev;

    Lecturer_Room(): next(nullptr)
    {
        if(!n28.rnode) n28.rnode=this;

        else
        {
            for(prev=n28.rnode; prev->next; prev=prev->next);
            prev->next=this;
        }
    }

    string getRoomName() const
    {
        return roomName;
    }

    int getRoomNo() const
    {
        return roomNo;
    }

    int getCapacity() const
    {
        return capacity;
    }

    void setRoomName(const string name)
    {
        roomName=name;
    }

    int setRoomNo(const int num)
    {
        roomNo=num;
    }

    int setCapacity(const int num)
    {
        capacity=num;
    }
};

void N28_Building::showAllLabs() const
{
    cout << "Showing all Labs:\n";

    for(Lab* p=lnode; p; p=p->next) cout << "Lab " << p->getLabName() << '\t' << p->getCapacity() << " Capacity\n";
}

void N28_Building::showAllLecturerRoom() const
{
    cout << "Showing all lecturers room:\n";

    for(Lecturer_Room* p=rnode; p; p=p->next) cout << p->getRoomName() << '\t' << p->getRoomNo() << '\t' << p->getCapacity() << " Capacity\n";
}

int main()
{
    Lab mpk1;
    mpk1.setLabName("MPK1");
    mpk1.setCapacity(60);

    Lab mpk2;
    mpk2.setLabName("MPK2");
    mpk2.setCapacity(60);

    Lab mpk3;
    mpk3.setLabName("MPK3");
    mpk3.setCapacity(50);

    Lab mpk4;
    mpk4.setLabName("MPK4");
    mpk4.setCapacity(50);

    Lecturer_Room hafiz;
    hafiz.setRoomName("Hafiz");
    hafiz.setRoomNo(102);
    hafiz.setCapacity(3);

    Lecturer_Room shafie;
    shafie.setRoomName("Shafie");
    shafie.setRoomNo(105);
    shafie.setCapacity(3);

    Lecturer_Room aisyah;
    aisyah.setRoomName("Aisyah");
    aisyah.setRoomNo(202);
    aisyah.setCapacity(3);

    Lecturer_Room rahim;
    rahim.setRoomName("Rahim");
    rahim.setRoomNo(208);
    rahim.setCapacity(3);

    n28.showAllLabs();
    n28.showAllLecturerRoom();

    return 0;
}
