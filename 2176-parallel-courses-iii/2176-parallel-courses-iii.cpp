class Solution {
public:
    unordered_map<int,vector<int>>graph;

    // int dfs( int node, vector<int>&time,vector<int>&memo)
    // {
    //     if(memo[node]!=-1)
    //      return memo[node];

    //     if( graph[node].size()==0)
    //      return time[node];

    //     int ans=0;
    //     for( auto neighbor : graph[node])
    //      ans= max(ans,dfs(neighbor,time,memo));

    //     return memo[node]= time[node]+ans;  

    // }
    // int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) 
    // {
    //     for( auto course : relations)
    //     {
    //         int x = course[0]-1;
    //         int y = course[1]-1;

    //         graph[x].push_back(y);
    //     }

        // vector<int>memo(n,-1);
        // int ans=0;
        // for(int i=0;i<n;i++)
        // {
        //     ans= max(ans,dfs(i,time,memo));
        // }
        // return ans;
    // }

     int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) 
    {
        vector<int>indegree(n,0);
        for( auto course : relations)
        {
            int x = course[0]-1;
            int y = course[1]-1;

            graph[x].push_back(y);
            indegree[y]++;
        }
        queue<int>q;
        vector<int>maxTime (n,0);

        for(int node=0;node<n;node++)
        {
            if(indegree[node]==0)
            {
                q.push(node);
                maxTime[node]=time[node];
            }
        }

        while(!q.empty())
        {
            int node=q.front();
            q.pop();
              for (int neighbor: graph[node]) 
              {
                maxTime[neighbor] = max(maxTime[neighbor], maxTime[node] + time[neighbor]);
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) 
                {
                    q.push(neighbor);
                }
             }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans= max(ans,maxTime[i]);
        }
      return ans;

    }
};