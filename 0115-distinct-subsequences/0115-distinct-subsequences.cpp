class Solution {
public:
    
    // int solve( string s,string t,int is,int it)
    // {
    //     if(it==t.size())
    //      return 1;
    //     if(is>=s.size())
    //      return 0;

    //     if(s[is]==t[it])
    //      {
    //          return solve(s,t,is+1,it+1)+solve(s,t,is+1,it);
    //      } 
    //      else 
    //       return solve(s,t,is+1,it);

    // }

    // int solvemem( string s,string t,int is,int it,
    //   vector<vector<int>>&dp)
    // {
    //     if(it==t.size())
    //      return 1;
    //     if(is>=s.size())
    //      return 0;

    //     if(dp[is][it]!=-1)
    //      return dp[is][it]; 

    //     if(s[is]==t[it])
    //      {
    //          return dp[is][it]=solvemem(s,t,is+1,it+1,dp)+solvemem(s,t,is+1,it,dp);
    //      } 
    //      else 
    //       return dp[is][it]=solvemem(s,t,is+1,it,dp);

    // }

    int numDistinct(string s, string t) 
    {

        // return solve(s,t,0,0);
        // vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,-1));
        // return solvemem(s,t,0,0,dp);
         

         // using 1 based indexing 
        // dp[i][j] is representing the no. of subseq of t[0-it] in s[0-is]
        vector<vector<long long>>dp(s.size()+1,vector<long long>(t.size()+1,0));

        for(int i=0;i<=s.size();i++)
         dp[i][0]=1;

        // an empty string is a subseq of each  
         const int MOD =1e9+7;
        for(int i=1;i<=s.size();i++)
        {
            for(int j=1;j<=t.size();j++)
            {
                if(s[i-1]==t[j-1])
                 dp[i][j]=dp[i-1][j-1]%MOD+dp[i-1][j]%MOD;
                else
                 dp[i][j]=dp[i-1][j]%MOD;   
            }
        }
        if (dp[s.size()][t.size()] >=INT_MAX)
         return -1;
        else 
         return dp[s.size()][t.size()];  
    }
};