class Solution {
public:
    
    unordered_map<int,bool>dp;
    
    bool solve( string s, int index, vector<string>&wordDict)
    {
        if( index >= s.length())
            return true;
        
        if(dp.find(index) != dp.end() )
            return dp[index];
        
        string temp="";
        
        for( int i=index;i<s.length();i++)
        {
            temp+=s[i];
            
            if( find(wordDict.begin(),wordDict.end(),temp)!= wordDict.end() && solve(s,i+1,wordDict) )
            {
                // cout<<temp<<endl;
                 return dp[index] = true;
            }
            
            
        }
        
        return dp[index] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        return solve( s,0,wordDict);
    }
};