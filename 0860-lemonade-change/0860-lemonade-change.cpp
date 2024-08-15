class Solution {
public:
    bool lemonadeChange(vector<int>& bills) 
    {
      int d_5 = 0 ;
      int d_10 = 0 ;
      
        
        for( auto bill :bills)
        {
            int left = bill -5 ;
            
            if( left >=5 )
            {
               if( left == 15 && d_5>0 && d_10>0)
               {
                   d_5--;
                   d_10--;
               }
                
                else if( left == 15 && d_5>=3 )
                {
                    d_5 = d_5-3;
                }
                
                else if (left == 5 && d_5>=1)
                {
                    d_5 = d_5-1;
                }
               else 
                   return false;
                
            }
    
          if( bill == 5 )
              d_5++;
          else if( bill == 10 )
              d_10++;
             
        }
        return true;
    }
};