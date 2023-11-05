class Solution {
public:
    int getWinner(vector<int>& arr, int k) 
    {
        int curr=arr[0];
        int win=0;
        for(int i=1;i<arr.size();i++)
        {
            if(curr<arr[i])
            {
                curr=arr[i];
                win=1;
            }
            else
             win++;

            if(win==k)
             break;
        }
        return curr;
    }
};