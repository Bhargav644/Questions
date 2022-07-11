#include <bits/stdc++.h>
using namespace std;
#define n 100
class Stack{
    int *arr;
    int top;
    public:
    Stack(){
        arr=new int[n];
        top=-1;
    }
    void push(int x){
        if(top==n-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top]=x;
    }
    void pop(){
        if(top==-1){
            cout<<"Stack Umderflow"<<endl;
            return;
        }
        top--;
    }
    int Top(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        return arr[top];
    }
    bool empty(){
        return top==-1;
    }
};
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    Stack s;
    s.push(23);
    s.push(11);
    s.push(13);
    cout<<s.Top()<<endl;
    s.pop();
    s.pop();
    cout<<s.Top()<<endl;
    s.pop();
    cout<<s.empty()<<endl;
    s.pop();
    return 0;
}