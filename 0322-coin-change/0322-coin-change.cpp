class Solution {
public:
    
    int solve( vector<int>&coins ,int amount,int index,vector<vector<int>>&dp)
    {
        if( index>=coins.size() || amount<=0)
        {
            if( amount == 0)
                return 0;
            else 
                return INT_MAX-1;
        }
        
        if(dp[index][amount]!=-1)
          return dp[index][amount];        
        
        int take =0,leave =0;
        
        take = 1+solve(coins,amount-coins[index],index,dp);
        leave = solve(coins,amount,index+1,dp);
        
        return dp[index][amount] = min(take,leave);
        
    }
    
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        
        int res = solve ( coins ,amount,0 ,dp);
        
        if( res >= (INT_MAX-1) )
            return -1;
        else 
            return res;
    }
};