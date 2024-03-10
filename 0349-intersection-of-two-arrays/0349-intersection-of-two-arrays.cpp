class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int>ans;
        vector<int>freq_1(1000,0);
         for(int i =0;i<nums1.size();i++)
             freq_1[nums1[i]]=1;
             
            for(int j=0;j<nums2.size();j++)
            {
                if(freq_1[nums2[j]]==1)
                { ans.push_back(nums2[j]);
                  freq_1[nums2[j]]=0;
                }
            }
        return ans;
    }
};