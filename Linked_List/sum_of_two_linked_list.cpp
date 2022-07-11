    #include <bits/stdc++.h>
    using namespace std;
    struct ListNode{
        int val;
        ListNode* next;
    };
    int main()
    {
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        
        struct node* head=first;
        first->data=3;
        first->next=second;
        second->data=3;
        second->next=third;
        third->data=1;
        third->data=10;
        third->next=NULL;
        return 0;
    }