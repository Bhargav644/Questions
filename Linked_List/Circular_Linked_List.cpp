#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
void insert_in_circular_list(node* &head,int val){
    node* newnode=new node(val);
    if(head==NULL){
        newnode->next=newnode;
        head=newnode;
        return;
    }
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
}
void display(node* head){
    node* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    node* head=NULL;
    insert_in_circular_list(head,10);
    insert_in_circular_list(head,11);
    insert_in_circular_list(head,12);
    display(head);
    return 0;
}