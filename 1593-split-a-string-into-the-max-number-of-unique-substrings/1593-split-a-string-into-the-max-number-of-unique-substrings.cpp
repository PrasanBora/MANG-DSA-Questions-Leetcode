class Solution {
public:
    
    int solve(string &s, int index,unordered_map<string,bool>&mp,string temp)
    {
       if( index >= s.length() )
           return 0;
        
        temp += s[index];
        
        int skip = 0,take = 0;
        
        if( mp.find(temp) == mp.end())
        {
            mp[temp] = true;
            take = 1+solve(s,index+1,mp,"");
            mp.erase(temp);
        }
        
        skip = 0+solve(s,index+1,mp,temp);
        
        return max(take,skip);
    }
    
    int maxUniqueSplit(string s) 
    {
      unordered_map<string,bool>mp;
      return solve(s,0,mp,"");
        
    }
};