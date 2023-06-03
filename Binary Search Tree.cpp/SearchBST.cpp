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
    //Recursive Approach 
  bool searchBST(TreeNode *root, int target){
    if(root== NULL) return false;
    else if(root->val==target) return true;
    else if(root->val > target) return searchBST(root->left, target);
    else return searchBST(root->right, target);
  } 

  //Iterative Approach
  bool searchBSTIterative(TreeNode *root, int target){
    if(root == NULL) return false;
    while(root !=NULL){
        if(root->val==target) return true;
        else if(root->val > target) root=root->left;
        else root=root->right;
    }
    return false;
  }
 
int main(int argc, char const *argv[])
{
 
  return 0;
}