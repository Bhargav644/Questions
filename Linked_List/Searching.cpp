#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
};
///////////////////////////////////SEARCH/////////////
bool search(node* head,int key){
    node *temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
///////////////////////////////////////////////////////
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    node* head=NULL;
    node* first=NULL;
    head=new node();
    first=new node();
    head->data=2;
    head->next=first;
    first->data=5;
    display(head);
    cout<<search(head,2)<<endl;
    return 0;
}