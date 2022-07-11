#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data=val;
        prev=NULL;
        next=NULL;
    }
};
int getlength(node* head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}
/*------------------------------appending last k node to first----------*/
node* append_k_node_to_first(node* &head,int k){
    int length=getlength(head);
    if(head==NULL || k==0){
        return head;
    }
    int count=0;
    node* rem=head;
    node* temp=head;
    node* that_node=NULL;
    while(temp->next!=NULL){
        count++;
        if((length-k)==count){
            that_node=temp;
        }
        temp=temp->next;
    }
    that_node->next->prev=NULL;
    node* ret=that_node->next;
    that_node->next=NULL;
    temp->next=rem;
    return ret;

}
/*----------------------------------------------------------------------*/
/////////////////////////general insert function//////
void insert_at_tail(node* &head,int val){
    node* new_node=new node(val);
    node* temp=head;
    if(head==NULL){
        head=new_node;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->prev=temp;
}
//////////////////display////////////////////////////////
void display(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
//////////////////////////////////////////////////////////
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    node* head=NULL;
    insert_at_tail(head,10);
    insert_at_tail(head,30);
    insert_at_tail(head,33);
    insert_at_tail(head,74);
    insert_at_tail(head,1);
    insert_at_tail(head,19);
    display(head);
    // append_k_node_to_first(head,0);//74 1 19 10 30 33
    display(append_k_node_to_first(head,3));
    return 0;
}