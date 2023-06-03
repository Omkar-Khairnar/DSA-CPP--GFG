#include <bits/stdc++.h>
 
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  //Iterative Approach
  TreeNode* insertBSt(TreeNode* root, int val){
    if(root== NULL){
        return new TreeNode(val);
    }
    TreeNode *curr=root;
    TreeNode* prev=NULL;
    
    while(curr!=NULL){
        if(val == curr->val) return root;
        else if(val > curr->val){
            prev=curr;
            curr=curr->right;
        }
        else{
            prev=curr;
            curr=curr->left;
        }
    }
    if(val > prev->val) prev->right=new TreeNode(val);
    else{
        prev->left=new TreeNode(val);
    }
    return root;
    
  }

  //Recursive Approach
  TreeNode* insertRecursiveBST(TreeNode *root, int val){
    if(root ==NULL){
        return new TreeNode(val);
    }
    if(val > root->val) {
       root->right= insertRecursiveBST(root->right, val);
       }  
    else root->left= insertRecursiveBST(root->left, val);
    return root;
  }
 
int main(int argc, char const *argv[])
{
 
  return 0;
}