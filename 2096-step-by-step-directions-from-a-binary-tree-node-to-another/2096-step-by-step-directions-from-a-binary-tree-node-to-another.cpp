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
     TreeNode * find_lca ( TreeNode*root, int left ,int right)
     {
         if( !root )
             return NULL;
         
         if( root->val == left || root->val == right )
           return root;
         
         TreeNode * l = find_lca(root->left,left,right);
         TreeNode * r = find_lca(root->right,left,right);
         
         if( l && r)
             return root;
         
         else if( l && !r)
             return l;
         else 
             return r;
     }
    
    bool traverse(TreeNode * root ,int dest ,string &path)
    {
        if( root == NULL)
            return false ;
        
        if(root->val == dest)
            return true ;
        
        path.push_back('L');
        if (traverse(root->left,dest,path))
             return true;
        path.pop_back();
        
        path.push_back('R');
        if(traverse(root->right,dest,path))
            return true;
        path.pop_back();
        
        return false;
        
    }
    
    
    string getDirections(TreeNode* root, int startValue, int destValue) 
    {
      TreeNode * lca = find_lca(root,startValue,destValue);
      // cout<<lca->val;
        string lca_start = "";
        string lca_dest  =  "";
        
        traverse(lca,startValue,lca_start);
        traverse(lca,destValue,lca_dest);
        
        for( auto &ch : lca_start)
            ch ='U';
        
        return lca_start + lca_dest ;
    }
};