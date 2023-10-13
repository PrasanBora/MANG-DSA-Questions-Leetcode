class Solution {
public:
    // int solve( vector<int>&cost,int n)
    // {
    //     if(n==0)
    //      return cost[0];
    //     if(n==1)
    //      return cost[1];

    //     return cost[n]+min(solve(cost,n-1),solve(cost,n-2));

    // }

    //  int solve( vector<int>&cost,int n,vector<int>&dp)
    // {
    //     if(n==0)
    //      return cost[0];
    //     if(n==1)
    //      return cost[1];

    //     if(dp[n]!=-1)
    //      return dp[n]; 

    //     return dp[n]=cost[n]+min(solve(cost,n-1,dp),solve(cost,n-2,dp));

    // }

    int solve( vector<int>&cost)
    {
        int n=cost.size();
        vector<int>dp(cost.size()+1,0);
         dp[0]= cost[0];
         dp[1]= cost[1];

        for(int i=2;i<cost.size();i++)
        {
          dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        } 

        return min(dp[n-1],dp[n-2]);

    }

    int minCostClimbingStairs(vector<int>& cost) 
    {
        // return min (solve(cost,cost.size()-1) ,
        //             solve(cost,cost.size()-2));

        // vector<int>dp(cost.size()+1,-1);
        // return min (solve(cost,cost.size()-1,dp) ,
        //             solve(cost,cost.size()-2,dp));

        return solve(cost);

    }
};