#include <bits/stdc++.h>
 
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int k){
        val=k;
        left=right=NULL;
    }
};

void printNodesAt_K(TreeNode* root, int K, int ct){
    if(root ==NULL) return;
    if(ct ==K){
        cout<<root->val<<" ";
    }
    else{
        ct++;
        printNodesAt_K(root->left,K,ct);
        printNodesAt_K(root->right,K,ct);
    }   
}
 
int main(int argc, char const *argv[])
{
 TreeNode *root=new TreeNode(10);
 TreeNode *l1=new TreeNode(20);
 TreeNode *r1=new TreeNode(30);
 TreeNode *l2=new TreeNode(40);
 TreeNode *r2=new TreeNode(50);
 TreeNode *r3=new TreeNode(60);
 root->left=l1;
 root->right=r1;
 l1->left=l2;
 l1->right=r2;
 r1->right=r3;

 printNodesAt_K(root,1,0);


  return 0;
}