class Solution {
public:
    int MOD =1e9+7; 
    int solve( int it,int m,int k,int cmx,vector<vector<vector<int>>>&dp)
    {
        if( it==0)
        {
            if(k==0)
             return 1;
            else return 0; 
        }
        if( dp[it][cmx][k] !=-1)
         return dp[it][cmx][k]; 
        long long ans=0;
        for(int i=1;i<=m;i++)
        {
            if( k>0&&i>cmx)
             ans+= solve(it-1,m,k-1,i,dp)%MOD;
            else if (i<=cmx)
             ans+= solve(it-1,m,k,cmx,dp)%MOD; 
        }
        return dp[it][cmx][k] = ans%MOD;
    }

    int numOfArrays(int n, int m, int k) 
    {
        vector<vector<vector<int>>>dp(n+2,vector<vector<int>>(m+2,vector<int>(k+2,-1)));
        return solve(n,m,k,0,dp)%MOD;
    }
};