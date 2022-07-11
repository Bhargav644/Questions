#include <bits/stdc++.h>
#include<stack>
using namespace std;
class Queue{
    public:
    stack<int> s1;
    stack<int> s2;
    void push(int x){
        s1.push(x);
    }
    void dod(){
       while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    void pop(){
        if(s2.empty()==1){
            return;
        }
        s2.pop();
    }
    int top(){
        if(s2.empty()==1){
            return -1;
        }
        return s2.top();
    }

    bool empty(){
        if(s1.empty()==1 && s2.empty()==1){
            return true;
        }
        return false;
    }
};
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.dod();
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
    q.pop();
    
    cout<<".."<<q.empty()<<endl;
    return 0;
}