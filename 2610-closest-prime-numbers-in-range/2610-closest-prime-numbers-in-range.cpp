class Solution {
    vector<int> sieve(int n) {
        vector<int> arr(n + 1, 1);

        arr[0] = 0;
        arr[1] = 0;

        for (int i = 2; i * i <= n; i++) {
            if (arr[i] == 1) {
                for (int multiple = i * i; multiple <= n; multiple += i) {
                    arr[multiple] = 0;
                }
            }
        }
        return arr;
    }

public:
    vector<int> closestPrimes(int left, int right) {
        vector<int>primeArray = sieve(right);

        vector<int>num ;

        for(int i=left;i<=right;i++){
           if(primeArray[i])
            num.push_back(i);
        }
        vector<int>res(2,-1);  
        if(num.size() < 2)
         return res ;
        
        int minDiff = INT_MAX;

        for(int i =1 ;i<num.size();i++){
            if( num[i]-num[i-1] < minDiff)
            {
                minDiff = (num[i]-num[i-1]);
                res[0] = num[i-1];
                res[1] = num[i];
            }
        } 
        return res ;
    }
};