    #include <bits/stdc++.h>
    using namespace std;
    class node{
        public:
        int data;
        node* next;
    };
    node* reverse_k_nodes(node* head,int k){
        node* prev=NULL;
        node* current=head;
        node* nextptr=NULL;
        int count_second=0;
        node* temp=head;//catching head's previous value;
        while(count_second++<k){
            temp=temp->next;
        }
        int count=0;
        while(count++<k){
            nextptr=current->next;
            current->next=prev;
            prev=current;
            current=nextptr;
        }
        nextptr=prev;
        while( nextptr->next != NULL){
            nextptr=nextptr->next;
        }
        nextptr->next=temp;
        head=prev;
        return head;
        
    }
    void Display(node* head){
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
        node* first=new node();
        node* second=new node();
        node* third=new node();
        node* fourth=new node();
        node* head=first;
        first->data=24;
        first->next=second;

        second->data=12;
        second->next=third;

        third->data=66;
        third->next=fourth;

        fourth->data=111;
        fourth->next=NULL;

        Display(head);
        Display(reverse_k_nodes(head,2));
        return 0;
    }