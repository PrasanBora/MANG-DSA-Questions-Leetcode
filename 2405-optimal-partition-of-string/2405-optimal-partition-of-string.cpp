class Solution {
public:
    int partitionString(string s) 
    {
      int ans = 1; 
      
        unordered_map<char,int>freq;
        
        for( int i=0 ;i<s.length();i++ )
        {
            if(freq.find(s[i]) == freq.end())
            {
                freq[s[i]]++;
            }
            else 
            {
                ans++;
                freq.clear();
                freq[s[i]]++;
            }
        }
        return ans ;
    }
};