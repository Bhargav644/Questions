//case::::::1 2 3 4
#include <bits/stdc++.h>
#include<stack>
using namespace std;
void to_Bottom(stack<int> &s,int ele){
    if(s.empty()){
        s.push(ele);
        return;
    }
    int topele=s.top();
    s.pop();
    to_Bottom(s,ele);//here element is just staord always and we traversed the whole stack at last we push this
    s.push(topele);
}
void reverse (stack<int> &s){
    if(s.empty()){
        return;
    }
    int ele=s.top();
    s.pop();
    reverse(s);//last value will be 4 then it goes to next line
    to_Bottom(s,ele);
}
void display(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    stack<int> s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    display(s);
    reverse(s);
    display(s);
    return 0;
}