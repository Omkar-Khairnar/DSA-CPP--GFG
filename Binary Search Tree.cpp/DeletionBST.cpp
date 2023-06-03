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

   TreeNode* inorderSuceeder(TreeNode *root){
        TreeNode *curr=root->right;
        while(curr && curr->left !=NULL){
            curr=curr->left;
        }
        return curr;
    }
   
    TreeNode* deleteNode(TreeNode* root, int val){
       if(!root) return root;

       if(val > root->val){
        root->right= deleteNode(root->right, val);
        return root;
       }
       else if(val < root->val){
        root->left= deleteNode(root->left, val);
        return root;
       }
       else{
            if(!root->left){
                TreeNode* temp= root->right;
                delete root;
                return temp;
            }
            else if(!root->right){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            else{
                TreeNode *succ=inorderSuceeder(root);
                root->val=succ->val;
                root->right=deleteNode(root->right, succ->val);
            }
       }
       return root;
      
    }
int main(int argc, char const *argv[])
{
 
  return 0;
}