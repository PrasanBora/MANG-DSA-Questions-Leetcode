class Solution {
public:
    
    bool is_operation( char ch)
    {
        return (ch == '+') || (ch == '-') || (ch == '*');
    }
    
    vector<int> solve ( int start ,int end ,string & exp)
    {
       int len = end-start+1;
        if( len<=2 )
            return {stoi(exp.substr(start,len))};
        
        vector<int> res;
        
        for( int i = start ;i<=end;i++)
        {
            if( is_operation(exp[i]))
            {
                vector<int> left = solve(start,i-1,exp);
                vector<int> right = solve(i+1,end,exp);
                
                char op = exp[i];
                
                for(auto l : left)
                {
                    for( auto r : right)
                    {
                        if( op =='+')
                            res.push_back(l+r);
                        if( op == '-')
                            res.push_back(l-r);
                        else if( op == '*')
                            res.push_back(l*r);
                    }
                }
            }
        }
        return res;
    }
    
    vector<int> diffWaysToCompute(string exp) 
    {
      int n = exp.length();   
        
        return solve(0,n-1,exp);
    }
};