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
int sum_of_all_nodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return sum_of_all_nodes(root->left) + sum_of_all_nodes(root->right) + root->data;
}
// Node *sum_replace(Node *root)
// {
//     static Node *temp = root;
//     if (root == NULL)
//     {
//         return NULL;
//     }
//     int sum = sum_of_all_nodes(root);
//     root->data = sum;
//     sum_replace(root->left);
//     sum_replace(root->right);
//     return temp;
// }
void sum_replace(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    sum_replace(root->left);
    sum_replace(root->right);
    if (root->left != NULL)
    {
        root->data += root->left->data;
    }
    if (root->right != NULL)
    {
        root->data += root->right->data;
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
    print_inorder(root);
    cout << endl;
    sum_replace(root);
    print_inorder(root);
    cout << '\n';
}