class Solution {
public:
     string simplify(string str)
     {
         stack<char>st;
         for(int i=0;i<str.length();i++)
         {
             if(str[i]=='#')
             {
               if(st.empty()) continue;
               else st.pop();
             }
             else 
              st.push(str[i]); 
         }
         string ans="";

         while(!st.empty())
          {ans = st.top()+ans;
          st.pop();}

         return ans; 
     }
    bool backspaceCompare(string s, string t) 
    {
        s = simplify(s);
        t =simplify(t);

        return s==t;
    }
};