class Solution 
{
public:
    int solve(string &s,int &k,int i ,int lastch ,vector<vector<int>>&dp)
    {
          if( i >= s.length())
              return 0;
        
        if(dp[i][lastch]!=-1)
            return dp[i][lastch];
        
        int leave =0,take =0;
        
        leave = solve( s,k,i+1,lastch,dp);
        
        if(lastch==0|| abs(lastch - s[i]) <= k)
         take = 1+solve(s,k,i+1,s[i],dp);
        
        return dp[i][lastch] = max(take ,leave) ;
    }
    
    int longestIdealString(string s, int k) 
    {
        
        vector<vector<int>>dp(s.size()+1,vector<int>(150,-1));
        return solve(s,k,0,0,dp);
    }
};