class Solution {
public:
    unordered_map<int,vector<int>>graph;

    int dfs( int node, vector<int>&time,vector<int>&memo)
    {
        if(memo[node]!=-1)
         return memo[node];

        if( graph[node].size()==0)
         return time[node];

        int ans=0;
        for( auto neighbor : graph[node])
         ans= max(ans,dfs(neighbor,time,memo));

        return memo[node]= time[node]+ans;  

    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) 
    {
        for( auto course : relations)
        {
            int x = course[0]-1;
            int y = course[1]-1;

            graph[x].push_back(y);
        }
        vector<int>memo(n,-1);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans= max(ans,dfs(i,time,memo));
        }
        return ans;
    }
};