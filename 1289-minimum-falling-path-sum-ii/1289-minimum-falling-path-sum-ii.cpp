class Solution {
public:
    
//     map<pair<int,int>,int>memo;
//     int solve(int row , int col,vector<vector<int>>& grid )
//     {
//         if( row == grid.size()-1)
//             return grid[row][col];
        
//          if (memo.find({row, col}) != memo.end()) {
//             return memo[{row, col}];
//         }
        
//         int res = INT_MAX;
        
//         for( int i =0;i<grid[0].size();i++)
//         {
//             if( i != col )
//             {
//                 res = min( res, solve(row+1,i,grid));
//             }
//         }
        
//         memo[{row, col}] = res + grid[row][col] ;
        
//         return memo[{row, col}];
//     }
//     int minFallingPathSum(vector<vector<int>>& grid) 
//     {
//         int row = grid.size();
//         int col = grid[0].size();
//         int ans = INT_MAX;
        
//         for(int i =0;i<col;i++)
//         {
//            ans = min( ans , solve(0,i,grid));    
//         }
//         return ans;
//     }

    int minFallingPathSum(vector<vector<int>>& grid)
    {
        vector<vector<int>> memo(grid.size(), vector<int>(grid.size(), INT_MAX));

        //  base case
        
        for (int col = 0; col < grid.size(); col++) {
            memo[grid.size() - 1][col] = grid[grid.size() - 1][col];
        }

        // Fill the recursive cases
        for (int row = grid.size() - 2; row >= 0; row--) 
        {
            for (int col = 0; col < grid.size(); col++) 
            {
                // Select minimum from valid cells of next row
                int nextMinimum = INT_MAX;
                for (int nextRowCol = 0; nextRowCol < grid.size(); nextRowCol++) 
                {
                    if (nextRowCol != col) 
                    {
                        nextMinimum = min(nextMinimum, memo[row + 1][nextRowCol]);
                    }
                }

                // Minimum cost from this cell
                memo[row][col] = grid[row][col] + nextMinimum;
            }
        }

        // Find the minimum from the first row
        int answer = INT_MAX;
        for (int col = 0; col < grid.size(); col++) {
            answer = min(answer, memo[0][col]);
        }

        // Return the answer
        return answer;
    }
        
};