class Solution {
public:
    vector<int> get_right_min(vector<int>&nums,int n)
    {
      vector<int> ans(n);
       stack<int>st;
       for(int i =n-1;i>=0;i--)
       {
           while(!st.empty() && nums[st.top()]>=nums[i])
            st.pop();
           if(st.empty())
            ans[i]= n;
           else 
            ans[i]= st.top();

           st.push(i);   
       }
       return ans;
    }

    vector<int> get_left_min(vector<int>&nums,int n)
    {
       vector<int> ans(n);
       stack<int>st;
       for(int i =0;i<n;i++)
       {
           while(!st.empty() && nums[st.top()]>=nums[i])
            st.pop();
           if(st.empty())
            ans[i]= -1;
           else 
            ans[i]= st.top();

           st.push(i);   
       }
       return ans;

    }
    
    void print(vector<int>& nums)
    {
        for(int i=0;i<nums.size();i++)
        cout<<nums[i]<<" ";
    } 

    int maximumScore(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<int>left = get_left_min(nums,n);
        vector<int>right = get_right_min(nums,n);
        int ans= 0;
        
        print(left);
        cout<<endl;
        print(right);

        for(int i=0;i<n;i++)
        {
            if(left[i]<k && right[i]>k )
             ans= max(ans,nums[i]*(right[i]-left[i]-1));
        }
        return ans;
    }
};