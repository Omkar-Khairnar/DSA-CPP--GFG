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
  void TopView(TreeNode *root, int col){
    if(!root) return;
    if(mp.count(col)==0){
        mp[col]=root->val;
    }
    TopView(root->left,col-1);
    TopView(root->right,col+1);
  }
  void showVerticalView(){
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
    rt->right=new TreeNode(50);
    root->left= new TreeNode(20);

    TopView(root,0);
    showVerticalView();

  return 0;
}