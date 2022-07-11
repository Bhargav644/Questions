#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void Left_view(Node *root)
{
    queue<Node *> q;
    q.push(NULL);
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp != NULL)
        {
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
            cout << q.front()->data << " ";
        }
    }
}
void print_inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " -> ";
    print_inorder(root->left);
    print_inorder(root->right);
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(12);
    print_inorder(root);
    cout << endl;
    cout << "Left view is: " << endl;
    Left_view(root);
    cout << '\n';
}