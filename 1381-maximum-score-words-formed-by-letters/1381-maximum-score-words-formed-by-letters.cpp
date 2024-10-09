class Solution {
public:
    // question is asking max score of a subset i can create from
    // vector words and the condition is i can only include words i 
    // can create frm the charactes given i cant use them more than 
    // the given times 

    int maxScore = 0;

    int calculateScore(string& word, unordered_map<char, int>& letterCount,
                       vector<int>& letterScores) 
    {
        // will check if i can include word and cal score
        int currentScore = 0;
        for (char ch : word) 
        {
            if (letterCount.count(ch)) 
            {
                if (letterCount[ch] > 0) 
                {
                    currentScore += letterScores[ch - 'a'];
                    letterCount[ch]--;
                } // only include those which i can make from given
                  // letters
                else 
                {
                    return 0;
                }
            } 
            else 
                return 0;
            
        }
        return currentScore;
    }

    void findMaxScore(int index, vector<string>& words,
                      vector<int>& letterScores,
                      unordered_map<char, int> letterCount, int currentVal) 
    {
        if (index == words.size()) 
        {
            maxScore = max(maxScore, currentVal);
            return;
        }
        
        // excluding the current word 
        findMaxScore(index + 1, words, letterScores, letterCount, currentVal);
        
        // now try including that first check is that possible 
        // if not will add 0 in curr val 
        int wordScore = calculateScore(words[index], letterCount, letterScores);
        if (wordScore > 0) 
        {
            findMaxScore(index + 1, words, letterScores, letterCount,
                         currentVal + wordScore);
        }
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& letterScores)
   {
        unordered_map<char, int> letterCount;
        // map will help to cal score and freq
        for (char ch : letters) 
        {
            letterCount[ch]++;
        }

        findMaxScore(0, words, letterScores, letterCount, 0);
        return maxScore;
    }
};