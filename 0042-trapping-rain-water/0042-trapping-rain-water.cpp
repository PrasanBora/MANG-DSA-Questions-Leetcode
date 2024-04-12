// class Solution {
// public:
//     int trap(vector<int>& height)
//     {
//         int ans = 0;
//         int size = height.size();
//         for (int i = 1; i < size - 1; i++) {
//             int left_max = 0, right_max = 0;
//             for (int j = i; j >= 0; j--) { //Search the left part for max bar size
//                 left_max = max(left_max, height[j]);
//             }
//             for (int j = i; j < size; j++) { //Search the right part for max bar size
//                 right_max = max(right_max, height[j]);
//             }
//             ans += min(left_max, right_max) - height[i];
//             cout<< min(left_max, right_max)- height[i] <<endl;
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int trap(vector<int>& height) 
    {
        int left =0;
        int right=height.size()-1;
        int lmax=height[0],rmax=height[right];
        int water=0;
        while(left<=right)
        {
            if(lmax<=rmax)
            {
                if(height[left]>lmax)
                  lmax=height[left];
                else 
                    water = water+ (lmax-height[left]);
                left++;
            }
            else 
            {
                if(height[right]>rmax)
                    rmax=height[right];
                 else 
                    water =  water+ (rmax-height[right] );
                right--;
            }
            // cout<<water<<endl;   
        }
        return water;
    }
};