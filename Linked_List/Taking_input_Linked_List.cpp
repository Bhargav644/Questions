    #include <bits/stdc++.h>
    using namespace std;
    class node{
        public:
        int data;
        node* next;
    };
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
    void Display(node* head){
        while(head!=NULL){
            cout<<head->data<<" -> ";
            head=head->next;
        }
        cout<<"NULL"<<endl;
    }
    int main()
    {
        // freopen("../input.txt", "r", stdin);
        //freopen("../output.txt", "w", stdout);
        node* head=NULL;
        int n;
        do{
            cin>>n;
            if(n!=-1){
                insert_data(head,n);
            }
        }while(n!=-1);
        Display(head);
        return 0;
    }