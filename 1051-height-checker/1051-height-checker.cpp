class Solution {
public:
    int heightChecker(vector<int>& heights) 
    {   
        int count=0;
        vector<int>temp = heights;
        sort(temp.begin(),temp.end());
        
        for( int i =0;i<temp.size();i++)
        {
            if( temp[i]!=heights[i] )
                count++;
        }
        return count;
    }
};