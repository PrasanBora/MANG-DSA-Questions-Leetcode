class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) 
    {
       priority_queue<float,vector<float>,
           greater<float>>pq;

       for(int i=0;i<dist.size();i++)
       {
           pq.push((float)dist[i]/speed[i]);
       } 
       int ans=0;
       while(!pq.empty())
       {
           if(pq.top()<=ans)
            return ans;

           ans++;
           pq.pop();

       }
       return ans;
    }
};