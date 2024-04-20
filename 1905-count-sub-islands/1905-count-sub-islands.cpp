class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2 ,int i ,int j,int &res)
    {
        if( i<0 || j<0 || i>=grid2.size() ||j>=grid2[0].size())
            return ;
        
        if( grid1[i][j]==0 && grid2[i][j]==1)
            {
              res = false;
            }
        
        if( grid2[i][j] == 0)
            return ;
        
        grid2[i][j]=0;
        
        dfs( grid1,grid2,i+1,j,res);
        dfs( grid1,grid2,i-1,j,res);
        dfs( grid1,grid2,i,j-1,res);
        dfs( grid1,grid2,i,j+1,res);
        
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
      int ans =0 ;
        
        for( int i=0;i<grid1.size();i++)
        {
            for( int j=0;j<grid1[0].size();j++)
            {
                if( grid2[i][j] == 1)
                {
                    int res = true;
                    
                    dfs( grid1 ,grid2,i,j,res);
                     ans+=res;
                }
            }
        }
        return ans;
    }
};