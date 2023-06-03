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

  map<int,int> mp;
  void BottomView(TreeNode *root, int col){
    if(!root) return;
        mp[col]=root->val;
    BottomView(root->left,col-1);
    BottomView(root->right,col+1);
  }
  void showBottomView(){
    for(auto it=mp.begin(); it !=mp.end(); it++){
        cout<<it->second<<endl;
    }
  }
 
int main(int argc, char const *argv[])
{
    TreeNode *root=new TreeNode(10);
    TreeNode *rt=new TreeNode(30);
    root->right=rt;
    rt->left=new TreeNode(40);
    rt->left->right=new TreeNode(80);
    rt->right=new TreeNode(50);
    rt->right->left=new TreeNode(60);
    root->left= new TreeNode(20);

    BottomView(root,0);
    showBottomView();

  return 0;
}