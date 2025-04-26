class Solution {
public:
    bool checkIfExist(vector<int>& arr) 
    {
       map<int,int>seen;
       for ( int i =0 ;i<arr.size();i++)
        seen[arr[i]]= i  ;

      for ( int i =0 ;i<arr.size();i++)
      {
        if( seen.find(2*arr[i])!=seen.end() && (seen[2*arr[i]] != i )){
            return true ;
        }
    
      }            
      return false ;
    }
};