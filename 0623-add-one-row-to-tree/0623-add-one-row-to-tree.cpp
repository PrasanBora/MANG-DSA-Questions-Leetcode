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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        if(!root)
            return NULL;
        if( depth == 1)
        {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size();
            depth--;
           
            while(sz--)
            {
                 TreeNode* curr = q.front();
                  q.pop();
                
                if( depth !=1 )
               {     
                if( curr->left )
                    q.push(curr->left);
                if( curr->right )
                    q.push(curr->right);
                }
                
                else 
                {
                    TreeNode * node_left = new TreeNode(val,curr->left,NULL);
                    TreeNode * node_right = new TreeNode(val,NULL,curr->right);
                    
                    curr->left = node_left;
                    curr->right = node_right;
                }
            }   
        }
        return root;
    }
};