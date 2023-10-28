class Solution {
public:
 int MOD=1e9+7;
    // int solve(int last, int n)
    // {
    //     if(n<=0)
    //      return 1;
    //      int res=0;
        
    //     if( last ==1)
    //      res+= solve(2,n-1);
    //     else if(last==2)
    //      res+= solve(1,n-1)+solve(3,n-1);
    //     else if(last==3)
    //      res+= solve(1,n-1)+solve(2,n-1)+solve(4,n-1)+solve(5,n-1);
    //     else if(last==4)
    //      res+= solve(3,n-1)+solve(5,n-1);
    //     else if(last==5)
    //      res+=solve(1,n-1);

    //     return res;   

    // }
     long long solvemem(int last, int n,vector<vector<long long>>&dp)
    {
        if(n<=0)
         return 1;

        if(dp[last][n]!=-1)
         return dp[last][n]%MOD; 
         
        long long res=0;
        
        if( last ==1)
         res= (solvemem(2,n-1,dp))%MOD;

        else if(last==2)
         res= (solvemem(1,n-1,dp)+solvemem(3,n-1,dp))%MOD;

        else if(last==3)
         res= (solvemem(1,n-1,dp)+solvemem(2,n-1,dp)+solvemem(4,n-1,dp)+solvemem(5,n-1,dp))%MOD;

        else if(last==4)
         res= (solvemem(3,n-1,dp)+solvemem(5,n-1,dp))%MOD;

        else if(last==5)
         res=(solvemem(1,n-1,dp))%MOD;

        return dp[last][n]=res%MOD;   

    }

    int countVowelPermutation(int n) 
    {
      long long ans=0;
      vector<vector<long long>>dp(6,vector<long long>(n+1,-1));
      for( int i=1;i<=5;i++ )
      {
        //   ans+=solve(i,n-1);
        ans+=solvemem(i,n-1,dp)%MOD;
      }   
      return ans%MOD;
    }
};