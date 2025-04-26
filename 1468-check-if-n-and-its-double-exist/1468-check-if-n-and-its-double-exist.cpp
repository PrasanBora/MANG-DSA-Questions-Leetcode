class Solution {
public:
    bool checkIfExist(vector<int>& arr) 
    {
       unordered_map<int,int>seen;
      for ( int i =0 ;i<arr.size();i++)
      {
        if( arr[i]!=0 && (seen[2*arr[i]] || (arr[i]%2==0 && seen[arr[i]/2]))){
            return true ;
        }
        if(arr[i]==0 && seen[arr[i]]==1)
         return true ;

        seen[arr[i]]++;
    
      }            
      return false ;
    }
};