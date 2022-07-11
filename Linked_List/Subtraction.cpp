// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

Node *subLinkedList(Node *l1, Node *l2);

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);

        Node *res = subLinkedList(first, second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends

/* Structure of linked list Node

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};

*/
#include <bits/stdc++.h>
Node *reverseList(Node *l1)
{
    Node *current = l1;
    Node *prev = NULL, *next1;
    while (current != NULL)
    {
        next1 = current->next;
        current->next = prev;
        prev = current;
        current = next1;
    }
    return prev;
}
Node *removeZero(Node *l1)
{
    while (l1 != NULL and l1->data == 0)
    {
        l1 = l1->next;
    }
    if (l1 == NULL)
    {
        Node *temp2 = new Node(0);
        return temp2;
    }
    return l1;
}
long length(Node *root)
{
    long count = 0;
    while (root != NULL)
    {
        count++;
        root = root->next;
    }
    return count;
}
bool largestList(Node *l1, Node *l2)
{ // true if first one is large
    int firstL = length(l1);
    int secondL = length(l2);

    if (firstL > secondL)
    {
        return true;
    }
    else if (secondL > firstL)
    {
        return false;
    }
    else
    {
        while (l1 != NULL and l2 != NULL)
        {
            if (l1->data > l2->data)
            {
                return true;
            }
            else if (l1->data < l2->data)
            {
                return false;
            }
            else
            {
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        return false;
    }
}
Node *subLinkedList(Node *l1, Node *l2)
{
    l1 = removeZero(l1);
    l2 = removeZero(l2);

    int count = 0, ans = 0;

    bool getLarge = largestList(l1, l2);
    if (!getLarge)
    {
        Node *temp = l1;
        l1 = l2;
        l2 = temp;
    }

    l1 = reverseList(l1);
    l2 = reverseList(l2);

    Node *remember = l1;
    while (l1 != NULL and l2 != NULL)
    {
        if ((l1->data + count) < l2->data)
        {
            l1->data = ((l1->data) + 10 + count) - (l2->data);
            count = -1;
        }
        else
        {
            l1->data = (l1->data) + count - (l2->data);
            count = 0;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != NULL)
    {
        if (l1->data + count < 0)
        {
            l1->data = l1->data + 10 + count;
            count = -1;
        }
        else
        {
            l1->data = l1->data + count;
            count = 0;
        }
        l1 = l1->next;
    }

    return removeZero(reverseList(remember));
}