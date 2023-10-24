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
    vector<int>ans;
    void dfs(TreeNode*node,int depth)
    {
        if( node==NULL)
         return ;

        if( depth==ans.size())
         ans.push_back(node->val);

        else 
         ans[depth] =max( ans[depth],node->val);

         dfs(node->left,depth+1);
         dfs(node->right,depth+1);  
    }
    vector<int> largestValues(TreeNode* root) 
    {
        // if(root==NULL)
        //  return vector<int>{};

        // vector<int> ans;
        // queue<TreeNode*>q;
        // q.push(root);

        // while(!q.empty())
        // {
        //     int sz= q.size();
        //     int cmax =INT_MIN;

        //     for(int i=0;i<sz;i++)
        //     {
        //         TreeNode* node = q.front();
        //         q.pop();

        //         cmax=max(cmax,node->val);

        //         if(node->left)
        //          q.push(node->left);
        //         if(node->right)
        //          q.push(node->right); 
        //     }
        //     ans.push_back(cmax);
        // }
        // return ans;

         dfs(root,0);
         return ans;
    }
};