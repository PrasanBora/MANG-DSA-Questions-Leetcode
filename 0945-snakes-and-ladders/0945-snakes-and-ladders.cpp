class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) 
    {
       int n=board.size();
       int it=1;

       vector<pair<int,int>>cells(n*n+1);
       vector<int>col(n);
       //filling col with increasing values
       iota(col.begin(),col.end(),0);  
       // marking the r and c for a number in board
       // 1=(n-1,0)
       // n*n =(0,0)
       for(int row=n-1;row>=0;row--)
       {
           for(int c :col)
             cells[it++]={row,c};
           reverse(col.begin(),col.end());
       }

       vector<int>dist(n*n+1 ,-1);
       //min number of moves required to reach cell
       dist[1]=0;
       queue<int>q;

       q.push(1);

       while(!q.empty())
       {
           int curr =q.front();
           q.pop();
           for(int next =curr+1;next<=curr+6 && next<=n*n;next++)
           {
               pair<int,int>p=cells[next];
               int r=p.first;
               int c=p.second;

               int des ;
               if( board[r][c]!=-1)
                des=board[r][c];
               else des =next; 
               // snake case we have to put min 
                if(dist[des]==-1)
                {
                   dist[des]=dist[curr]+1; 
                  q.push(des);
                }
           }
       }
       return dist[n*n];
    }
};