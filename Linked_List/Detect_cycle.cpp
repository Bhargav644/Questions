//Floyd's algorithim
//hare and tortoise ALgorithim
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
};
///////////////////////////////////////insert///////////////////////
void insert_data(node* &head,int new_data){
    node* new_node=new node();
    new_node->data=new_data;
    new_node->next=NULL;
    if(head==NULL){
        head=new_node;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
}
///////////--------------------Display-------------------/////////
void Display(node* head){
    while(head!=NULL){
        cout<<head->data<<" -> ";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
////////////////////////////Creates Cycle/////////////////////
void create_cycle_at_position(node* &head,int pos){
        node *temp;
        node *nhead=head;
        int count=1;
        while(nhead->next!=NULL){
            if(count==pos){
                temp=nhead;
            }
            nhead=nhead->next;
            count++;
        }
        nhead->next=temp;
}
////////////////////detect cycle//////////////////////
bool detect_cycle(node *head){
    node* fast=head;//hare
    node* slow=head;//tertoise  ///floyd's algo
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}
void remove_cycle(node* &head){
    node* fast=head;//hare
    node* slow=head;//tertoise  ///floyd's algo
    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(slow!=fast);
    fast=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
}
//////////////////////////////////////////////////////
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    node* head=NULL;
    insert_data(head,20);
    insert_data(head,6);
    insert_data(head,12);
    insert_data(head,13);
    insert_data(head,19);
    create_cycle_at_position(head,3);
    cout<<detect_cycle(head)<<endl;
    remove_cycle(head);
    cout<<detect_cycle(head)<<endl;
    Display(head);
    return 0;
}