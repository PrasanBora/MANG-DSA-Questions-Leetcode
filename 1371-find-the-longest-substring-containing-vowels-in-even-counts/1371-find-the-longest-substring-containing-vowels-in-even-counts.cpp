class Solution {
public:
    int findTheLongestSubstring(string s) 
    {
        map<char,int> v;
        v['a']=0;
        v['e']=1;
        v['i']=2;
        v['o']=3;
        v['u']=4;
        
        map<int,int> f;
        
        int mask=0,ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(v.find(s[i])!=v.end())
                mask^=1<<v[s[i]];
            
            if( mask !=0 && f.find(mask)==f.end())
                f[mask]=i+1;
            
                ans=max(ans,i-f[mask]+1);
        }
        return ans;
    }
};