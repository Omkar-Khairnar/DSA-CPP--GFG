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

  map<int, int> mp;
  void verticalTraverseSum(TreeNode*root, int row, int col){
    if(!root) return;
    mp[col]+=root->val;
    verticalTraverseSum(root->left, row+1, col-1);
    verticalTraverseSum(root->right, row+1, col+1);
  }
  void showVerticalSum(){
    for(auto it=mp.begin(); it !=mp.end(); it++){
        cout<<"Column :"<<it->first<<" Sum :"<<it->second<<endl;
    }
  }
 
int main(int argc, char const *argv[])
{
    TreeNode *root=new TreeNode(10);
    TreeNode *rt=new TreeNode(30);
    root->right=rt;
    rt->left=new TreeNode(40);
    rt->right=new TreeNode(50);
    root->left= new TreeNode(20);

    verticalTraverseSum(root,0,0);
    showVerticalSum();
    
 
  return 0;
}