class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
      unordered_map<int,int>mp;
      for( auto it :nums)
          mp[it]++;
      int ans=0;

      for( auto it:mp)
      {
          if(it.second ==1)
           return -1;
          int add= it.second/3;
          int rem =it.second%3;

          if(rem>0)
          add++;

         ans+=add; 
      }
      return ans;
    }
};