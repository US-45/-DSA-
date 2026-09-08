class Solution {
public:
    bool detectCapitalUse(string word) {
        int upper = 0;

        for (char c : word) {
            if (c >= 'A' && c <= 'Z')
                upper++;
        }

        return upper == 0 ||
               upper == word.size() ||
               (upper == 1 && word[0] >= 'A' && word[0] <= 'Z');
    }
};
