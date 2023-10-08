class Solution {
public:
    int solve( string word1,string word2,int i1,int i2 ,vector<vector<int>>&dp)
    {
       if(i1==word1.length() && i2==word2.length())
        return 0;

       if(dp[i1][i2]!=-1)
        return dp[i1][i2]; 

       if( i1==word1.length() || i2==word2.length())
        return dp[i1][i2]=max(word1.length()-i1,word2.length()-i2);

       if( word1[i1]==word2[i2])
        return dp[i1][i2]=solve(word1,word2,i1+1,i2+1,dp);
       else 
        return dp[i1][i2]=min(1+ solve(word1,word2,i1+1,i2,dp),1+solve(word1,word2,i1,i2+1,dp)); 

    }

    int solvetb(string word1,string word2)
    {
      int n=word1.size();
      int m=word2.size();
      vector<vector<int>>dp(n+1,vector<int>(m+1,0));

      for(int i=0;i<n;i++)
       dp[i][m]=n-i;
      
      for(int i=0;i<m;i++)
       dp[n][i]=m-i;
      
      for(int i1=n-1;i1>=0;i1--)
      {
          for( int i2=m-1;i2>=0;i2--)
          {
             if( word1[i1]==word2[i2])
               dp[i1][i2]=dp[i1+1][i2+1];
             else 
              dp[i1][i2]=min(1+ dp[i1+1][i2],1+dp[i1][i2+1]);
          }
      }
       return dp[0][0];
    }

    int minDistance(string word1, string word2) 
    {
        // vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        // return solve(word1,word2,0,0,dp);

        return solvetb(word1,word2);
    }
};