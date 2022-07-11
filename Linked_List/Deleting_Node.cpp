#include <bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node *next;
};
///////////////////////////DELETE NODE//////////////
void Delete_Node(node **head,int pos){
    node *temp=*head;
    if(*head==NULL){
        return;
    }
    if(pos==1){
         node *todelete=*head;
        *head=(*head)->next;
         delete todelete;
         return;
    }
    pos=pos-1;//becuze we want to get it's previous node
    while(pos-->1){
        if(temp==NULL){
            return;
        }
        temp=temp->next;
    }
    node *todelete=temp->next;
    temp->next=(temp->next)->next;
    delete todelete;

}
/////////////////////////////////delete by value////
void Delete_Node2(node **head,int val){//not for first element by my case
    if(*head==NULL){
        return;
    }
    node *temp=*head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node *todelete=temp->next;
    temp->next=(temp->next)->next;
    delete todelete;
}
//////////////////////////////////////////////////
void Display(node* head)
{
    while(head!=NULL){
        cout<<head->data<<" -> ";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    node *first=new node();
    node *second=new node();
    node *third=new node();
    node *head=first;

    first->data=20;
    first->next=second;

    second->data=11;
    second->next=third;

    third->data=4;
    third->next=NULL;
    Delete_Node(&head,3);
    Display(head);
    return 0;
}