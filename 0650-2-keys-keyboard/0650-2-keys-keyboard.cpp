class Solution {
public:
    int N ;
    int minSteps(int n) 
    { 
        if( n == 1)
            return 0;
        N = n;
        
        // return 1+solve(1,1);
        
        // first param. = currlen on screen 
        // second param. = curr copied length
        
        vector<vector<int>>memo(n+1,vector<int>(n+1,0));
        
        return 1 + solvemem(1,1,memo);
    }
    
//     int solve( int curr ,int copied)
//     {
//         if( curr == N )
//             return 0;
        
//         if( curr > N )
//             return 100000;
        
//         int op1 = 2 + solve( 2*curr , curr );
//         // copy the present and paste it whole
        
//         int op2 = 1 + solve(curr+copied ,copied);
//         // paste the copied
        
//         return min(op1,op2);
        
//     }
    
     int solvemem( int curr ,int copied,vector<vector<int>>&memo)
    {
        if( curr == N )
            return 0;
         
          if( curr > N )
            return 100000;
         
         if(memo[curr][copied]!=0)
             return memo[curr][copied];
             
       
        
        int op1 = 2 + solvemem( 2*curr , curr ,memo );
        // copy the present and paste it whole
        
        int op2 = 1 + solvemem( curr+copied ,copied,memo );
        // paste the copied
        
        return memo[curr][copied] = min(op1,op2);
        
    }
};