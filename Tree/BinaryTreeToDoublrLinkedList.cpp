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
     TreeNode *prev=NULL;
  TreeNode* BinaryToDLL(TreeNode *root){
        if(root == NULL) return root;

          TreeNode* head=  BinaryToDLL(root->left);
          
          if(prev == NULL) head=root;
          else{
            root->left=prev;
            prev->right=root;
          }
            prev=root;

            BinaryToDLL(root->right);
    return head;
  } 
 
int main(int argc, char const *argv[])
{
 
  return 0;
}