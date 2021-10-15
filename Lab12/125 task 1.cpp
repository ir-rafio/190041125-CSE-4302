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
        Node *temp=head;
        head=head->nxt;
        delete temp;
        return head->key;
    }

    T peek()
    {
        return head->key;
    }

};

int main()
{
    my_stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout << s1.peek() << endl;
    cout << s1.pop() << endl;
    cout << s1.peek() << endl;
    cout << endl;

    my_stack<char> s2;
    s2.push('A');
    s2.push('B');
    s2.push('C');
    cout << s2.peek() << endl;
    cout << s2.pop() << endl;
    cout << s2.peek() << endl;

    return 0;
}
