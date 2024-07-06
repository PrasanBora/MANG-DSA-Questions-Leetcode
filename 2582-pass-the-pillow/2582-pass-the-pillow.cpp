class Solution {
public:
    int passThePillow(int n, int time) 
    {
        int x = time/ (n-1);
        int y = time% (n-1);
        
        if( x%2 == 0)
            return y+1 ;
        else 
            return n-y ;
    }
};