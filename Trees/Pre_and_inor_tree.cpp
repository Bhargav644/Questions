#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *left;
    Node *right;
    int data;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int Search(vector<int> v1, int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (v1[i] == curr)
        {
            return i;
        }
        else
        {
            continue;
        }
    }
    return 0;
}
Node *build_tree(vector<int> preorder, vector<int> inorder, int start, int end)
{
    static int index = 0;
    if (start > end)
    {
        return NULL;
    }
    if (index > preorder.size() - 1)
    {
        return NULL;
    }
    int curr = preorder[index];
    index++;
    Node *newNode = new Node(curr);

    int pos = Search(inorder, start, end, curr);
    newNode->left = build_tree(preorder, inorder, start, pos - 1);
    newNode->right = build_tree(preorder, inorder, pos + 1, end);

    return newNode;
}
void Print_inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Print_inorder(root->left);
    cout << root->data << " ";
    Print_inorder(root->right);
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    vector<int> v1(5);
    v1 = {1, 2, 4, 3, 5};
    vector<int> v2(5);
    v2 = {4, 2, 1, 5, 3};
    Print_inorder(build_tree(v1, v2, 0, 5));
    return 0;
}