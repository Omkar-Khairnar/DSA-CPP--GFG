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

  int itr=-1;
  TreeNode *helper(vector<int>& postorder, vector<int>& inorder, int start, int end){
        if(start > end || itr < 0 ) return NULL;
        else if(start== end) {
            itr--;
            return new TreeNode(inorder[start]);
            }

        int val=postorder[itr];
        itr--;
        int index=-1;
        TreeNode* root=new TreeNode(val);
        for(int i=start; i<= end;i++){
            if(inorder[i]==val){
                index=i;
                break;
            }
        }

        root->right=helper(postorder, inorder, index+1, end);
        root->left=helper(postorder, inorder, start, index-1);

        return root;

    }

   TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    itr=postorder.size()-1;
        return helper(postorder, inorder, 0, postorder.size()-1);
    } 
 
int main(int argc, char const *argv[])
{
 
  return 0;
}