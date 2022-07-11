#include <bits/stdc++.h>
using namespace std;
class  ListNode{
    public:
     int val;
     ListNode* next;
     ListNode(int data){
        val=val;
        next=NULL;
    }
};
void insertEnd( ListNode* &head,int val){
     ListNode* newnode=new  ListNode(val);
    if(head==NULL){
        head=newnode;
        return;
    }
     ListNode* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}
void display( ListNode* head){
    if(head==NULL){
        return;
    }
    while(head!=NULL){
        cout<<head->val<<" -> ";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* temp=head;
    
        while(temp->next!=NULL){
            const int value=temp->val;
            ListNode* temp2=temp;
            temp=temp->next;
            if(temp->val==value){
                temp2->next=temp->next;
            }
        }
        return head;
    }
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    ListNode* head=NULL;
    int n=3;
    int arr[n]={1,1,1};
    int i=0;
    while(i<n){
        insertEnd(head,arr[i]);
        i++;
    }
    display(head);
    ListNode* newnode=deleteDuplicates(head);
    display(newnode);
    return 0;
}