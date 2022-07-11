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
Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL || root->data == n1 || root->data == n2)
    {
        return root;
    }
    Node *left = LCA(root->left, n1, n2);
    Node *right = LCA(root->right, n1, n2);

    if (left == NULL)
    {
        return right;
    }
    else if (right == NULL)
    {
        return left;
    }
    else
    { //no body is null hence it is our answer
        return root;
    }
}
int length_from(Node *source, int destination)
{
    queue<Node *> q1;
    q1.push(source);
    q1.push(NULL);
    int levelCount = 0;
    while (!q1.empty())
    {
        Node *top = q1.front();
        q1.pop();
        if (top != NULL)
        {
            if (top->data == destination)
            {
                levelCount++;
                break;
            }
            if (top->left != NULL)
            {
                q1.push(top->left);
            }
            if (top->right != NULL)
            {
                q1.push(top->right);
            }
        }
        else if (!q1.empty())
        {
            q1.push(NULL);
            levelCount++;
        }
    }
    return levelCount - 1;
}
int shortestPath(Node *root, int n1, int n2)
{
    Node *source = LCA(root, n1, n2);
    int d1 = length_from(source, n1);
    int d2 = length_from(source, n2);
    return d1 + d2;
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
    int a, b;
    cin >> a >> b;
    cout << "Shortest Path between two nodes is: " << endl;
    cout << shortestPath(root, a, b);
    cout << '\n';
    return 1;
}