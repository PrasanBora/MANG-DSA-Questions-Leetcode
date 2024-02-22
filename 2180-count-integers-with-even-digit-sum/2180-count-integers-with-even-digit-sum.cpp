class Solution {
public:
    int calSum(int n)
    {
        int sum=0;
        
        while( n>0 )
        {
            sum += n%10;
            n = n/10;
        }
        return sum;
    }
    int countEven(int num) 
    {
        int count=0;
        for( int i =1 ;i<=num;i++)
        {
            int digitSum = calSum(i);
            if(digitSum % 2 == 0)
                count++;
        }
        return count;
    }
};