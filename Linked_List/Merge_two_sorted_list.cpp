#include <bits/stdc++.h>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;

    ListNode(int data){
        val=data;
        next=NULL;
    }
};
void insert_at_end(ListNode* &head,int data){
    ListNode* temp=head;
    ListNode* newnode= new ListNode(data);
    if(head==NULL){
        head=newnode;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
    if(list1==NULL){
        return list2;
    }
    if(list2==NULL){
        return list1;
    }
    ListNode* newnode=NULL;
    while(list1!=NULL && list2!=NULL){
        if(list1->val<=list2->val){
            insert_at_end(newnode,list1->val);
            list1=list1->next;
        }
        else if(list1->val>list2->val){
            insert_at_end(newnode,list2->val);
            list2=list2->next;
        }
    }
    while(list1!=NULL && list2==NULL){
        insert_at_end(newnode,list1->val);
        list1=list1->next;
    }

    while(list2!=NULL && list1==NULL){
        insert_at_end(newnode,list2->val);
        list2=list2->next;
    }
    return newnode;
}
void print_list(ListNode* head){
    if(head==NULL){
        return;
    }
    while(head!=NULL){
        cout<<head->val<<" -> ";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    ListNode* first=NULL;
    insert_at_end(first,1);
    insert_at_end(first,3);
    insert_at_end(first,5);
    insert_at_end(first,7);

    ListNode* second=NULL;
    insert_at_end(second,2);
    insert_at_end(second,4);
    insert_at_end(second,6);
    insert_at_end(second,8);
    
    ListNode* third=mergeTwoLists(first,second);
    print_list(first);
    print_list(second);
    print_list(third);
    return 0;
}