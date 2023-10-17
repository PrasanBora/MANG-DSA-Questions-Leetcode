class Solution {
public:
    
    // bool binarytree( int root,vector<int>& leftchild, vector<int>& rightchild)
    // {
    //     // bfs
    //      vector<int>vis(leftchild.size(),0);
    //      queue<int>q;

    //      q.push(root);
    //      vis[root]=true;

    //      while(!q.empty())
    //      {
    //          int curr=q.front();
    //          q.pop();

    //          if(leftchild[curr]!=-1)
    //          {
    //              if(vis[leftchild[curr]])
    //               return false;

    //              q.push(leftchild[curr]);
    //              vis[leftchild[curr]]=true;

    //          }

    //          if(rightchild[curr]!=-1)
    //          {
    //              if(vis[rightchild[curr]])
    //               return false;

    //              q.push(rightchild[curr]);
    //              vis[rightchild[curr]]=true;

    //          }
    //      }
    //      for( auto it : vis )
    //      {
    //          if(!it)
    //           return false;
    //      }
    //      return true;
    // }
    
     bool binarytree( int curr,vector<int>& leftchild, vector<int>& rightchild,vector<bool>&vis )
    {
        
             if(leftchild[curr]!=-1)
             {
                 if(vis[leftchild[curr]])
                  return false;

                 vis[leftchild[curr]]=true;
                 if (!binarytree(leftchild[curr],leftchild,rightchild,vis)) 
                  return false;

             }

             if(rightchild[curr]!=-1)
             {
                 if(vis[rightchild[curr]])
                  return false;

                 vis[rightchild[curr]]=true;
                 if (!binarytree(rightchild[curr],leftchild,rightchild,vis)) 
                  return false;
             }
              return true;
         }
         
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftchild, vector<int>& rightchild) 
    {
        // cycle detection
        vector<bool>count(n,0);
        for( int i=0;i<n;i++)
        {
            if(leftchild[i]!=-1)
             {
               if(count[leftchild[i]])
                return false;
               count[leftchild[i]]=true; 
             }

            if(rightchild[i]!=-1)
             {
               if(count[rightchild[i]])
                return false;
               count[rightchild[i]]=true;
             } 
        }

        // single root 

        int root=-1;
        for(int i=0;i<n;i++)
        {
            if(!count[i])
             {
                 if(root==-1)
                 root=i;
                 else 
                  return false;
             }
        }
        if(root==-1)
         return false;

        vector<bool>vis(n);
        vis[root]=true;
        if (!binarytree(root,leftchild,rightchild,vis)) 
         return false;

          for( auto it : vis )
         {
             if(!it)
              return false;
         }
         return true;
    }
};