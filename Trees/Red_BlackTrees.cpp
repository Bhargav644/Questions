#include <bits/stdc++.h>
using namespace std;

enum Color
{
    RED,
    BLACK
};
//!
struct Node
{
    int data;
    Node *parent, *left, *right;
    Color color;
    Node(int data)
    {
        this->data = data;
        left = right = parent = NULL;
        this->color = RED;
    }
};

//!
class RedBlackTree
{
private:
    Node *root;

protected:
    void rotateLeft(Node *&, Node *&);
    void rotateRight(Node *&, Node *&);
    void fixViolation(Node *&, Node *&);

public:
    // Constructor
    RedBlackTree() { root = NULL; }
    void insert(int n);
    void inorder();
    void levelOrder();
};
Node *BSTInsert(Node *root, Node *ptr)
{
    if (root == NULL)
    {
        return ptr;
    }
    if (ptr->data < root->data)
    {
        root->left = BSTInsert(root->left, ptr);
        root->left->parent = root;
    }
    else if (ptr->data > root->data)
    {
        root->right = BSTInsert(root->right, ptr);
        root->right->parent = root;
    }
    return root;
}
void inorderHelper(Node *root)
{
    if (root == NULL)
        return;

    inorderHelper(root->left);
    cout << root->data << "  ";
    inorderHelper(root->right);
}
void RedBlackTree::rotateLeft(Node *&root, Node *&pt)
{
    Node *pt_right = pt->right;

    pt->right = pt_right->left;

    if (pt->right != NULL)
        pt->right->parent = pt;

    pt_right->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_right;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;

    else
        pt->parent->right = pt_right;

    pt_right->left = pt;
    pt->parent = pt_right;
}
void RedBlackTree::rotateRight(Node *&root, Node *&pt)
{
    Node *pt_left = pt->left;

    pt->left = pt_left->right;

    if (pt->left != NULL)
        pt->left->parent = pt;

    pt_left->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_left;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;

    else
        pt->parent->right = pt_left;

    pt_left->right = pt;
    pt->parent = pt_left;
}
void RedBlackTree::fixViolation(Node *&root, Node *&ptr)
{
    Node *parent_ptr = NULL;
    Node *grand_parent_ptr = NULL;

    while ((ptr != root) and (ptr->color != BLACK) and ptr->parent->color == RED)
    {
        parent_ptr = ptr->parent;
        grand_parent_ptr = ptr->parent->parent;

        //! just checking wether the parent is left child or right child of grandparent
        if (parent_ptr == grand_parent_ptr->left)
        {
            Node *uncle_ptr = grand_parent_ptr->right;

            /*Case1:either uncle is black or red if red then we need to only recolouring*/
            //! remember NULL also depicts black colour
            if (uncle_ptr != NULL and uncle_ptr->color == RED)
            {
                grand_parent_ptr->color = RED;
                parent_ptr->color = BLACK;
                uncle_ptr->color = BLACK;
                ptr = grand_parent_ptr;
            }
            /*means the uncle is black so the tree needs rotations*/
            else
            {
                /*Case2:ptr is right child of it's parent hence required left-rotation */
                if (ptr == parent_ptr->right)
                {
                    rotateLeft(root, parent_ptr);
                    ptr = parent_ptr;
                    parent_ptr = ptr->parent;
                }

                rotateRight(root, grand_parent_ptr);
                swap(parent_ptr->color, grand_parent_ptr->color);
                ptr = parent_ptr;
            }
        }
        //! parent is  right child of grandparent
        else
        {
            Node *uncle_ptr = grand_parent_ptr->left;

            if (uncle_ptr != NULL and uncle_ptr->color == RED)
            {
                grand_parent_ptr->color = RED;
                parent_ptr->color = BLACK;
                uncle_ptr->color = BLACK;
                ptr = grand_parent_ptr;
            }
            else
            {
                if (ptr == parent_ptr->left)
                {
                    rotateRight(root, parent_ptr);
                    ptr = parent_ptr;
                    parent_ptr = ptr->parent;
                }
                rotateLeft(root, grand_parent_ptr);
                swap(parent_ptr->color, grand_parent_ptr->color);
                ptr = parent_ptr;
            }
        }
    }
    root->color = BLACK;
}
void RedBlackTree::insert(int data)
{
    Node *ptr = new Node(data);

    //*normal insertion in BST
    root = BSTInsert(root, ptr);

    // fixing
    fixViolation(root, ptr);
}

void RedBlackTree::inorder() { inorderHelper(root); }

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    RedBlackTree tree;

    tree.insert(7);
    tree.insert(6);
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);

    cout << "Inorder traversal of created Tree\n";
    tree.inorder();
    return 0;
}