class Solution {
public:
    static int count_one ( int n)
    {
        int count=0;
        while(n)
        {
            count++;
            n=n&(n-1);
        }
        return count;
    }
    static bool comp ( int a,int b)
    {
        int one_a = count_one(a);
        int one_b = count_one(b);

        if( one_a==one_b)
         return a<=b;
        else 
         return one_a<one_b; 
    }
    vector<int> sortByBits(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }
};