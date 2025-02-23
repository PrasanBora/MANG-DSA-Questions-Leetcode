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
     TreeNode* solve( int start1 ,int end1 , int start2, vector<int>&preorder , vector<int>&postorder)
     {
        // start1 --> index current we start traversing in preorder will point to the left subtree
        // end1 --> index where we end the traversing 
        // start2 --> index we currently are in the post order array to defines the start of the index frm which we will compare the elemnt to our root to grt to know the number of elemnts in my left subtree

        if( start1 > end1)
         return NULL;

        if( start1 == end1)
         return new TreeNode(preorder[start1]);

        TreeNode* root = new TreeNode(preorder[start1]);
        int left = preorder[start1+1];
        int count = 1 ;
        while( postorder[start2 + count - 1] != left)
        {
            count++;
            // calculating the number of left elemnts in leftsubtree
        } 
        root->left = solve(start1+1,start1+count,start2,preorder,postorder);
        root->right = solve(start1+count+1,end1,start2+count,preorder,postorder);

        return root ;
     }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) 
    {
      return solve(0,preorder.size()-1,0,preorder,postorder);   
    }
};