class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int start=0,end=nums.size()-1;
        int k=end;
        vector<int>ans(k+1,0);
        while(k>=0)
        {
            if(abs(nums[start])>abs(nums[end]))
                ans[k--]=nums[start]*nums[start++];
             else 
                  ans[k--]=nums[end]*nums[end--];
        }
        return ans;
    }
};