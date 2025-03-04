class Solution {
public:
    bool solve(int p , int n){
        if(n == 0)
         return true;

        if( pow(3,p) > n )
         return false;

        bool take = solve( p+1 , n - pow(3,p));
        bool skip = solve( p+1, n);

        return skip || take   ;
    }
    bool checkPowersOfThree(int n) {

        return solve(0,n);
        
    }
};