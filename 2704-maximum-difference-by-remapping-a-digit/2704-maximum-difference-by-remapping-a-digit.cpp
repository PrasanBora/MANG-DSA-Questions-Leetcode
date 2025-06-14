class Solution {
public:
    int minMaxDifference(int num) {

        string original =to_string(num);
        string str = to_string(num);
        int max ,min;
        
        char firstNonNine ;
        for(int i =0;i<str.length();i++)
        {
             if(str[i]!='9')
             {firstNonNine = str[i];
             break;}
        }
        for(int j=0;j<str.length();j++)
        {
            if(str[j]==firstNonNine)
            { str[j]='9';}
        }
         max =stoi(str);
         
        str =original; 
        char firstNonZer0 =str[0];
        for( int i=0;i<str.length();i++)
        {
            if(firstNonZer0 == str[i])
            {
                str[i]='0';
            }
        }
        min =stoi(str);

        return max-min;
    }
};