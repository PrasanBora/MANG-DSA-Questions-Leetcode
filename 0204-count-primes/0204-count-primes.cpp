class Solution {
public:
    int countPrimes(int n) 
    {
        vector<bool>num(n+1,true);
        num[0] = num[1] = false;
        
        for( int i =2 ;i*i <=n;i++)
        {
            if( num[i] )
            {
                for( int j = 2 ;i*j <=n ;j++)
                    num[i*j] = false;
            }
        }
        int count=0;
        
        for( int k=0;k<n;k++)
            if(num[k])
                count++;
        
        return count;
    }
};