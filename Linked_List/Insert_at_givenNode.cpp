#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
void insert_at_givenNode(node **head, int value)
{ //gnode-given-Node
    node *ptr = new node();
    ptr->next = (*head)->next;
    ptr->data = value;
    (*head)->next = ptr;
}
void insert_at_given_position(node **head,int pos,int value){
        node *temp=(*head);
        node *ptr = new node();
        while(pos-->1){
            if(temp==NULL){
                return;
            }
            temp=temp->next;
        }
        ptr->next=temp->next;
        ptr->data=temp->data;
        temp->data=value;
        temp->next=ptr;

}
void Display(node *head)
{
    if (head != NULL)
    {
        cout << head->data << " -> ";
        Display(head->next);
    }
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    node *head = NULL;
    node *first = NULL;
    node *second = NULL;
    //form three nodes in heap
    head = new node();
    first = new node();
    second = new node();

    head->data = 4;
    head->next = first;

    first->data = 5;
    first->next = second;

    second->data = 11;
    second->next = NULL;
    insert_at_given_position(&head,2,100);
    Display(head);
    return 0;
}