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

    // unordered_map<int,int>freq;
    // void get_freq(TreeNode* root)
    // {
    //     if(!root)
    //      return;
    //     freq[root->val]++;
    //     get_freq(root->left);
    //     get_freq(root->right);
    // }

    // vector<int> findMode(TreeNode* root) 
    // {
    //     if(!root)
    //      return{};

    //     vector<int>res;
    //     get_freq(root);
        
    //     int max_freq=-1;
    //     for( auto it:freq)
    //     {
    //         if(it.second>max_freq)
    //         {
    //             max_freq=it.second;
    //             res.clear();
    //             res.push_back(it.first);
    //         }
    //         else if( it.second==max_freq)
    //           res.push_back(it.first);

    //     }
    //     return res;
    // }
        
        int currNum,maxStreak,currStreak;
        vector<int>res;

        void inorder(TreeNode* root)
        {
            if(!root)
             return ;

            inorder(root->left);

            int num = root->val;
            if(num==currNum)
             currStreak++;
            else 
              {
                  currStreak=1;
                  currNum=num;
              } 

            if(currStreak>maxStreak)
            {
                res={};
                maxStreak=currStreak;
            }  
            if( currStreak==maxStreak)
            {
                res.push_back(num);
            }

            inorder(root->right);
        }
        vector<int> findMode(TreeNode* root) 
        {
            if(!root)
             return {};
            inorder(root);
            return res; 
        }
};