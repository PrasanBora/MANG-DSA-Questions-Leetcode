class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long res =0 ;
        long long maxNum =0;
        long long maxDiff =0;

        for( int i =0 ;i <nums.size();i++)
        {   
            res= max(res, maxDiff*nums[i]);
           
            maxDiff= max(maxDiff ,maxNum-nums[i]);

            maxNum= max(maxNum , static_cast<long long>(nums[i]));
        }
        return res;
    }
};