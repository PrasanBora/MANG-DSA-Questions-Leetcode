class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n =nums.size();
        vector<int>prefix(n+1,0);
        vector<int>suffix(n+1,0);
        prefix[0]=1;
        suffix[0]=1;

        for( int i=0;i<n;i++)
        {
            prefix[i+1]= nums[i]*prefix[i];
            suffix[i+1]= suffix[i]*nums[n-i-1];
        }
        for(int i=0;i<n;i++)
        {
            cout<<prefix[i]<<"    "<<suffix[n-i-1]<<endl;
            nums[i]=prefix[i]*suffix[n-i-1];
        }
        return nums;
    }
};