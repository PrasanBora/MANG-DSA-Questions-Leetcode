class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        if (k <= 1) 
         return 0;
         
        int product =1;
        int left =0;
        int right =0;
        int subarray =0;

        for( right = 0; right<nums.size();right++)
        {
            product *= nums[right];

            while( product >= k )
            {
                 product/=nums[left++];
            }
            
            subarray  += right - left + 1;

        }
        return subarray;
    }
};