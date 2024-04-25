class Solution {
public:
    
    bool dfs(unordered_map<int,vector<int>> &graph,int start,int end,vector<bool>&visited)
    {
        if( start == end )
            return true;
        
        visited[start] = true ;
        
        for( auto adj : graph[start])
        {
            if( visited[adj] == false )
            {
                if( dfs(graph,adj,end,visited))
                    return true;
            }
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        unordered_map<int,vector<int>> graph; 
        for(auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n,0);        
       
        return dfs(graph,start,end,visited);
    }
};