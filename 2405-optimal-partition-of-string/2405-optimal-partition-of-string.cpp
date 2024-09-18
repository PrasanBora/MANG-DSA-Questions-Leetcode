class Solution {
public:
//     int partitionString(string s) 
//     {
//       int ans = 1; 
      
//         unordered_map<char,int>freq;
        
//         for( int i=0 ;i<s.length();i++ )
//         {
//             if(freq.find(s[i]) == freq.end())
//             {
//                 freq[s[i]]++;
//             }
//             else 
//             {
//                 ans++;
//                 freq.clear();
//                 freq[s[i]]++;
//             }
//         }
//         return ans ;
//     }
    
    
    int partitionString(string s) 
    {
      int ans = 1; 
      
        vector<int>lastseen(26,-1);
        int start = 0;
        
        for( int i=0 ;i<s.length();i++ )
        {
            if(lastseen[s[i]-'a'] >= start)
            {
                ans++;
                start=i;
            }
            lastseen[s[i]-'a'] = i;
        }
        return ans ;
    }
    
};