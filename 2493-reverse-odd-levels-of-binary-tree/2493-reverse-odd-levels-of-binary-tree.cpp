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
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
         queue<TreeNode*>q;
         q.push(root);
         vector<int>arr;
         int lvl = 0;

         while(!q.empty())
         {
             int sz = q.size();
             vector<int>temp;

             for( int i =0;i<sz;i++)
             {
                TreeNode* node = q.front();
                q.pop();

                if( lvl % 2)
                 node->val = arr[sz-i-1];

                if(node->left)
                 {
                    q.push(node->left);
                    temp.push_back(node->left->val);
                 } 

                 if(node->right)
                 {
                    q.push(node->right);
                    temp.push_back(node->right->val);
                 } 
             }
             arr=temp;
             lvl++;
         }
         return root;
    }
};