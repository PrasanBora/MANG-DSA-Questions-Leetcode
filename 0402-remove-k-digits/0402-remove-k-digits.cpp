class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        if(k>=num.length())
         return "0";
        stack<char>st;
        
        for(int i=0;i<num.length();i++)
        {
            while(!st.empty() && st.top()>num[i] && k)
            {
               st.pop();
               k--;
            }
            st.push(num[i]);
            if(st.size()==1 && num[i]=='0')
             st.pop();
        }
        while(k && !st.empty())
        {
            st.pop();
            k--;
        }
        num="";
        while(!st.empty())
        {
          num+=st.top();
          st.pop();
        }
        if(num=="")
         return "0";
        reverse(num.begin() ,num.end());
        
        return num;
    }
};