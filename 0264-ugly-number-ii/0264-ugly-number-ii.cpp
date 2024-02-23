class Solution {
public:
    #define ll  long long 
    int nthUglyNumber(int n) 
    {
         priority_queue<ll,vector<ll>,greater<ll>>pq;
        
        pq.push(1);
        for(int i=0 ;i<n-1;i++)
        {
            ll temp = pq.top();
            pq.pop();
            
            while(!pq.empty() && temp == pq.top())
             pq.pop();
            
            pq.push(temp*2);
            pq.push(temp*3);
            pq.push(temp*5);
        }
        return pq.top();   
    }
};