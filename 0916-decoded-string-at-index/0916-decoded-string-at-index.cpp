class Solution {
public:
    string decodeAtIndex(string s, int k) 
    {
      long long size=0;
       for( int i=0;i<s.size();i++)
       {
           if(isalpha(s[i]))
            size+=1;
           else 
            size*=s[i]-'0'; 
       }   

       for(int i=s.size()-1;i>=0;i--)
       {
           k=k%size;

           if(s[i]>='a')
           {
               if(k==0)
                return (string)""+ s[i];
                else 
               size-=1;
           }
           else 
            size/=s[i]-'0';
       }
       return "";
    }
};