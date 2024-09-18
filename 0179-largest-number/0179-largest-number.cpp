
class Solution {
public:
    static bool compare (int i1 ,int i2)
    {
        string s1= to_string(i1);
        string s2= to_string(i2);
            return (s1+s2 >s2+s1);
    }
    string largestNumber(vector<int>& nums)
    {
        sort(nums.begin(),nums.end(),compare);
        
        string ans="";
        
        for(int i=0;i<nums.size();i++)
            ans+=to_string(nums[i]);
        
        if(ans[0]=='0')
            return "0";
        
        return ans;
    }
};