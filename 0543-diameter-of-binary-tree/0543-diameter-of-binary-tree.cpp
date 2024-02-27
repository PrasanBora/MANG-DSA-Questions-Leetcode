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
class Solution {
public:
 int mx=0;
    int diameter(TreeNode* root) 
    {
        if( !root)
            return 0;
        int l =diameter(root->left);
        int r=diameter(root->right);
        mx= max(mx,l+r);
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode * root)
    {
        if(!root)
            return 0;
        diameter(root);
        return mx;
    }
};