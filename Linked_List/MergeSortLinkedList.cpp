#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
Node *findMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
Node *merge(Node *left, Node *right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }
    Node *ans;
    if (left->data < right->data)
    {
        ans = left;
        ans->next = merge(left->next, right);
    }
    else
    {
        ans = right;
        ans->next = merge(left, right->next);
    }
    return ans;
}
Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *mid = findMid(head);

    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    Node *ans = merge(left, right);

    return ans;
}
void printNode(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    Node *head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next = new Node(0);
    head->next->next->next = new Node(-1);
    head->next->next->next->next = new Node(-2);
    head->next->next->next->next->next = NULL;

    cout << "Original Linked List :" << endl;
    printNode(head);

    cout << "Sorted Linked List :" << endl;
    printNode(mergeSort(head));
}