class Solution {
public:
    bool is_vowel(char ch)
    {
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
               ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U';
    }
    string sortVowels(string s) 
    {
        string temp="";
         for( auto it:s)
          if(is_vowel(it))
           temp+=it;

        sort(temp.begin(),temp.end());
        int j=0;

        for(int i=0;i<s.length();i++)
        {
            if(is_vowel(s[i]))
             s[i]=temp[j++];
        }   
        return s;
          
    }
};