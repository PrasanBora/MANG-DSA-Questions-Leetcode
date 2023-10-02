class Solution {
public:
    int value(string str)
    {
        int score=0;
        for(int i=0;i<str.length();i++)
        score+=str[i];

        return score;
    }
    int solve ( string s1, string s2)
    {
       int n =s1.length();
       int m =s2.length();

       vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       for(int i =n-1;i>=0;i--)
       {
           for(int j=m-1;j>=0;j--)
           {
               if(s1[i]==s2[j])
               {
                   dp[i][j]= s1[i]+dp[i+1][j+1];
               }
               else 
                dp[i][j] = max( dp[i+1][j],dp[i][j+1]);
           }
       }
       return dp[0][0];
    }
    int minimumDeleteSum(string s1, string s2) 
    {
       int value_s1 = value(s1);
       int value_s2 = value(s2);
       int value_lcs = solve(s1,s2);

        return value_s1+value_s2 - (2*value_lcs); 
    }
};