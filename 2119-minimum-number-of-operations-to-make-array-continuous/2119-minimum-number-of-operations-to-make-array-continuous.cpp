class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n = nums.size()-1;
        int l =0;
        int count=0,maxi=0;

        for(int i=0;i<nums.size();i++)
        {
            if( i+1<nums.size()&&nums[i]==nums[i+1])
             continue;
            nums[l++]=nums[i]; 
        }
        
        int r=0;
        for(int i=0;i<l;i++)
        {
            while(r<l && (nums[r]-nums[i] <=n))
            {
                count++;
                r++;
            }
            maxi =max(maxi,count);
            count--;
        }
        return nums.size()-maxi;
    }
};