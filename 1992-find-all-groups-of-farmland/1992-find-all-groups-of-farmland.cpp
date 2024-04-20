class Solution {
public:
    void dfs ( vector<vector<int>>& land ,int i ,int j ,int & mxi,int & mxj)
    {
        if( i<0 || j<0 || i>=land.size() || j>=land[0].size() )
            return ;
        
        if( land[i][j]==1)
        {
            land[i][j]=2;
            
            mxi = max( i,mxi);
            mxj = max( j,mxj);
            
            dfs(land,i+1,j,mxi,mxj);
            dfs(land,i,j+1,mxi,mxj);
            dfs(land,i,j-1,mxi,mxj);
            dfs(land,i-1,j,mxi,mxj);
        }
        return;
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) 
    {
       vector<vector<int>> ans;
        
      for( int i =0;i<land.size();i++)
      {
          for( int j =0;j<land[0].size();j++)
          {
              if( land[i][j] == 1)
              {
                  
                    int mxi = i;
                    int mxj = j;
        
                    dfs(land,i,j,mxi,mxj);
                  
                  ans.push_back({i,j,mxi,mxj});
              }
          }
      }
        return ans;
    }
};