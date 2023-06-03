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
 
bool isChildrenSumPropert(TreeNode* root){
    if(root ==NULL || (!root->left && !root->right)) return true;
    int sum=0;
    if(root->left) sum+=root->left->val;
    if(root->right) sum+=root->right->val;

    return (sum == root->val) && isChildrenSumPropert(root->left) && isChildrenSumPropert(root->right);

} 
int main(int argc, char const *argv[])
{
 TreeNode* root=new TreeNode(8);
 TreeNode* l1=new TreeNode(3);
 TreeNode* l2=new TreeNode(3);
 TreeNode* r1=new TreeNode(5);
 TreeNode* r2=new TreeNode(1);
 TreeNode* r3=new TreeNode(5);
 root->left=l1;
 root->right=r1;
 l1->left=l2;
 l1->right=r2;
 r1->right=r3;
 cout<<isChildrenSumPropert(root)<<endl;
  return 0;
}