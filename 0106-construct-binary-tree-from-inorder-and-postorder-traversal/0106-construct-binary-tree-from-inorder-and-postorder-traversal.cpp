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
int itr;
 map<int,int>valtoindex;

 TreeNode * maketree( vector<int>& postorder ,int start, int end )
 {
     if(start>end)
     return NULL;
     
     int temp = postorder[itr --];
     TreeNode * node = new TreeNode (temp) ;
    
     node ->right = maketree (postorder , valtoindex[temp]+1 ,end);
     node ->left  = maketree (postorder , start ,valtoindex[temp]-1);
    
     return node ;
 }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        for (int i =0 ;i<inorder.size();i++)
            valtoindex[inorder[i]] = i;

        itr=inorder.size()-1;
            return maketree ( postorder , 0 , postorder.size()-1) ;
    }
};