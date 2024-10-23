
class Solution {
public:
    //  function to find the depth and parent of a given node value
    void findDepthAndParent(TreeNode* node, TreeNode* parent, int depth, int val, int& nodeDepth, TreeNode*& nodeParent) {
        if(node == NULL) return; // base case   
        // If the current node matches the value we're looking for
        if (node->val == val){// current node == x or current node == y 
            nodeDepth = depth; // Set the depth of the node
            nodeParent = parent; // Set the parent of the node
            return; // Return as we found the node
        }
        // recur for the left child
        findDepthAndParent(node->left, node, depth + 1, val, nodeDepth, nodeParent);
        // recur for the right child
        findDepthAndParent(node->right, node, depth + 1, val, nodeDepth, nodeParent);
    }

    // Main function to determine if two nodes are cousins
    bool isCousins(TreeNode* root, int x, int y) 
    {
        if (root==NULL) 
        return false; 

        int xDepth = -1;
        int yDepth = -1; // Initialize depths of x and y
        TreeNode* xParent = NULL; //  parent of x
        TreeNode* yParent = NULL; //  parent of y
        
        findDepthAndParent(root, NULL, 0, x, xDepth, xParent);
        findDepthAndParent(root, NULL, 0, y, yDepth, yParent);
       
        return (xDepth == yDepth) && (xParent != yParent);
    }
};