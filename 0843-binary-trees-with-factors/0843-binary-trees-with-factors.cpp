class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
      int mod =1e9+7;
      sort(arr.begin(),arr.end());
      unordered_map<int, long long>mp;
      long long  ans=0;

       for( auto x:arr) 
       {
           mp[x]=1; // any number as a root onli tree
           for(int i=0;arr[i]<=sqrt(x);i++)
           {
              int y=arr[i];
              if( x%y ==0)
              {
                  int z = x/y;
                  int c = (y==z)?1:2;

                  if(mp.count(z))
                  {
                      mp[x]= mp[x]%mod +(mp[y]*mp[z]*c) % mod;
                  }
                   
              }
           }
           ans= (ans+mp[x])%mod;
       }  
       return ans;
    }
};