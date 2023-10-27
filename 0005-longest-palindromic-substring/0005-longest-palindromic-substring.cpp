class Solution {
public:
    // bool solve(int i,int j, string s, int &start ,int &maxl)
    // {
    //     if (i > j) return true;
    //     bool ans;
    //     if (s[i]==s[j])
    //     {
    //         ans=solve(i+1,j-1,s,start,maxl);
    //     }
    //     else ans= false;
    //     if(ans)
    //     {
    //         if (maxl < j - i + 1)
    //             {
    //                 maxl = j - i + 1;
    //                 start = i;
    //             }
    //     }
    //     return ans;
      
    // }

    //  int solvemem(int i,int j, string &s, int &start ,int &maxl,
    //  vector<vector<int>>&dp)
    // {
    //     if (i > j) return true;
        
    //     if(dp[i][j]!=-1)
    //      return dp[i][j] ;

    //     if (s[i]==s[j])
    //     {
    //         dp[i][j]=solvemem(i+1,j-1,s,start,maxl,dp);
    //     }
    //     else dp[i][j]= 0;
    //     if(dp[i][j])
    //     {
    //         if (maxl < j - i + 1)
    //             {
    //                 maxl = j - i + 1;
    //                 start = i;
    //             }
    //     }
    //     return dp[i][j];
    // }
    string longestPalindrome(string s) 
    {
      int start =0;
      int maxl =0;
      int n= s.length();
     
        // for(int i=0;i<n;i++) 
        // {
        //     for(int j=i;j<n;j++)
        //     {
        //         solve(i,j,s,start,maxl);
        //     }
        // } 
        
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // for(int i=0;i<n;i++) 
        // {
        //     for(int j=i;j<n;j++)
        //     {
        //         solvemem(i,j,s,start,maxl,dp);
        //     }
        // } 
        // return s.substr(start,maxl);

        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        string ans="";
        ans+=s[0];
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        

        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j<n;j++)
            {
              if(s[i]==s[j] )
              {
                  if(j-i==1 || dp[i+1][j-1])
                  {
                      dp[i][j]=1;

                      if(ans.size()< j-i+1)
                       ans= s.substr(i,j-i+1);
                  }
              }
            }
        }
        return ans;

    }
};

