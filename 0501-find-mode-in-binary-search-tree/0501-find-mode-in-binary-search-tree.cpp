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
    map<int,int>freq;
    void getfreq(TreeNode * root)
    {
        if(!root)
        return;
        freq[root->val]++;
        getfreq(root->left);
        getfreq(root->right);
    }
    vector<int> findMode(TreeNode* root)
    {
       if(!root)
       return {};
       vector<int> res; 
       getfreq(root); 
       int mxf =-1;
       for( auto e:freq)
       {
           if(e.second==mxf)
               res.push_back(e.first);
           else if(e.second>mxf)
           {
               mxf=e.second;
               res.clear();
               res.push_back(e.first);
           }
       }
       return res;
    }
};