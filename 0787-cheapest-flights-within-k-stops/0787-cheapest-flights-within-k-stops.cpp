class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
      
        vector<int> dist( n, INT_MAX );
        dist[src] = 0;
        
        // Run only K+1 times since we want shortest distance in K hops
        
        for( int i =0;i<=k;i++)
        {
            vector<int>temp(dist);
            for( auto it:flights)
            {
                int from = it[0];
                int to = it[1];
                int fare = it[2];
                
                if( dist[from] != INT_MAX)
                {
                    temp[to] = min( temp[to], dist[from]+fare);
                }
            }
            dist = temp;
        }

      
        if( dist [dst] != INT_MAX )
          return dist[dst];
        else 
          return -1;
    }
};