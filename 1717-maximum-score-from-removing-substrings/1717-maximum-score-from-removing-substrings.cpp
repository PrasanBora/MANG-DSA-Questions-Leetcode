class Solution {
public:
    
    int solve( string &s , int point , string str )
    {
        stack<char> st;
        int total = 0;
        for( auto ch : s)
        {
            if( ! st.empty () && ch == str[1] && st.top() == str[0])
            {
                st.pop();
                total+=point;
            }
            else 
                st.push(ch);
        }
        
        string temp ="";
        
        while( !st.empty() )
        {
            temp+=st.top();
            st.pop();
        }
        
        reverse(temp.begin(),temp.end());
        
        s = temp;
        return total;
    }
    
    int maximumGain(string s, int x, int y) 
    {
        if( x > y )
         return solve(s ,x,"ab") + solve(s ,y,"ba");
        else 
        return solve(s,y,"ba") + solve(s ,x,"ab");
    }
};