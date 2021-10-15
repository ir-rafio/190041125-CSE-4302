#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ara[5]={4, 2, 8, 6, 10}; //Initialization is just for testing
    set<int> s;

    int j=0;
    for(int i=1; i<=10; i++)
    {
        if(i&1) s.insert(i);
        else ara[j++]=i;
    }

    cout << "Array: ";
    for(int i=0; i<5; i++) cout << ara[i] << ' ';
    cout << endl;

    cout << "Set: ";
    for(auto it=s.begin(); it!=s.end(); it++) cout << *it << ' ';
    cout << endl;

    vector <int> v(10);
    merge(ara, ara+5, s.begin(), s.end(), v.begin());

    cout << "Vector: ";
    for(auto it=v.begin(); it!=v.end(); it++) cout << *it << ' ';

    return 0;
}
