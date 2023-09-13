class Solution {
public:
    string convert(string s, int n) 
    {
        if(n==1) return s;
        vector<string> row(n);
        int j=0,d=1;
        for( int i=0;i<s.size();i++)
        {
            row[j] += s[i];
            if( j==n-1)
             d=-1;
            if( j==0)
             d=1;
            j+=d;  
        }
        s="";
        for( int i=0;i<row.size();i++ )
        {
            s+=row[i];
        }
        return s;
    }
};