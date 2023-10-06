class Solution {
public:
    // int solve(int n,vector<int>&dp)
    // {
    //     if(n<=1)
    //      return 1;
    //     if(dp[n]!=-1)
    //      return dp[n];

    //     int mx=1;
    //     for( int i=1;i<n;i++)
    //     {
    //       mx= max(mx,max(i*(n-i),i*solve(n-i,dp)));
    //     } 
    //     return dp[n]=mx;
    // }

    // int solvetb(int n)
    // {
    //     vector<int>dp(n+1,0);
    //      dp[1]=1;
        
    //     for(int i=2;i<=n;i++)
    //     {
    //         for( int j=1;j<i;j++)
    //             dp[i]= max ( dp[i],max(j*(i-j),j*dp[i-j]));
    //     }
    //     return dp[n];

    // }

    int solvemath(int n)
    {
        if(n<=3)
         return n-1;

        int count_3 = n/3;
        int rem = n%3;

        if( rem == 0)
         return pow(3,count_3);

        if( rem == 1)
         return pow(3,count_3-1)*4;

        if( rem == 2)
         return pow(3,count_3)*2;  

        return INT_MAX; 

    }
    int integerBreak(int n) 
    {
        // vector<int>dp(n+1,-1);
        // return solve (n,dp);

        // return solvetb(n);

        return solvemath(n);
    }
};