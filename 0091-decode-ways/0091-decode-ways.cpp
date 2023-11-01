class Solution {
public:
    // int solve( int index,string s)
    // {
    //   if( index==s.size())
    //    return 1;
      
    //   int one =0;
    //    if(s[index]!='0')
    //      one = solve( index+1,s);

    //   int two =0;
    //    if( index+1<s.size() &&
    //        (s[index]=='1'||s[index]=='2') 
    //        && s[index+1]<='6')
    //        {
    //           two = solve(index+2,s);
    //        }
    
    //  return one+two;

    // }

    // int solvemem( int index,string s,vector<int>&dp)
    // {
    //   if( index==s.size())
    //    return 1;

    //   if(dp[index]!=-1)
    //    return dp[index]; 
      
    //   int one =0;
    //    if(s[index]!='0')
    //      one = solvemem( index+1,s,dp);

    //   int two =0;
    //    if( s[index]!='0' && index +1<s.size())
    //     {
    //         int temp = stoi(s.substr(index,2));
    //         if( temp<=26 && temp>0)
    //         two = solvemem(index+2,s,dp);
    //     }
    
    //  return dp[index] = one+two;

    // }

    // int numDecodings(string s) 
    // {
    //     vector<int>dp(s.length()+1,-1);
    //     // return solve(0,s);
    //     return solvemem(0,s,dp);
    // }

    int numDecodings(string s) 
    {
        vector<int>dp(s.length()+1);
         dp[0]=1;
        if(s[0]=='0')
         dp[1]=0;
        else 
         dp[1]=1;

        for(int i=2;i<=s.size();i++)
        {
            int one,two;
            if(s[i-1]=='0')
             one=0;
            else 
             one =dp[i-1]; 

            if(stoi(s.substr(i-2,2))<=26 &&  stoi(s.substr(i-2,2))>0 && s[i-2]!='0')
             two =dp[i-2];
            else 
              two=0;

              dp[i] = one +two; 
        } 
        return dp[s.size()];
    }
};