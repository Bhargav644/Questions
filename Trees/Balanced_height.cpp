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
bool isBalance(Node *root, int *height)
{
    int lh = 0, rh = 0;
    if (root == NULL)
    {
        return 1;
    }
    if (!isBalance(root->left, &lh))
    {
        return false;
    }
    if (!isBalance(root->right, &rh))
    {
        return false;
    }
    *height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        false;
    }
}
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}
bool balanced_height(Node *root) //O(n*n)
{
    if (root == NULL)
    {
        return true;
    }
    if (balanced_height(root->left) == false)
    {
        return false;
    }
    if (balanced_height(root->right) == false)
    {
        return false;
    }
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    if (abs(lHeight - rHeight) > 1)
    {
        return false;
    }
    else
    {
        return true;
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
    root->left->left->left = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    print_inorder(root);
    cout << endl;
    int height = 0;
    if (isBalance(root, &height))
    {
        cout << "Balanced Tree" << endl;
    }
    else
    {
        cout << "Unbalanced Tree" << endl;
    }
    cout << '\n';
}