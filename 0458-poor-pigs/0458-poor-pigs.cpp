class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) 
    {
        int test = minutesToTest/minutesToDie+1;
        int i=0;
        while( pow(test,i)< buckets)
        {
            i++;
        }
        return i;
    }
};