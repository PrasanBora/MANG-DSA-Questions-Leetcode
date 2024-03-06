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
    string ans = "";
    void solve( TreeNode* root ,string temp )
    {
       if( !root)
           return ;
        
        temp = char(root->val + 'a') + temp;
        
        if( !root->left && !root->right )
        {
            if(ans.length() == 0)
                 ans = temp ;
            else 
                ans = min(ans,temp);
        }
        
        solve( root->left,temp);
        solve( root->right,temp);
    }
    
    string smallestFromLeaf(TreeNode* root) 
    {
      string temp ="";
        solve(root,temp);
        
        return ans;
    }
};