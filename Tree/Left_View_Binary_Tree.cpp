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

int maxLevel=0;

void printLeftNodes(TreeNode *root, int level){
    if(root ==NULL) return;
    if(level > maxLevel){
        cout<<root->val<<" ";
        maxLevel=level;
    }
    if(root->left) printLeftNodes(root->left, level+1);
    if(root->right) printLeftNodes(root->right, level+1);
}
 
int main(int argc, char const *argv[])
{
 
  return 0;
}