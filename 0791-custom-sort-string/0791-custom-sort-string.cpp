class Solution {
public:
    string customSortString(string order, string s) 
    {
        map<char,int>mp;
        for( int i =0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        
        string ans ="";
        for( int i=0;i<order.length();i++)
        {
            while( mp[order[i]] > 0)
            {
                ans+=order[i];
                mp[order[i]]--;
            }
        }
        
        for( auto it : mp)
        {
            while( it.second > 0)
            {
                ans+=it.first;
                it.second--;
            }
        }
        return ans;
    }
};