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
     
    TreeNode * findlca (TreeNode* node, int left, int right)
    {
        if(node == nullptr)
            return nullptr;
        
        if(node->val == left || node->val == right)
            return node ;
        
        TreeNode * leftlca = findlca(node->left,left,right);
        TreeNode * rightlca = findlca(node->right,left,right);
        
        if( leftlca && rightlca )
        {
            return node ;
        }
        else if ( leftlca && !rightlca )
            return leftlca;
        else 
            return rightlca;
        
    }
    
    bool traverse (TreeNode * root , int target , string & path )
    {
        if( !root )
            return 0;
        if( root -> val == target )
             return 1;
        
        path.push_back('L');
        
        if( traverse(root->left ,target,path))
            return true;
        
        path.pop_back();
        
        path.push_back('R');
        
        if( traverse(root->right ,target,path))
            return true;
        
        path.pop_back();
        
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) 
    {
       TreeNode* lca = findlca( root ,startValue, destValue );
       
        string lca_start ;
        string lca_end ;
        
         traverse ( lca , startValue ,lca_start);
         traverse ( lca , destValue ,lca_end);
        
        string res = "";
        
        for( auto it : lca_start )
            res+= 'U';
        
        res+=lca_end;
        
        return res;
        
    }
};