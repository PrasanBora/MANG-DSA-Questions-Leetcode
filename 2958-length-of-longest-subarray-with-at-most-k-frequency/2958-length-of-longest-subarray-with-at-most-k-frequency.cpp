class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) 
    {
        int l =0 ;
        int r =0;
        int mxlen = -1;
        int len =0;
        
        unordered_map<int,int>freq;
        
        while( r < nums.size() )
        {
            freq[nums[r]]++;
            
            if( freq[nums[r]] > k )
            {
                while( nums[l] != nums[r])
                {
                     freq[nums[l]]--;
                      l++;
                    
                }
                  
                freq[nums[l]]--;
                l++;
            }
            
            len = r - l +1 ;
            mxlen = max( len ,mxlen );
            r++;
            
            
        }
        
        return mxlen;
    }
};