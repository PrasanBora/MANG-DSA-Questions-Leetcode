class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) 
    {
      unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
          int maxFreq = 0;
    for (const auto& entry : freq) 
    {
        maxFreq = std::max(maxFreq, entry.second);
    }

    int maxFreqElements = 0;
    for (const auto& entry : freq) 
    {
        if (entry.second == maxFreq) 
        {
            maxFreqElements++;
        }
    }

    return maxFreqElements*maxFreq;
    }
};