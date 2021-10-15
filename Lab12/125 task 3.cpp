#include <bits/stdc++.h>
using namespace std;

template<typename T> class my_stack
{
private:
    struct Node
    {
        T key;
        Node *nxt;

        Node(T t): key(t), nxt(nullptr)
        {}

        Node(): nxt(nullptr)
        {}
    };

    Node *head;

public:
    class Empty_Stack
    {};

    my_stack(): head(nullptr)
    {}

    void push(T t)
    {
        Node *temp=head;
        head=new Node(t);
        head->nxt=temp;
    }

    T pop()
    {
        if(!head) throw Empty_Stack();

        Node *temp=head;
        head=head->nxt;
        delete temp;
        return head->key;
    }

    T peek()
    {
        if(!head) throw Empty_Stack();

        return head->key;
    }

    ~my_stack()
    {
        while(head) pop();
    }
};

int main()
{
    my_stack<int> s1;

    try
    {
        s1.pop();
    }
    catch(my_stack<int>::Empty_Stack e)
    {
        cout << "Can not pop: Stack is Empty!\n";
    }

    my_stack<char> s2;

    try
    {
        s2.peek();
    }
    catch(my_stack<char>::Empty_Stack e)
    {
        cout << "Can not peek: Stack is Empty!\n";
    }

    return 0;
}
