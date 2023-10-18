class Solution 
{
public:
    int MOD = 1e9+7 ;
    int n;

    int solve( int steps,int curr,vector<vector<int>>&dp)
    {
        if(steps==0)
         {
             if(curr==0)
              return 1;
             else 
              return 0; 
         }
         if(dp[steps][curr]!=-1)
          return dp[steps][curr];

        int ans = solve(steps-1,curr,dp)%MOD; 
        if(curr>0)
         ans = (ans +solve(steps-1,curr-1,dp))%MOD;
        if(curr < n-1)
         ans = (ans +solve(steps-1,curr+1,dp))%MOD;

        dp[steps][curr]=ans%MOD;

        return dp[steps][curr];   
    }

     int solvetb( int steps,int arrLen)
    {
        vector<vector<int>>dp(steps+1,vector<int>(arrLen+1,0));
        dp[0][0]=1;
        for( int st=1;st<=steps;st++)
        {
            for( int curr=arrLen-1;curr>=0;curr--)
            {
                
               dp[st][curr]=dp[st-1][curr]%MOD; 
              if(curr>0)
               dp[st][curr]+=dp[st-1][curr-1]%MOD;
               
               dp[st][curr]=dp[st][curr]%MOD;
              if(curr < arrLen-1)
                dp[st][curr]+=dp[st-1][curr+1]%MOD;

                dp[st][curr]=dp[st][curr]%MOD;
            }
        }
        
        return dp[steps][0];   
    }

    int numWays(int steps, int arrLen) 
    {
        arrLen =min(steps,arrLen);
        n=arrLen;
        // vector<vector<int>>dp(steps+1,vector<int>(steps+1,-1));
         return solvetb(steps,arrLen);
        // return solve( steps,0,dp);
    }
};