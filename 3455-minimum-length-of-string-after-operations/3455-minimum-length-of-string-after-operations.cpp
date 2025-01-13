class Solution {
public:
    int minimumLength(string s) 
    {
      unordered_map<int,int>freq;
      for (int i =0 ;i<s.length();i++)
      {
        freq[s[i]]++;
      } 
      int del =0;  
      for ( auto it:freq)
      {
        int count = it.second;

        if(count % 2 == 1)
        {
            del += (count-1);
        }
        else 
         del += (count-2);

      }
       return s.length()-del;
    }
};