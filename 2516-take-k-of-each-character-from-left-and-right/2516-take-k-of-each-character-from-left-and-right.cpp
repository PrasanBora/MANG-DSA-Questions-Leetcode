class Solution {
public:
    int takeCharacters(string s, int k) 
    {
      int count_a = 0, count_b = 0 ,count_c = 0;
        
        for( int i =0;i<s.length();i++)
        {
            if(s[i]=='a')
                count_a++;
            else if(s[i]=='b')
                count_b++;
            else 
                count_c++;
        }
        count_a-=k;
        count_b-=k;
        count_c-=k;
        
        if( count_a < 0 || count_b < 0 || count_c < 0)
            return -1;
        
        int i =0,j=0;
        
        int ca=0,cb=0,cc=0;
        int ans =-1;
        
        while(i < s.length())
        {
            if( s[i] == 'a')
                ca++;
            else if(s[i]== 'b')
                cb++;
            else cc++;
            
            while( ca>count_a || cb>count_b || cc>count_c )
            {
                if(s[j]=='a')
                    ca--;
                else if(s[j]=='b')
                    cb--;
                else
                    cc--;
                
                j++;
            }
            ans = max(ans,i-j+1);
            i++;
        }
        return s.length()-ans;
    }
};