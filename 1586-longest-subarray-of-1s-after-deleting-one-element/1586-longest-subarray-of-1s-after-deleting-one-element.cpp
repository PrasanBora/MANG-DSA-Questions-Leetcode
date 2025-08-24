class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int left=0;
        int right=0;
        int count=0;
    
        int len=0;
        while(right<nums.size())
        {
            if(nums[right]==0)
               count++;
  
            if(count<=1)
            len = max(len,right-left);
            
            while(count==2)
            {
                if(!nums[left])
                 count--;
                 left++;
            }
            right++;
        }
        return len; 
    }
};