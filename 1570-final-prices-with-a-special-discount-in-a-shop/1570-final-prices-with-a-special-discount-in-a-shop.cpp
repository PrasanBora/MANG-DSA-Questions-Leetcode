class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) 
    {
      int n=prices.size();
      vector<int> ans(n);
      stack<int>st;

      for(int i=n-1;i>=0;i--)
      {
          while(!st.empty() && prices[st.top()]>prices[i])
           st.pop();
          if(st.empty())
           ans[i]=0;
          else 
           ans[i]=prices[st.top()];

           st.push(i); 
      }

      for(int i=0;i<prices.size();i++)
       ans[i]=prices[i]-ans[i];

       return ans;

    }
};