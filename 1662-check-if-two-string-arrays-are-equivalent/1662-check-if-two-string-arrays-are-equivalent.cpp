class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int w1 = 0, idx1 = 0;
        int w2 = 0, idx2 = 0;

        while(w1 < word1.size() && w2 < word2.size()){
            if(word1[w1][idx1] != word2[w2][idx2]){
                return false;
            }
            
            idx1++;
            idx2++;
            if(idx1 == word1[w1].size()){
                w1++;
                idx1 = 0;
            }
            if(idx2 == word2[w2].size()){
                w2++;
                idx2 = 0;
            }
        }

        return w1 == word1.size() && w2 == word2.size();
    }
};