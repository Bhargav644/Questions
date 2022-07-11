/*
NEED--Because of Skewed tree in BST we have to balance the height of tree
AVL tree is a balnced BST
meaning of balanced:: A tree is balanced if it's
height(leftSubtree)-height(rightSubtree) must belongs to {-1,0,1}
in order to balance a tree we have four cases:
-Left Left CASE     --Right Rotation
-Left Right CASE    --Left Than Right Rotation
-Right Right CASE   --Left Rotation
-Right Left CASE    --Right Than Left Rotation
always the height will of BST will be now O(logn)
Roataion will be always between three nodes
*/
#include <bits/stdc++.h>
using namespace std;
class Node
{
    Node *left;
    Node *right;
    int value;

public:
    Node()
    {
        value = 0;
        left = NULL;
        right = NULL;
    }
    Node(int val)
    {
        value = val;
        left = NULL;
        right = NULL;
    }
    Node *insert(Node *root, int toInsert)
    {
        if (root == NULL)
        {
            return new Node(toInsert);
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
    void inorder(Node *root, vector<int> &iO)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left, iO);
        iO.push_back(root->value);
        inorder(root->right, iO);
    }
};
class AVL
{
    AVL *left;
    AVL *right;
    int height;
    int value;

public:
    AVL()
    {
        value = 0;
        left = NULL;
        right = NULL;
        height = 1;
    }
    AVL(int val)
    {
        value = val;
        left = NULL;
        right = NULL;
        height = 1;
    }
    int findHeight(AVL *node)
    {
        if (node == NULL)
            return 0;
        return node->height;
    }
    int getBalance(AVL *node)
    {
        if (node == NULL)
            return 0;
        return findHeight(node->left) - findHeight(node->right);
    }
    //! left rotation
    AVL *leftRotate(AVL *node)
    {

        AVL *temp = node->right;
        AVL *tempL = temp->left;
        temp->left = node;
        node->right = tempL;

        node->height = 1 + max(findHeight(node->left), findHeight(node->right)); //! always update node's height than temp's height
        temp->height = 1 + max(findHeight(temp->left), findHeight(temp->right));

        return temp;
    }
    //! right rotation
    AVL *rightRotate(AVL *node)
    {
        AVL *temp = node->left;
        AVL *tempR = temp->right;
        temp->right = node;
        node->left = tempR;

        node->height = 1 + max(findHeight(node->left), findHeight(node->right)); //! always update node's height than temp's height
        temp->height = 1 + max(findHeight(temp->left), findHeight(temp->right));

        return temp;
    }
    //*-------------main function-----------*//
    AVL *insert(AVL *node, int toInsert)
    {
        if (node == NULL)
        {
            return new AVL(toInsert);
        }
        if (toInsert > node->value)
        {
            node->right = insert(node->right, toInsert);
        }
        else if (toInsert < node->value)
        {
            node->left = insert(node->left, toInsert);
        }
        else
        {
            return node;
        }
        node->height = 1 + max(findHeight(node->left), findHeight(node->right));

        int balance = getBalance(node);
        // after balancing there can be 4 cases ll,RR,LR,Rl;
        if (balance > 1 and toInsert < node->left->value) //! LL
        {
            return rightRotate(node);
        }
        if (balance > 1 and toInsert > node->left->value) //! LR
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 and toInsert > node->right->value) //! RR
        {
            return leftRotate(node);
        }
        if (balance < -1 and toInsert < node->right->value) //! RL
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node; // if node is unchanged
    }
    //*-------------main function-----------*//
    void inorder(AVL *root)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left);
        cout << root->value << " -> ";
        inorder(root->right);
    }
    void postorder(AVL *root)
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
    Node obj, *root = NULL;
    root = obj.insert(root, 50);
    obj.insert(root, 14);
    obj.insert(root, 15);
    obj.insert(root, 1);
    obj.insert(root, 60);
    obj.insert(root, 56);
    obj.insert(root, 12);
    vector<int> iO;
    obj.inorder(root, iO);

    //! can be done only by AVL class
    AVL obj2, *base = NULL;
    base = obj2.insert(base, iO[0]);
    for (int i = 1; i < iO.size(); i++)
    {
        base = obj2.insert(base, iO[i]);
    }
    obj2.inorder(base);
    cout << endl;
    obj2.postorder(base);
    cout << endl;
    //! in BST inorder always  gives sorted list
}