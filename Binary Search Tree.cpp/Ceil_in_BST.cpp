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
    
  TreeNode *ceilBST(TreeNode *root, int x){
    if(!root) return NULL;
    TreeNode *ans=NULL;
    TreeNode *curr=root;
    while(curr){
        if(curr->val ==x ){
            return curr;
        }
        else if(curr->val > x){
            ans=curr;
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
    }
   return ans;
  } 
 
int main(int argc, char const *argv[])
{
 
  return 0;
}