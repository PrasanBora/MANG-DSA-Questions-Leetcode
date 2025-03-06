class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
    {
         long long n = grid[0].size();
         long long m = n*n;
        
        long long expectedSum = (m)*(m+1)/2;

        long long expectedSqSum =  m*(m+1)*(2*m+1)/6 ;

        long long sum =0;
        long long sqSum =0;

        for( int i = 0;i<n;i++)
        {
            for(int j =0;j<n;j++)
            {
                sum+=grid[i][j];
                sqSum+=(grid[i][j]*grid[i][j]);
            }
        }
        int p = sum - expectedSum;
        int q = sqSum - expectedSqSum;
        int repeate = (q/p + p )/2;
        int missing  = (q/p - p )/2;
        return {repeate,missing};   
    }
};