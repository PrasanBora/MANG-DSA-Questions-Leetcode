class Solution {
public:
    int solve( int it ,int remain ,vector<int>& cost, vector<int>& time ,vector<vector<int>>&dp)
    {
        if(remain<=0)
         return 0;

        if(it==cost.size())
         return 1e7;

        if(dp[it][remain]!=-1)
         return dp[it][remain];

        int paint = cost[it]+ solve(it+1,remain-1-time[it],cost,time,dp);
        int notpaint =  solve(it+1,remain,cost,time,dp);

        dp[it][remain] = min(paint,notpaint);

        return dp[it][remain];
    }

    int solvetb( vector<int>& cost, vector<int>& time )
    {
        int n=cost.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int i=1;i<=n;i++)
            dp[n][i]=1e9;
        for(int it=n-1;it>=0;it--)
        { 
          for(int remain=1;remain<=n;remain++ )
          {
            int paint = cost[it]+ dp[it+1][max(0,remain-1-time[it])];
            int notpaint =  dp[it+1][remain];

            dp[it][remain] = min(paint,notpaint);
          }
        }

        return dp[0][n];
    }

    int paintWalls(vector<int>& cost, vector<int>& time) 
    {
        // int n= cost.size();
    //   vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    //    return solve(0,n,cost,time,dp)   ;

         return solvetb(cost,time);
    }
};