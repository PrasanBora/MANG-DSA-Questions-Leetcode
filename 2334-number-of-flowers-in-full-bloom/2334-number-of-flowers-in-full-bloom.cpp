class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) 
    {
        vector<int>st,ed;
        int m = flowers.size();
        for( auto i:flowers)
        {
            st.push_back(i[0]);
            ed.push_back(i[1]);
        }
        sort(st.begin(),st.end());
        sort(ed.begin(),ed.end());

        vector<int>v;
        for(int i=0;i<people.size();i++)
        {
            int p = (upper_bound(st.begin(), st.end(), people[i]) - st.begin());

            // Calculate the number of flowers blooming at or after the person's bloom time.
            int q = (lower_bound(ed.begin(), ed.end(), people[i]) - ed.begin());

            // Calculate the bloom status for the person and store it in the result vector.
            v.push_back( p-q);
        }
        return v;
    }
};