class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int res=0 ;
        for ( int i =0 ;i<nums.size();i++)
        {
            if(i+2 <nums.size())
            { 
               if( 2*(nums[i] + nums[i+2]) == (nums[i+1]))
                ++res;
            }
            
        }
        return res;
    }
};