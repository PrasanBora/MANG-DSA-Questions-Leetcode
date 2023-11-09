class Solution {
public:
    int mod =1e9+7;
    int countHomogenous(string s) 
    {
        long long count=1;
        long long ans=1;
        for(int i=1;i<s.length();i++)
        {
          if(s[i]==s[i-1])
            count++;
          else
            count=1;
           ans= (ans+count)%mod;
        }
        return ans%mod;
    }
};