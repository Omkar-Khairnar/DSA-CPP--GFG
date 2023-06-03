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

   vector<int> levelOrder(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()){
            TreeNode *curr =q.front();
            ans.push_back(curr->val);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
            q.pop();
        }
        return ans;
    }
 
int main(int argc, char const *argv[])
{
 
  return 0;
}