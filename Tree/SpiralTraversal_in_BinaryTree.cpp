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

  //This is one way  of spiral Traversing.
 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode *>q;
        q.push(root);
        int sz=0;
        TreeNode* curr=NULL;
        int ct=0;
        while (!q.empty())
        {
            sz=q.size();
            vector<int> row;
            while (sz--)
            {
               curr=q.front();
               q.pop();
               row.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
               
            }
            if(ct % 2!=0) reverse(row.begin(), row.end());
            ans.push_back(row);
            ct++;    
        }
        

    return ans; 
    } 


    //We can find spiral traversal by using Two stacks as explaned in video.
 
int main(int argc, char const *argv[])
{
 
  return 0;
}