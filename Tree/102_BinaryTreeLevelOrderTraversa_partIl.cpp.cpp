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
 
// vector<vector<int>> levelOrder(TreeNode* root) {
//           vector<vector<int>> ans;
//         if(root == NULL) return ans;
//         queue<TreeNode *> q;
//         q.push(root);
//         q.push(NULL);
//         vector<int> row;
//         while (q.size() >1)
//         {   
//             TreeNode *curr =q.front();
//             q.pop();

//             if(curr==NULL){
//                 ans.push_back(row);
//                 row.clear();
//                 q.push(NULL);
//                 continue;
//             }

//             row.push_back(curr->val);
//             if(curr->left) q.push(curr->left);
//             if(curr->right) q.push(curr->right);
//              if(q.size()==1){
//                 ans.push_back(row);
//                 row.clear();
//             }
//         }
//       return ans;  
// }


vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode *> q;
        q.push(root);
       
         vector<int> row;
        while (!q.empty())
        {  
            int sz=q.size();

            while(sz--){
                TreeNode *curr =q.front();
                q.pop();
                row.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
           ans.push_back(row);
           row.clear();
         
            
        }
      return ans;  
}

int main(int argc, char const *argv[])
{
 
  return 0;
}