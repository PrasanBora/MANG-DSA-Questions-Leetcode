class Solution {
public:
         vector<int>ans;
         set<int>vis;
   void dfs(unordered_map<int,vector<int>>&adj,int &root)
            {
               if(vis.find(root)!=vis.end())
                return ;

               ans.push_back(root);
               vis.insert(root);
               for(auto it:adj[root])
                dfs(adj,it); 
            }

    vector<int> restoreArray(vector<vector<int>>
             & adjacentPairs) 
    {
        unordered_map<int,vector<int>>adj;
        for(auto it :adjacentPairs)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int root;
        for(auto it:adj)
        {
           if(it.second.size()==1)
            {
                root=it.first;
                break;
            }
        }
        dfs(adj,root);
        return ans;
    }
};