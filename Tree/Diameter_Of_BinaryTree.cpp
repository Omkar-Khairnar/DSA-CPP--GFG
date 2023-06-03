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


 //This is One Solution with Complexity O(n^2)
//  int mx=0;
//  int getHeight(TreeNode *root){
//     if(root == NULL) return 0;

//     return 1+max(getHeight(root->left) , getHeight(root->right));
//  }
//  void calculateDiameter(TreeNode *root){
//     if(root == NULL) return;
//    int d=1+getHeight(root->left)+getHeight(root->right);
//    mx=max(mx,d);
//    calculateDiameter(root->left);
//    calculateDiameter(root->right);
//  }
//  int diameterOfBinaryTree(TreeNode* root) {
//         if(root == NULL) return 0;
//         calculateDiameter(root);
//         return mx-1;
//     }


//Efficient Solution by modifying Height function Time Complexity:O(n)
int mx=0;
int getHeight(TreeNode *root){
    if(root == NULL) return 0;
    int lh=getHeight(root->left);
    int rh=getHeight(root->right);

    int d=1+lh+rh;
    mx=max(mx,d);

    return 1+max(lh,rh);

}
 int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        getHeight(root);
        return mx-1;
    }
 
int main(int argc, char const *argv[])
{
 
  return 0;
}