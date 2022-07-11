#include<bits/stdc++.h>
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
int getlength(node* head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}
/*=====================find intersection point=================*/
int find_intersection_point(node* &head1,node* &head2){
    int l1=getlength(head1);
    int l2=getlength(head2);
    int count=0;
    node* ptr1=head1;
    // here lets we suppose that first list is always greater than second list
    while(ptr1!=NULL){
        if(count==abs(l1-l2)){
            break;
        }
        count++;
        ptr1=ptr1->next;
    }
    while(ptr1!=NULL && head2!=NULL){
        if(ptr1->data==head2->data){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        head2=head2->next;
    }
    return -1;
}
///////////////////////////////////insert function//////////////
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
    node* head1=NULL;
    insert_at_tail(head1,10);
    insert_at_tail(head1,30);
    insert_at_tail(head1,33);
    insert_at_tail(head1,74);
    insert_at_tail(head1,1);
    insert_at_tail(head1,19);
    insert_at_tail(head1,6);
    insert_at_tail(head1,21);
    insert_at_tail(head1,5);
    display(head1);
    node* head2=NULL;
    insert_at_tail(head2,99);
    insert_at_tail(head2,35);
    insert_at_tail(head2,31);
    insert_at_tail(head2,100);
    insert_at_tail(head2,6);
    insert_at_tail(head2,21);
    insert_at_tail(head2,5);
    // intersect(head1,head2,5);//pos is with respect to head2
    display(head2);

    cout<<find_intersection_point(head1,head2);
    return 0;
}