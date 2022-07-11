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
void delete_at_head(node* &head){
    node* temp=head;
    head=head->next;
    head->prev=NULL;
    delete temp;
}
/*to delete tthe node in doubly linked list*/
void delete_node(node* &head,int pos){
    if(head==NULL){
        return;
    }
    node* temp=head;
    if(pos==1){
        delete_at_head(head);
        return;
    }
    while(pos-->1 && temp!=NULL){
        temp=temp->next;
    }
    node* ptr=temp->next;
    if(temp->next!=NULL){
        ptr->prev=temp->prev;
    }
    temp->prev->next=ptr;
    delete temp;
}
///////////////////////////////////////
/*for insertion in doubly linked list*/
void insert_at_tail(node* &head,int n){
node* newnode=new node(n);
node* temp=head;
if(head==NULL){
    head=newnode;
    return;
}
while(temp->next!=NULL){
    temp=temp->next;
}
temp->next=newnode;
newnode->prev=temp;

}
/*--------------------------------Display-----------------*/
void Display(node* head){
    cout<<"N";
    while(head!=NULL){
        cout<<" <- "<<head->data<<" -> ";
        head=head->next;
    }
    cout<<"N"<<endl;
}
////////////////////////////////////////////
int main()
{
    // freopen("../input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    node* head=NULL;
    insert_at_tail(head,10);
    insert_at_tail(head,2);
    insert_at_tail(head,1);
    insert_at_tail(head,20);
    insert_at_tail(head,13);
    Display(head);
    delete_node(head,1);
    Display(head);
    return 0;
}