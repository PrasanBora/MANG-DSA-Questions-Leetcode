class Solution {
public:
    void insert_remove(unordered_map<char,int>&mp,char insert, char del)
    {
      mp[insert]++;
      mp[del]--;
      if(mp[del]==0)
       mp.erase(del);
    }

    bool isItPossible(string word1, string word2) 
    {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;

        for(int i=0;i<word1.size();i++)
         mp1[word1[i]]++;
        for(int i=0;i<word2.size();i++)
         mp2[word2[i]]++;

        for(char i='a';i<='z';i++)
        {
            for(int j='a';j<='z';j++)
            {
                if(mp1.count(i)==0 || mp2.count(j)==0)
                 continue;

                insert_remove(mp1,j,i);
                insert_remove(mp2,i,j);

                if(mp1.size()==mp2.size())
                {
                    cout<<i<<j;
                   return true;
                }
                 
                insert_remove(mp1,i,j);
                insert_remove(mp2,j,i); 
            }
        }  
        return false;
    }
};