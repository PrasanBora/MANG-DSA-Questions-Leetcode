class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int land =0 ,common=0;
        for( int i =0 ;i<grid.size();i++)
        {
            for( int j =0;j<grid[0].size();j++)
            {
              if( grid[i][j] == 1)
               {   
                  land ++;
                
                if( i >0 && grid[i-1][j] == 1)
                    common++;
                if( j >0 && grid[i][j-1] == 1)
                    common++;
              }
            }
        }
        return 4*land - ( 2* common);
    }
};