class Solution {
public:
    int countSymmetricIntegers(int low, int high) 
    {
        int ans=0;
       for(int i=low;i<=high;i++)
       {
           int left =0;
           int right =0;

           
              string temp = to_string(i); 
              if(temp.size()%2==0)
              {int n=temp.size()/2;
              for(int i=0;i<temp.size()/2;i++)
               {
                   left +=temp[i]-'0';
                   right +=temp[n+i]-'0';
               }
                if( left==right)
                   {
                      cout<< left<<" "<<right<<endl;
                       ans++;
                   }
               }
           
       }   
        return ans;
    }
};