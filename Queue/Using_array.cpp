#include <bits/stdc++.h>
using namespace std;
#define n 20


class Queue{
    int *arr;
    int front;
    int back;
    public:
    Queue(){
        arr=new int[n];
        front=-1;
        back=-1;
    }
    void enqueue(int x){
        if(back==n-1){
            cout<<"queue overflow"<<endl;
            return;
        }
        back++;
        arr[back]=x;

        if(front==-1){
            front++;
        }
    }
    void dequeue(){
        if(front==-1 || front>back){
            cout<<"queue is empty"<<endl;
            return;
        }
        front++;
    }
    int peek(){
        if(front==-1 || front>back){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        return arr[front];
    }
    bool empty(){
        if(front==-1 || front>back){
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
    q.enqueue(20);
    q.enqueue(21);
    q.enqueue(22);
    q.enqueue(23);
    cout<<q.peek()<<" ";
    q.dequeue();
    
    cout<<q.peek()<<" ";
    q.dequeue();
    
    cout<<q.peek()<<" ";
    q.dequeue();
    
    cout<<q.peek()<<" "<<endl;
    q.dequeue();

    cout<<".."<<q.empty()<<" ";
    return 0;
}