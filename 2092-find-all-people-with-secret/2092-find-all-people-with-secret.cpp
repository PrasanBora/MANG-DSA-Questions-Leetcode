class Solution {
public:
    
    void dfs(int person,int time,auto & adj, auto &time_known)
    {
          for( auto [t,p] : adj[person])
            {
                if(t >= time && time_known[p] > t)
                {
                    time_known[p] = t;
                    dfs(p,t,adj,time_known);
                }
            }
    }
    
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) 
    {
      map<int,vector<pair<int,int>>>adj;
      
        for( auto it: meetings)
        {
            int p1 = it[0];
            int p2 = it[1];
            int time = it[2];
            
            adj[p1].push_back({time,p2});
            adj[p2].push_back({time,p1});
        }
        
        vector<int>time_known(n,INT_MAX);
        time_known[0] =0;
        time_known[firstPerson] = 0;
        
//         queue<pair<int,int>>q;
        
//         q.push({0,0});
//         q.push({firstPerson,0});
        
//         while(!q.empty())
//         {
//             auto[ person,time ] = q.front();
//             q.pop();
            
//             for( auto [t,p] : adj[person])
//             {
//                 if(t >= time && time_known[p] > t)
//                 {
//                     time_known[p] = t;
//                     q.push({p,t});
//                 }
//             }
//         }
        
        dfs(0,0,adj,time_known);
        dfs(firstPerson,0,adj,time_known);
        
        vector<int>ans;
        for( int i =0;i<n;i++)
        {
            if(time_known[i]!=INT_MAX)
                ans.push_back(i);
        }
        return ans;
    }
};