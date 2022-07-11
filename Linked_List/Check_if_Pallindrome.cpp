    #include <bits/stdc++.h>
    using namespace std;
    struct node{
        int data;
        struct node* next;
    };
    #include<vector>
    int check(vector <int> v){
        int l=0;
        int r=v.size()-1;
        while(l<r){
            if(v[l]==v[r]){
                l++;
                r--;
            }
            else{
                return 0;
            }
        }
        return 1;
    }
    int check_Palindrome(struct node **head){
        vector <int> v;
        struct node* temp=*head;
        while(temp!=NULL){
            v.push_back(temp->data);
            temp=temp->next;
        }
        return check(v);   
    }
    void Display(struct node* head){
    struct node *temp=head;
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
        struct node* first=(struct node*) malloc(sizeof(struct node));
        struct node* second=(struct node*) malloc(sizeof(struct node));
        struct node* third=(struct node*) malloc(sizeof(struct node));
         struct node* fourth=(struct node*) malloc(sizeof(struct node));
        struct node* head=first;
        first->data=3;
        first->next=second;
        second->data=3;
        second->next=third;
        third->data=1;
        third->data=10;
        third->next=NULL;
        Display(head);
        cout<<check_Palindrome(&head);
        return 0;
    }