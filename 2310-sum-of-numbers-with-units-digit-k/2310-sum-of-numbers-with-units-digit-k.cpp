class Solution {
public:
    int solve( int num ,int index, vector<vector<int>>& dp ,vector<int>&ans )
    {
        if( num < 0 || index >= ans.size() )
            return INT_MAX;
        if( num == 0 )
            return 0;
        
        if( dp[num][index] != -1)
            return dp[num][index];
        
        int take  = solve( num - ans[index],index,dp,ans);
        
        int nottake = solve( num ,index+1,dp,ans);
        
        if(take!=INT_MAX)
            take++;
        
         return dp[num][index] = min(take,nottake);
        
    }
    int minimumNumbers(int num, int k) 
    {
        if (num == 0) 
            return 0;
        if( num % 10 == k)
            return 1;
        
        vector<int>ans;
        
        for( int i = 1 ;i <= num ;i++)
            if(i % 10 == k)
                ans.push_back(i);
         
        vector<vector<int>>dp(num+1,vector<int>(ans.size()+1,-1)); 
        
        int res = solve( num ,0,dp,ans);
        
        if( res == INT_MAX)
            return -1;
        
        return res;   
    }
};