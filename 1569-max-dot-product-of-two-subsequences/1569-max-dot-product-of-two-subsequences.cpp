class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2,int it1,int it2,vector<vector<int>>&dp)
    {
        if(it1>=nums1.size() || it2>=nums2.size())
         return 0;

        if(dp[it1][it2]!=-1)
         return dp[it1][it2]; 

        int c1 = INT_MIN;
        int c2 = INT_MIN;
        int c3 = INT_MIN;
        int ans = nums1[it1]*nums2[it2];

        // c1 = max (nums1[it1]*nums2[it2],nums1[it1]*nums2[it2] + solve(nums1,nums2,it1+1,it2+1));

        c1 = nums1[it1]*nums2[it2] + solve(nums1,nums2,it1+1,it2+1,dp);

        if( it1+1 < nums1.size())
        c2 = solve(nums1,nums2,it1+1,it2,dp);

        if( it2+1 < nums2.size())
        c3 = solve(nums1,nums2,it1,it2+1,dp);
        
        ans = max({ans,c1,c2,c3});
        return dp[it1][it2]=ans;
        // return ans;
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<vector<int>>dp(5000,vector<int>(5000,-1));
        return solve(nums2,nums1,0,0,dp);
    }
};