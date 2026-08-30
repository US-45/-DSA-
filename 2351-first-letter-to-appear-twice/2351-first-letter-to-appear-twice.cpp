class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> hash;

        for (char ch : s) {
            if (hash.find(ch) != hash.end()) {
                return ch;
            }
            hash.insert(ch);
        }

        return '\0'; 
    }
};
