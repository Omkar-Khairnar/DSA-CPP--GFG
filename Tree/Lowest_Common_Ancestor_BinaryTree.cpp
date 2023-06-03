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

  //Naive Solution
//  bool findpath(TreeNode* root, vector<TreeNode*>& arr, TreeNode* p){
//     if(root == NULL) return false;
     
//     arr.push_back(root);
//     if(root->val == p->val) return true;

//     if(findpath(root->left, arr, p) || findpath(root->right, arr, p)){
//         return true;
//     }

//     arr.pop_back();
//     return false;
//   }
// TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         vector<TreeNode*> path1;
//         vector<TreeNode*> path2;

//         findpath(root,path1,p);
//         findpath(root,path2,q);
//         int i=0;
//         for ( i=0; i < path1.size()-1 && i< path2.size()-1; i++)
//         {
//             if(path1[i+1] != path2[i+1]){
//                 return path1[i];
//             }   
//         }
//         cout<<i<<endl;
//         return path1[i];    
//     } 



    //Efficient Solution

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root ==p || root == q){
            return root;
        }

        TreeNode *lca1=lowestCommonAncestor(root->left,p,q);
        TreeNode *lca2=lowestCommonAncestor(root->right,p,q);

        if(lca1 !=NULL && lca2 !=NULL){
            return root;
        }
        else if(lca1 != NULL){
            return lca1;
        }
        else return lca2;

    }
 
int main(int argc, char const *argv[])
{
 
  return 0;
}