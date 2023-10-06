class Solution {
public:
    int solve(int n,vector<int>&dp)
    {
        if(n<=1)
         return 1;
        if(dp[n]!=-1)
         return dp[n];

        int mx=1;
        for( int i=1;i<n;i++)
        {
          mx= max(mx,max(i*(n-i),i*solve(n-i,dp)));
        } 
        return dp[n]=mx;
    }
    int integerBreak(int n) 
    {
        vector<int>dp(n+1,-1);
        return solve (n,dp);
    }
};