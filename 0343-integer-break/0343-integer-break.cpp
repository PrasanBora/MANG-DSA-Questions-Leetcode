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

    int solvetb(int n)
    {
        vector<int>dp(n+1,0);
         dp[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            for( int j=1;j<i;j++)
                dp[i]= max ( dp[i],max(j*(i-j),j*dp[i-j]));
        }
        return dp[n];

    }
    int integerBreak(int n) 
    {
        // vector<int>dp(n+1,-1);
        // return solve (n,dp);

        return solvetb(n);
    }
};