class Solution {
public: 
    int n,m ;
//     int dp[210][210];
    
//     int solve( int i,int j, vector<vector<int>>& dungeon)
//     {
//         if( i >=n || j >=m)
//         {
//             return INT_MAX;
//         }
        
//         if( i == n-1 && j == m-1 )
//         {
//             if(dungeon[i][j] <=0 )
//             {
//                 return  dp[i][j] = abs(dungeon[i][j])+1;
//             }
//             else return  dp[i][j] = 1;
//         }
        
//         if(dp[i][j] != -1)
//             return dp[i][j] ;
        
//         int right = solve(i ,j+1,dungeon);
//         int down = solve(i+1,j,dungeon);
        
//         int ans = min(right,down) - dungeon[i][j];
        
//         if( ans <= 0)
//             return dp[i][j] = 1;
//         else 
//             return dp[i][j] = ans;
//     }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        n = dungeon.size();
        m = dungeon[0].size();
        // memset(dp, -1, sizeof(dp));
        
        // return solve(0,0,dungeon);
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));
        
        dp[n][m-1] =1;
        dp[n-1][m] =1;
        
        for(int i = n-1 ;i>=0;i--)
        {
            for( int j = m-1;j>=0;j--)
            {
                int need = min(dp[i+1][j],dp[i][j+1])  - dungeon[i][j];
                if(need <=0 )
                    dp[i][j] =1;
                else 
                    dp[i][j] = need;
            }
        }
        return dp[0][0];
    }
    
};