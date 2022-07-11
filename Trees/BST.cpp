/*
O(h) where h is the height of tree
worst it can be if tree skewed h=n;
*/
#include <bits/stdc++.h>
using namespace std;
class BST
{
    BST *left;
    BST *right;
    int value;

public:
    BST()
    {
        value = 0;
        left = NULL;
        right = NULL;
    }
    BST(int val)
    {
        value = val;
        left = NULL;
        right = NULL;
    }
    BST *insert(BST *root, int toInsert)
    {
        if (root == NULL)
        {
            return new BST(toInsert);
        }
        if (toInsert > root->value)
        {
            root->right = insert(root->right, toInsert);
        }
        else if (toInsert < root->value)
        {
            root->left = insert(root->left, toInsert);
        }
        return root;
    }
    BST *findMin(BST *root)
    {
        if (root->left == NULL)
        {
            return root;
        }
        findMin(root->left);
    }
    BST *todelete(BST *root, int data)
    {
        if (root == NULL)
            return root;
        else if (root->value > data)
            return root->left = todelete(root->left, data);
        else if (root->value < data)
            return root->right = todelete(root->right, data);
        else
        {
            // leaf node
            if (root->left == NULL and root->right == NULL)
            {
                delete root;
                root = NULL;
                return root;
            }
            // one child
            else if (root->left == NULL)
            {
                struct BST *newNode = root;
                root = root->right;
                delete newNode;
                return root;
            }
            else if (root->right == NULL)
            {
                struct BST *newNode = root;
                root = root->left;
                delete newNode;
                return root;
            }
            // two children
            else
            {
                struct BST *newNode = findMin(root->right);
                root->value = newNode->value;
                root->right = todelete(root->right, newNode->value);
            }
        }
        return root;
    }
    void inorder(BST *root)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left);
        cout << root->value << " -> ";
        inorder(root->right);
    }
    void postorder(BST *root)
    {
        if (!root)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->value << " -> ";
    }
};
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    BST obj, *root = NULL;
    root = obj.insert(root, 50);
    obj.insert(root, 14);
    obj.insert(root, 15);
    obj.insert(root, 1);
    obj.insert(root, 60);
    obj.insert(root, 56);
    obj.insert(root, 12);
    obj.inorder(root); // printing inorder
    cout << endl;
    obj.postorder(root); // printing postorder
    cout << endl;

    obj.todelete(root, 14);

    obj.inorder(root);
    cout << endl;
    //! in BST inorder always  gives sorted list
}
