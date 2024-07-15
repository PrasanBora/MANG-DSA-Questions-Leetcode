class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) 
    {
         unordered_set<string>st;
         
        for( auto it : startWords)
        {
            sort(it.begin(),it.end());
            st.insert(it);   
        }
        
        int res = 0;
         for( auto str : targetWords)
         {
             sort( str.begin(),str.end());
             for( int i = 0;i<str.length();i++)
             {
                 string temp = str.substr(0,i) + str.substr(i+1);
                 
                 if( st.find(temp) != st.end() )
                 {
                     res++;
                     break;
                 }
             }
         }
        
        return res;
    }
};