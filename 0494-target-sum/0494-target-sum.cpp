class Solution {
public:
    // int count =0;
    int findTargetSumWays(vector<int>& nums, int target) 
    {
          // solve( nums ,target , 0 ,0);
        
          vector<unordered_map<int,int>>dp(nums.size()+1);
        
            return solve( nums,target,dp,0,0);
          // return count;
    }
    
     int solve( vector<int>&nums ,int target,vector<unordered_map<int,int>>&dp, int index,int sum)
     {
         
        
         
         if( index>=nums.size())
         {
             if( target == sum )
                 return  1;
             else 
                 return  0;
         }
         
          if( dp[index].find(sum) != dp[index].end())
         {
             return dp[index][sum];
         }
         
         dp[index][sum] = solve(nums,target,dp,index+1,sum+nums[index]) + 
                          solve(nums,target,dp,index+1,sum-nums[index]) ;
         
         
         return dp[index][sum];
     }
    
//     void solve( vector<int>&nums ,int target, int index,int sum)
//     {
//         if( index>=nums.size())
//         {
//             if( sum == target )
//                 count++;
//             return;
//         }
//         else 
//             solve( nums,target,index+1,sum+nums[index]);
//             solve( nums,target,index+1,sum-nums[index]);
//     }
    
};