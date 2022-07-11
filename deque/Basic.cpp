#include <bits/stdc++.h>
#include<deque>
using namespace std;
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    deque<int> d1;
    d1.push_back(2);
    d1.push_back(4);
    d1.push_front(3);
    d1.push_front(8);//8 3 2 4

    for(auto i:d1){
        cout<<i<<" ";
    }
    cout<<endl;

    d1.pop_back();

    for(auto i:d1){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}