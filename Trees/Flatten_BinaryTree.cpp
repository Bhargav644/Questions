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
void fllaten_BinaryTree(Node *&root)
{
    if (root == NULL)
    {
        return;
    }
    fllaten_BinaryTree(root->left);
    if (root->left != NULL and root->right != NULL)
    {

        Node *preRight = root->right;
        root->right = root->left;
        Node *check = root->left;
        while (check->right != NULL)
        {
            check = check->right;
        }
        check->right = preRight;
        root->left = NULL;
    }
    else
    {
        return;
    }
}
void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " -> ";
    preOrder(root->left);
    preOrder(root->right);
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->left = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    preOrder(root);
    cout << endl;
    fllaten_BinaryTree(root);
    preOrder(root);
    cout << endl;
}