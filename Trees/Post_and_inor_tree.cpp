#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
int search(vector<int> in,int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(in[i]==curr){
            return  i;
        }
    }
    return 0;
}
Node* build_tree(vector<int> post,vector<int> in,int start,int end){
   static int index=post.size()-1;
   if(index<0){
       return NULL;
   }
   if(start>end){
       return NULL;
   }
   int current=post[index];
   index--;
   Node* newnode=new Node(current);
   int pos=search(in,start,end,current);
   newnode->right=build_tree(post,in,pos+1,end);
   newnode->left=build_tree(post,in,start,pos-1);

   return newnode;
}
void preorder(Node* pre){
    if(pre==NULL){
        return;
    }
    cout<<pre->data<<" ";
    preorder(pre->left);
    preorder(pre->right);
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    vector<int> post={4,5,2,6,7,3,1}; //? LEFT-RIGHT-ROOT
    vector<int> in={4,2,5,1,6,3,7}; //? LEFT-ROOT-RIGHT

    Node* pre=build_tree(post,in,0,post.size()-1);
    preorder(pre);
    return 0;
}