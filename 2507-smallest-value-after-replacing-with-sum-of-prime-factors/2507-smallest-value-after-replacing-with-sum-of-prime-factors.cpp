class Solution {
public:
    
    int getsum(int n )
    {
        if( n == 0)
            return 0;
        
        int sum = 0;
        int divisor = 2;
        
        while( n > 1)
        {
            if( n % divisor == 0)
            {
                sum+=divisor;
                n = n/divisor;
            }
            else 
            {
                divisor++;
            }
        }
        return sum; 
    }
    
    
    int smallestValue(int n) 
    {
      while( true )
      {
          int sumofprime = getsum(n);
          
          if( sumofprime == n )
              return n ;
          
          n = sumofprime;
      }
        return -1;
    }
};