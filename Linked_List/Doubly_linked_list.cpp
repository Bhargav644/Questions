#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
/*---------------------------Insert at head----------------------------*/
void insert_at_head(node* &head,int n){
    node* newnode=new node(n);
    newnode->next=head;
    if(head!=NULL){
         head->prev=newnode;
    }
    head=newnode;
}
/*------------------------------Insert at tail-----------------------*/
void insert_at_tail(node* &head,int n){
    node* newnode=new node(n);
    node* temp=head;
    if(head==NULL){
        insert_at_head(head,n);
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;

}
/*-------------------Display doubly linked list----------------------*/
void Display(node* head){
    cout<<"N";
    while(head!=NULL){
        cout<<" <- "<<head->data<<" -> ";
        head=head->next;
    }
    cout<<"N"<<endl;
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    node* head=NULL;
    insert_at_tail(head,10);
    insert_at_tail(head,22);
    insert_at_tail(head,12);
    insert_at_tail(head,1);
    insert_at_tail(head,89);
    Display(head);
    return 0;
}