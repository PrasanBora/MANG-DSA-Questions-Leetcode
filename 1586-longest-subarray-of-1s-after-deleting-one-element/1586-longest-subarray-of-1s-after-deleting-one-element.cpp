class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left =0;
        int right =0;
        int maxLen=0;
        int allowedZero=0;

        while(right < nums.size())
        {
            if( !nums[right])
            allowedZero++;

            if( allowedZero < 2)
            {
                maxLen = max(maxLen,right-left);
            }

            while(allowedZero >= 2)
            {
                if(!nums[left])
                allowedZero--;

                    left++;
            }
            right++;
        }
        return maxLen;
    }
};