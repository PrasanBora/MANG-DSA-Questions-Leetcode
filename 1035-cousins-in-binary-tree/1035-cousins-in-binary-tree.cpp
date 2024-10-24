
class Solution {
public:
    int findDepthAndParent(TreeNode* node, TreeNode* parent, int depth, int val, TreeNode*& nodeParent)
    {
        if(node == NULL) 
          return -1000; 

        if (node->val == val)
        {
            nodeParent = parent; 
            return depth ; 
        }
     
       int left_find = findDepthAndParent(node->left, node, depth + 1, val, nodeParent);

       if( left_find != -1000 )
        return left_find ;
       
       else return 
        findDepthAndParent(node->right, node, depth + 1, val, nodeParent);
    }

    bool isCousins(TreeNode* root, int x, int y) 
    {
        if (root==NULL) 
         return false; 

        TreeNode* xParent = NULL; 
        TreeNode* yParent = NULL; 
        
        int xDepth = findDepthAndParent(root, NULL, 0, x, xParent);
        int yDepth = findDepthAndParent(root, NULL, 0, y, yParent);

        cout<< xParent <<" -- "<<yParent<<endl;

        return (xDepth == yDepth) && (xParent != yParent);
    }
    
};

