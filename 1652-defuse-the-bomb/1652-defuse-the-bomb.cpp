class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) 
    {
      int n = code.size();
      vector<int>res(n,0);
        
        if( k == 0)
            return res;
        
        int start = 1;
        int end = k;
        
        if(k<0)
        {
            k = abs(k);
            start = n-k;
            end = n-1;
            
        }
        int sum =0;
        for( int i =start;i<=end;i++)
        {
            sum+=code[i];
        }
        
        for( int i=0;i<n;i++)
        {
            res[i] = sum;
            
            end++ ;
            // cout<<start%n<<" "<<end%n<<endl;
            sum -= code[start %n];
            sum += code[end %n];
            start++;
            
        }
        return res;
        
    }
};