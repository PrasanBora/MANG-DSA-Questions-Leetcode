class Solution {
public:
    int N ;
    int minSteps(int n) 
    { 
        if( n == 1)
            return 0;
        N = n;
        
        return 1+solve(1,1);
        // first param. = currlen on screen 
        // second param. = curr copied length
    }
    
    int solve( int curr ,int copied)
    {
        if( curr == N )
            return 0;
        
        if( curr > N )
            return 100000;
        
        int op1 = 2 + solve( 2*curr , curr );
        // copy the present and paste it whole
        
        int op2 = 1 + solve(curr+copied ,copied);
        // paste the copied
        
        return min(op1,op2);
        
    }
};