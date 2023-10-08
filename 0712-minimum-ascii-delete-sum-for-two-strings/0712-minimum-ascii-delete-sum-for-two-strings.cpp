class Solution {
public:
    // int solve ( string &s1,string &s2,int i1,int i2,vector<vector<int>>&dp)
    // {
    //     if(i1==s1.length() &&i2==s2.length())
    //      return 0;

    //     if(dp[i1][i2]!=-1)
    //      return dp[i1][i2]; 

    //     if(i1==s1.length()&&i2<s2.length())
    //     {
    //       int ans=0;
    //       for(int it=i2;it<s2.length();it++)
    //        {
    //            ans+=s2[it];
    //        }
    //        return ans;
    //     } 

    //     if(i2==s2.length()&&i1<s1.length())
    //     {
    //       int ans=0;
    //       for(int it=i1;it<s1.length();it++)
    //        {
    //            ans+=s1[it];
    //        }
    //        return ans;
    //     }

    //     if(s1[i1]==s2[i2])
    //      return solve(s1,s2,i1+1,i2+1,dp);

    //     int cost1=s1[i1];
    //     int cost2=s2[i2]; 

    //     int c1 = cost1+solve(s1,s2,i1+1,i2,dp);
    //     int c2 = cost2+solve(s1,s2,i1,i2+1,dp);
    //     int c3 = cost1+cost2+solve(s1,s2,i1+1,i2+1,dp);

    //     return dp[i1][i2]=min({c1,c2,c3});
    // }
    
     // 

     int solvetb(string s1,string s2)
     {
         int n=s1.length();
         int m=s2.length();

         vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=n-1;i>=0;i--)
            dp[i][m]= s1[i] + dp[i+1][m];
        
        for(int i=m-1;i>=0;i--)
            dp[n][i]= s2[i] + dp[n][i+1];

        for( int i1 =n-1;i1>=0;i1--)
        {
            for( int i2=m-1;i2>=0;i2--)
            {
                if(s1[i1]==s2[i2])
                 dp[i1][i2] = dp[i1+1][i2+1];
                
                else 
               { int cost1=s1[i1];
                 int cost2=s2[i2]; 

                 dp[i1][i2]=min(cost1+dp[i1+1][i2],cost2+dp[i1][i2+1]);
               }
            }
        }    
         return dp[0][0];
     }
    int minimumDeleteSum(string s1, string s2) 
    {
        // vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        // return solve(s1,s2,0,0,dp);

        return solvetb(s1,s2);
    }
};