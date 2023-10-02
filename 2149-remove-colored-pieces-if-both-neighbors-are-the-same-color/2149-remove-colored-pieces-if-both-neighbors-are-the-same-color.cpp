class Solution {
public:
    bool winnerOfGame(string colors) 
    {
      int alice=0,bob=0;

      for(int i=1;i<colors.size()-1;i++)
      {
          char curr = colors[i];
          char next = colors[i+1];
          char prev = colors[i-1];

          if( curr=='A'&& prev =='A' && next =='A' )
           alice++;
          if( curr=='B' && prev=='B'&& next =='B')
           bob++; 
      }   
      return alice>bob;
    }
};