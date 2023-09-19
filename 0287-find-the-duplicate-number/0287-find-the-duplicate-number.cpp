class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int low =1;
        int high=nums.size()-1,cnt;

        while( low<=high )
        {
            int mid= low +(high-low)/2;
            cnt=0;
            for( int n:nums)
            if(n<=mid) cnt++;

            if(cnt<=mid)
             low =mid+1;
            else 
             high= mid-1; 
        }
        return low;
    }
};