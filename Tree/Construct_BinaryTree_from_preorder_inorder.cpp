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

    int itr=0;
    TreeNode *helper(vector<int>& preorder, vector<int>& inorder, int start, int end){
        if(start > end || itr >=preorder.size()) return NULL;
        else if(start== end) {
            itr++;
            return new TreeNode(inorder[start]);
            }

        int val=preorder[itr];
        itr++;
        int index=-1;
        TreeNode* root=new TreeNode(val);
        for(int i=start; i<= end;i++){
            if(inorder[i]==val){
                index=i;
                break;
            }
        }

        root->left=helper(preorder, inorder, start, index-1);
        root->right=helper(preorder, inorder, index+1, end);

        return root;

    }

  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       return helper(preorder,inorder, 0, inorder.size()-1);
    }
 
int main(int argc, char const *argv[])
{
    
}