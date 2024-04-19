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
    map<int,int>val_index;
    
    TreeNode* solve(vector<int>&preorder,int start,int end ,int & index)
    {
         if( start >end )
            return nullptr;
        
        int center = val_index[ preorder[index]];
        TreeNode* root = new TreeNode( preorder[index++] );
        
        root->left = solve(preorder ,start ,center-1, index);
        root->right = solve(preorder,center+1,end ,index );
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        for( int i = 0;i<inorder.size();i++)
        {
            val_index[inorder[i]] = i;
        }
        int index =0 ;
        return solve( preorder,0,inorder.size()-1,index);
    }
};