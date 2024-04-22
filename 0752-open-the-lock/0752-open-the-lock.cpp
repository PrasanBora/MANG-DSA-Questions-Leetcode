class Solution {
public:
    int openLock(vector<string>& deadends, string target) 
    {
        unordered_set<string> deadset(deadends.begin(),deadends.end());
        unordered_map<string,bool> visited;

        int result =0;
        if(deadset.find("0000") != deadset.end())
         return -1;

        queue<string> q;

        q.push("0000");
        visited["0000"]=1;

        while(!q.empty())
        {
           int sz= q.size();
           while(sz--)
           {
               string up ,down,curr = q.front();
               q.pop();

               if(curr==target)
                return result;

                for(int i=0;i<4;i++)
                {
                    down=up=curr;
                    up[i] = up[i] == '9' ? '0' :up[i] +1;
                    down[i] = down[i] =='0' ? '9': down[i]-1;

                    if(!visited[up] && deadset.find(up)==deadset.end())
                    {
                        q.push(up);
                        visited[up]=1;
                    }

                      if(!visited[down] && deadset.find(down)==deadset.end())
                    {
                        q.push(down);
                        visited[down]=1;
                    }
                }
           }
           result++;
        }
        return -1;
    }
};