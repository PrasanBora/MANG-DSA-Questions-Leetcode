class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int>freq (256,0);
        int ans=0, i=0,j=0;
        
       while(i<s.length())
        {
           freq[s[i]]++;
            while(freq[s[i]]>1)
            {
                    freq[s[j]]--;
                   j++;
            }
         
            ans=max(ans,i-j+1);
            i++;
        }
        return ans;
    }
};