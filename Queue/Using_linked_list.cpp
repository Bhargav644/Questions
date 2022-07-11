#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int x){
        data=x;
        next=NULL;
    }
};
class Queue{
    node* front;
    node* back;
    public:
    Queue(){
        front=NULL;
        back=NULL;
    }
    void push(int x){
        node* newnode=new node(x);
        if(front==NULL){
            back=newnode;
            front=newnode;
            return;
        }
        back->next=newnode;
        back=newnode;
    }

    void pop(){
        if(front==NULL){
            cout<<"Queue is empty"<<endl;
            return;
        }
        node* temp=front;
        front=front->next;
        delete temp;
    }

    int peek(){
        if(front==NULL){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return front->data;
    }

    bool empty(){
        if(front==NULL){
            return true;;
        }
        return false;
    }
};
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    Queue q;
    q.push(20);
    q.push(23);
    q.push(2);
    q.push(43);
    q.push(29);

    cout<<q.peek()<<" ";
    q.pop();

    cout<<q.peek()<<" ";
    q.pop();

    cout<<q.peek()<<" ";
    q.pop();

    cout<<q.peek()<<" "<<endl;
    q.pop();

    cout<<"IsEmpty: "<<q.empty()<<endl;
    
    cout<<q.peek()<<" "<<endl;
    q.pop();
    
    cout<<"IsEmpty: "<<q.empty()<<endl;
    return 0;
}