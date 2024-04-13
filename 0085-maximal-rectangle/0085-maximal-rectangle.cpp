class Solution {
public:

    vector<int> leftmin(vector<int>arr)
    {
      vector<int> res(arr.size());
      stack<int> st;
      for(int i=0;i<arr.size();i++)
      {
          while(!st.empty() && arr[st.top()] >=arr[i]) 
            st.pop();

        if(st.empty())
              res[i]=-1;
        else
           res[i]=st.top();
             
             st.push(i); 
      }
      return res;
    }

    vector<int> rightmin(vector<int>arr)
    {
      vector<int> res(arr.size());
      stack<int> st;
      for(int i=arr.size()-1;i>=0;i--)
      {
          while(!st.empty() && arr[st.top()] >=arr[i]) 
            st.pop();

        if(st.empty())
              res[i]=-1;
        else
             res[i]=st.top();

             st.push(i);     
      }
      return res;
    }
    int maxarea( vector<int> arr)
    {
        vector<int>left =leftmin(arr);
        vector<int>right =rightmin(arr);

        int maxarea=INT_MIN;

        for(int i=0;i<arr.size();i++)
        {
            int l = arr[i];
            int b = right[i]-left[i]-1;
             if(right[i]==-1)
                b= arr.size()-left[i]-1;
            maxarea =max(maxarea,l*b);
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int maxi=INT_MIN;
        vector<int>area(matrix[0].size(),0);
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
              if(matrix[i][j]=='1')
               area[j]++;
              else 
               area[j]=0; 
            }
            maxi =max(maxi , maxarea(area));
        }
        return maxi;
    }
};