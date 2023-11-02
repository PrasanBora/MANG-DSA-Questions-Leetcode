/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:
    int res;
    pair<int,int> solve(TreeNode*root)
    {
      if(!root)
       return {0,0};

      pair<int,int>left=solve(root->left);
      pair<int,int>right=solve(root->right);

      int sum = root->val+left.first+right.first;
      int count= 1+left.second+right.second;

      if(sum/count == root->val)
           res++;
      return {sum,count}; 
    }
    int averageOfSubtree(TreeNode* root) 
    {
        solve(root);
        return res;
    }
};