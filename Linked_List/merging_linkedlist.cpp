#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};
int getlength(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
/*--------------recursive way--------*/
node *mergeRecursive(node *&head1, node *&head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    node *result;
    if (head1->data < head2->data)
    {
        result = head1;
        result->next = mergeRecursive(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = mergeRecursive(head1, head2->next);
    }
    return result;
}
/*------------------------------merging two linked list----------*/
node *merge(node *&head1, node *&head2)
{
    node *ptr1 = head1;
    node *ptr2 = head2;
    node *ptr3 = new node(-1);
    node *dummy = ptr3;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data <= ptr2->data)
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }
    while (ptr1 != NULL)
    {
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }
    while (ptr2 != NULL)
    {
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }
    return dummy->next;
}
/*----------------------------------------------------------------------*/
/////////////////////////general insert function//////
void insert_at_tail(node *&head, int val)
{
    node *new_node = new node(val);
    node *temp = head;
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}
//////////////////display////////////////////////////////
void display(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
//////////////////////////////////////////////////////////
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    node *head1 = NULL;
    insert_at_tail(head1, 10);
    insert_at_tail(head1, 11);
    insert_at_tail(head1, 17);
    insert_at_tail(head1, 19);
    insert_at_tail(head1, 32);
    display(head1);
    node *head2 = NULL;
    insert_at_tail(head2, 2);
    insert_at_tail(head2, 9);
    insert_at_tail(head2, 16);
    insert_at_tail(head2, 34);
    insert_at_tail(head2, 50);
    display(head2);
    cout << "Merged array is: " << endl;
    display(merge(head1, head2));
    // display(mergeRecursive(head1, head2));
    return 0;
}