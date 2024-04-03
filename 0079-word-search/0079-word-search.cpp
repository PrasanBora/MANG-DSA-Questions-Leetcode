class Solution {
public:
    bool ans =false;
    int m ,n;
    bool helper(vector<vector<char>>& board, string word,
                 int it ,int i ,int j)
    {
        if( it == word.length()  )
         { 
             return true;
         }
        if(word[it]==board[i][j]) 
        {
          board[i][j]='#';
         if(i>0  && helper(board,word,it+1,i-1,j)  )
         return true;

         if(i<n-1 && helper(board,word,it+1,i+1,j)  )
         return true;

         if(j<m-1 && helper(board,word,it+1,i,j+1)  )
         return true;

         if( j>0 && helper(board,word,it+1,i,j-1)  )
         return true;
         
          board[i][j]=word[it];
        }
        
        return false;
    } 
    bool exist(vector<vector<char>>& board, string word) 
    {
        m = board[0].size();
        n = board.size();
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {

                  if(helper(board ,word ,0 ,i,j) || word.length()==1)
                  return true;
                }
            }
        }
        return false;
    }
};
