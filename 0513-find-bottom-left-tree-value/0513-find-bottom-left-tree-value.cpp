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
    int findBottomLeftValue(TreeNode* rt) 
    {
        queue<TreeNode*>q;
        int ans;
        q.push(rt);
        while(!q.empty())
        {
            ans =q.front()->val;
            int n=q.size();
            while(n--)
            {
               TreeNode* root = q.front();
                 q.pop();
               if(root->left)
                q.push(root->left);
               if(root->right)
                q.push(root->right);
              
            }
        }
        return ans;
    }
};