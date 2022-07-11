#include <bits/stdc++.h>
using namespace std;
class leaf{
    public:
    int data;
    leaf *left,*right;

    leaf(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    leaf *root=new leaf(20);
    root->left=new leaf(21);
    root->right=new leaf(22);

    /* TREE 1
        20
       / \
      21 22   
    
    */

    root->left->right=new leaf(24);
    root->right->left=new leaf(23);

    /* TREE 2
        20
       / \
      21 22 
     / \
    23 24 
    
    */
    return 0;
}