class Solution {
public:
    int n,m,K,mod = 1e9 + 7 ;
    vector<vector<vector<int>>>dp;
    
    int solve( int i,int j, vector<vector<int>>& grid,int sum)
    {
        if( i >=n || j >=m)
        {
            return 0;
        }
        
        if( i == n-1 && j == m-1 )
        {
            if((sum + grid[i][j]) % K == 0)
              return  1;
            else 
              return  0;
        } 
        
        if(dp[i][j][sum] != -1)
            return dp[i][j][sum] ;
        
        int right = solve(i ,j+1,grid, (sum + grid[i][j])%K );
        int down = solve(i+1,j,grid ,(sum + grid[i][j])%K );
        
        
        return dp[i][j][sum] = (right+down)%mod;
        
       
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) 
    {
        n = grid.size();
        m = grid[0].size();
        K = k;
        
       
       dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));

        return solve(0,0,grid,0);
    }
};