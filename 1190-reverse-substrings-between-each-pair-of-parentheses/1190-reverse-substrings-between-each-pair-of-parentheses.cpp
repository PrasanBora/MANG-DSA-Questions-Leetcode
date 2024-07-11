class Solution {
public:
    string reverseParentheses(string s) 
    {
        stack <int>st;
        
        string res="";
        
        for( int i = 0; i<s.length(); i++)
        {
            if( s[i] == '(')
                st.push(res.length());
            else if( s[i] == ')')
            {
                int start = st.top();
                st.pop();
                
                reverse(res.begin()+start,res.end());
            }
            else     
                res+=s[i];
         }
        return res;
    }
};