class Solution{
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders){
        int n = heights.size();

        // min heap to store the jumps made in increasing order
        priority_queue<int, vector<int>, greater<int>> jumps;

        for(int i=0; i<n-1; i++){
            // calculate the difference in heights
            int diff = heights[i+1] - heights[i];
            if(diff > 0){
                // try a jump of size diff
                jumps.push(diff);

                // if already used all the ladders for jumps 
                if(jumps.size() > ladders){
                    // use bricks of height lowest jump
                    int bricks_needed = jumps.top();
                    jumps.pop();

                    // if we don't have enough bricks 
                    if(bricks_needed > bricks) return i;
                    // use bricks and subtract the amount used
                    else bricks -= bricks_needed;
                }
            }
        }
        return n-1;
    }
};