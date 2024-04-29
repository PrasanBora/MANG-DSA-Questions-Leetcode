class Solution {
public:
    vector<int>dp;
    int solve( vector<int>&nums,int index)
    {
       if(index >= nums.size())
           return 0;
        
        int take=0 ,leave =0;
        
        if(dp[index]!=-1)
            return dp[index];
        
        take = nums[index] + solve(nums,index+2);
        leave = solve(nums,index+1);
        
        return dp[index] = max(take,leave);
    }
    
    int rob(vector<int>& nums) 
    {
        dp.resize(nums.size()+1,-1);
      return solve(nums,0);   
    }
};