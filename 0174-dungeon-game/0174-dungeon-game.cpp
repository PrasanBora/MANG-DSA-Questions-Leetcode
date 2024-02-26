class Solution {
public: 
    int n,m ;
    int dp[210][210];
    
    int solve( int i,int j, vector<vector<int>>& dungeon)
    {
        if( i >=n || j >=m)
        {
            return INT_MAX;
        }
        
        if( i == n-1 && j == m-1 )
        {
            if(dungeon[i][j] <=0 )
            {
                return  dp[i][j] = abs(dungeon[i][j])+1;
            }
            else return  dp[i][j] = 1;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j] ;
        
        int right = solve(i ,j+1,dungeon);
        int down = solve(i+1,j,dungeon);
        
        int ans = min(right,down) - dungeon[i][j];
        
        if( ans <= 0)
            return dp[i][j] = 1;
        else 
            return dp[i][j] = ans;
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        n = dungeon.size();
        m = dungeon[0].size();
        memset(dp, -1, sizeof(dp));
        
        return solve(0,0,dungeon);
    }
};