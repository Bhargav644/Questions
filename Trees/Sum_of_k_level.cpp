#include<bits/stdc++.h>
#include<queue>
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
int sum_of_level_k(Node* root,int k){
    queue<Node*> q;
    int count=0;
    int sum=0;
    q.push(root);
    while(!q.empty()){
            Node* node=q.front();
            count++;
            if(count>(pow(2,k-1)-1) and count<=(pow(2,k)-1)){
                sum+=node->data;
            }
            q.pop();
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
        }
    return sum;    
}
int main(){
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    cout<<sum_of_level_k(root,3)<<endl;
    
}