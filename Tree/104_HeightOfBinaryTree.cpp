#include <bits/stdc++.h>
 
using namespace std;
 struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int k){
        val=k;
        left=right=NULL;
    }
 };
  
   int maxDepth(TreeNode* root) {
      if(root == NULL){
        return 0;
      }
      else{
        return max(maxDepth(root->left),maxDepth(root->right))+1;
      }
    } 


int main(int argc, char const *argv[])
{
 
  return 0;
}