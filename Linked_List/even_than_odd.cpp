#include <bits/stdc++.h>
using namespace std;
class  Node{
    public:
    int data;
     Node* next;
     Node* prev;
     Node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
void insertEnd( Node* &head,int val){
     Node* newnode=new  Node(val);
    if(head==NULL){
        head=newnode;
        return;
    }
     Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
}
void display( Node* head){
    if(head==NULL){
        return;
    }
    while(head!=NULL){
        cout<<head->data<<" -> ";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
/*----------------------------------------even than odd----------*/
Node* rearrangeList(Node* head){
   int i = 1;
    Node *even = NULL;
    Node  *odd = NULL;
    Node *last = head;
    while (last != NULL)
    {
      if(i%2 == 0){
        insertEnd(even , last->data);
      }
      if(i%2 != 0){
        insertEnd(odd , last->data);
      }
      last = last->next;
      i++;
    }
    Node *final = NULL;
    while (even != NULL)
    {
      insertEnd(final , even->data);
      even = even->next;
    }
    while (odd != NULL)
    {
      insertEnd(final , odd->data);
      odd = odd->next;
    }
    return final;
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    Node* head=NULL;
    int n=5;
    int arr[n]={1,2,3,4,5};
    int i=0;
    while(i<n){
        insertEnd(head,arr[i]);
        i++;
    }
    display(head);
    display(rearrangeList(head));
    return 0;
}