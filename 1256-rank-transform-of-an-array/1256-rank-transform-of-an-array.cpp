class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        if(!arr.size())
         return arr;
         
      unordered_map<int,int> mp;
      vector<int>temp(arr);

      sort(arr.begin(),arr.end());
      int rank =1;

       int last = arr[0];
       mp[arr[0]] = 1;
       for( int i = 1 ;i<arr.size();i++)
       {
          if( arr[i] > last)
          {
            last = arr[i];
            rank++;
          }
          mp[arr[i]] = rank;
       }
      
       for( int i =0 ;i<temp.size();i++)
       {
         temp[i] = mp[temp[i]];
       }
       return temp;
    }
};