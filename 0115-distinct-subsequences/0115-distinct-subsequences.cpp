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

    int solvemem( string s,string t,int is,int it,
      vector<vector<int>>&dp)
    {
        if(it==t.size())
         return 1;
        if(is>=s.size())
         return 0;

        if(dp[is][it]!=-1)
         return dp[is][it]; 

        if(s[is]==t[it])
         {
             return dp[is][it]=solvemem(s,t,is+1,it+1,dp)+solvemem(s,t,is+1,it,dp);
         } 
         else 
          return dp[is][it]=solvemem(s,t,is+1,it,dp);

    }

    int numDistinct(string s, string t) 
    {

        // return solve(s,t,0,0);
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,-1));
        return solvemem(s,t,0,0,dp);

    }
};