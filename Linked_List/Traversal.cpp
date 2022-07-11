#include <bits/stdc++.h>
using namespace std;
class node
{ //for single node
public:
  int data;
  node *next;
};
void Display(node *head)
{
  node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " -> ";
    temp = temp->next;
  }
  cout << "NULL" << endl;
}
void backwardPrint(node *head)
{
  if (head == NULL)
  {
    return;
  }
  backwardPrint(head->next);
  cout << head->data << "-";
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
  backwardPrint(head);
  Display(head);

  return 0;
}