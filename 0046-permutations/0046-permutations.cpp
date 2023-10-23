class Solution {
public:
    vector<vector<int>>perm;
    
    void solve(vector<int>nums,int index)
    {
        if (index==nums.size()-1)
         {
             perm.push_back(nums);
             return;
         }
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[i],nums[index]);
            solve(nums,index+1);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        solve(nums,0);
        return perm;
    }
};