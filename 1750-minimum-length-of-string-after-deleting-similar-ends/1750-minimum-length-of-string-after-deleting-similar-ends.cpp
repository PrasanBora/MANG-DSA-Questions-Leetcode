class Solution {
public:
    int minimumLength(string s)
    {
        int end=s.length()-1;
        int start=0;
  
        while( start<end )
        {
              if(s[start]==s[end]  )
            {
                  while(s[end]==s[end-1]  && end-1>start )
                    end--; 
                  while(s[start]==s[start+1]  && start+1<end  )
                    start++; 
                 end--;start++;    
            }
          else break;
        }
        return end-start+1; 
    }
};