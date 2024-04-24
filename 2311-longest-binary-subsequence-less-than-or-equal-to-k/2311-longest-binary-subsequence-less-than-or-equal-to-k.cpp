class Solution {
public:
    int longestSubsequence(string s, int k) {
        
        int z=0;
        //count zero
        for(char c:s)
            if(c=='0')z++;

        int num=0,base=1,len=0;
		//take as many ones from right as possible until they do not make the num>k
        for(int i=s.size()-1;i>=0;i--)
        {    
            if(num+base>k)
                break;
            if(s[i]=='1')
                num+=base;
            else  
                z--; //already taken zeros should be redued from zeros count
            base*=2;
            len++;
        }
        
        return len+z;
    }
};