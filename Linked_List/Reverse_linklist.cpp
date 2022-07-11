#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
node *reverse_list(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *temp = reverse_list(head->next);
    head->next->next = head;
    head->next = NULL;
    /*
     box1->box2  //before this call
     box1->next->next//means box2->next
     bo2->next=box1
     box1=NULL    
     */
    return temp;
}
void Display(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    node *first = new node();
    node *second = new node();
    node *third = new node();
    node *head = first;

    first->data = 11;
    first->next = second;

    second->data = 24;
    second->next = third;

    third->data = 66;
    third->next = NULL;
    Display(head);
    Display(reverse_list(head));
    return 0;
}