class Solution {
public:
    string numberToWords(int num) 
    {
      if(num == 0 ) 
          return "Zero";
        
      vector<string> ones = { "" ,"One","Two","Three","Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"}; 
      vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
      vector<string> thousands = {"", "Thousand", "Million", "Billion"};
        
        string res = "";
        int gindex = 0;
        
        while(num > 0)
        {
            if( num % 1000)
            {
                string temp_res ="" ;
                
                int part = num % 1000;
                
                if(part >=100 )
                {
                    temp_res = ones[part/100] +" " + "Hundred"+ " ";
                    part %= 100;
                }
                
                if( part >= 20)
                {
                    temp_res += tens[part/10] + " ";
                    part %= 10;
                }
                
                if( part > 0)
                {
                    temp_res += ones[part] + " ";
                }
                
                temp_res += thousands[gindex] + " ";
            
                res = temp_res + res;
            }
              
             num = num/1000 ;
             gindex++;
              
        }
        
        return res.substr(0,res.find_last_not_of(" ")+1);
        
    }
};