class Solution {
public:
    string maximumOddBinaryNumber(string s) 
    {
      int one =0;
        for( int i=0;i<s.length();i++)
        {
            if(s[i]=='1')
                one++;
        }
        
        string ans ="";
        for( int i =0 ;i<s.length()-1;i++)
        {
            if(one > 1)
                {
                ans+='1';
                one--;
                }
            else 
                ans+='0';
        }
        ans+='1';
        return ans;
    }
};