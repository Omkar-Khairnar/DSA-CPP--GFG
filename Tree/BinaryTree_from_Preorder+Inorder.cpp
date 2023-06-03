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
  int preindex=0;
  TreeNode* constructBT(vector<int> &preorder, vector<int> &inorder, int le,int re){
    if(le > re) return NULL;

    TreeNode *root=new TreeNode(preorder[preindex++]);
    int index;
    for (int i = 0; i < inorder.size(); i++)
    {
        if(inorder[i] == root->val){
         index=i;
            break;
        }
    }

    root->left=constructBT(preorder,inorder,le,index-1);
    root->right=constructBT(preorder,inorder,index+1,re);
    return  root; 
  } 
 
int main(int argc, char const *argv[])
{
 
  return 0;
}