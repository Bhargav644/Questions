#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
////////////////////////////////////at end////////////////////
void Insert_ElementAt_End(Node* &head,int n){
    Node* newNode=new Node();
    newNode->data=n;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
        return;
    }
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}
//////////////////////////////////////////////at Head/////////////
void  Insert_ElementAt_Head(Node* &head,int n){
    Node* newNode=new Node();//make node at heap
    newNode->data=n;
    newNode->next=head;
    head=newNode;
}
////////////////////////////////////////////////////////////////
void Display(Node* head){
    Node *temp=head;
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
    /////////////////////////////////////
    int total_element;
    cin>>total_element;//total elements to be inserted at end
    Node* head=NULL;
    while(total_element>0){
        int n;
        cin>>n;
        Insert_ElementAt_End(head,n);
        total_element--;
    }
    //////////////////////////////////
    ///for head part
    int total_element1;
    cin>>total_element1;//total elements to be inserted
    while(total_element1>0){
        int n;
        cin>>n;
        Insert_ElementAt_Head(head,n);
        total_element1--;
    }
    ////////////////////////
    Display(head);
    return 0;
}