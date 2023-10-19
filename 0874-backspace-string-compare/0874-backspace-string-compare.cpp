class Solution {
public:
    //  string simplify(string str)
    //  {
    //      stack<char>st;
    //      for(int i=0;i<str.length();i++)
    //      {
    //          if(str[i]=='#')
    //          {
    //            if(st.empty()) continue;
    //            else st.pop();
    //          }
    //          else 
    //           st.push(str[i]); 
    //      }
    //      string ans="";

    //      while(!st.empty())
    //       {ans = st.top()+ans;
    //       st.pop();}

    //      return ans; 
    //  }
    bool backspaceCompare(string s, string t) 
    {
        // s = simplify(s);
        // t =simplify(t);

        // return s==t;
//----------------------------------------------------
        //  string temp1;
        //  string temp2;
        // for( int i=0;i<s.length();i++)
        // {
        //    if(s[i]!='#')
        //     temp1.push_back(s[i]);
        //    else 
        //      if(temp1.length())temp1.pop_back(); 
        // }
        // for( int i=0;i<t.length();i++)
        // {
        //    if(t[i]!='#')
        //      temp2.push_back(t[i]);
        //    else 
        //      if(temp2.length())temp2.pop_back();
        // }
        // return temp1==temp2;

  //--------------------------------------------
       int i=s.length()-1;
       int j=t.length()-1;
       int skipS=0;
       int skipT=0;

       while(i>=0||j>=0)
       {
           while(i>=0)
           {
               if(s[i]=='#')
                skipS++,i--;
               else if(skipS>0) 
                skipS--,i--;
               else 
               break; 
           }

           while(j>=0)
           {
               if(t[j]=='#')
                skipT++,j--;
               else if(skipT>0) 
                skipT--,j--;
               else 
               break; 
           }
           if(i<0 &&j<0)
            return true;
           if(i<0||j<0) return false;
           else if(s[i]!=t[j])
             return false; 

            i--;
            j--; 
       }      
       return true;
    }
};