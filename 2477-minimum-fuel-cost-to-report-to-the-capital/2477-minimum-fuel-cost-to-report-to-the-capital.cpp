class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) 
    {
        vector<vector<int>>graph(roads.size()+1);
        
        for( auto it: roads)
        {
            int u = it[0];
            int v = it[1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        long long ans =0;
        
        dfs(graph,0,-1,ans,seats);
        
        return ans;
    }
    
    int dfs(vector<vector<int>>&graph ,int curr,int prev,long long &ans ,int seats)
    {
        int people = 1;
        
        for( auto next : graph[curr])
        {
            if( next == prev )
             continue;
            
            people += dfs(graph,next,curr,ans,seats);
        }
        
        if( curr > 0)
        {
            ans += (people + seats - 1) / seats ;
        }
        
        return people;
    }
};