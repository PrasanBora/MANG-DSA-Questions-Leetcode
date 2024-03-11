class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) 
    {
        map<int,vector<int>>mp;
        
      for( int i = 0;i<score.size();i++)
      {
          mp[score[i][k]] = score[i]; 
      }
        
        int n = score.size()-1;
        
        for( auto it:mp)
        score[n--] =  it.second;
        
        return score;
    }
};