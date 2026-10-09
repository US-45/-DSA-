class Solution {
public:
    int minInsertions(string s) {
        int openCount = 0, insertions = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                openCount++;
            } else {
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                } else {
                    insertions++;
                }

                if (openCount > 0) {
                    openCount--;
                } else {
                    insertions++;
                }
            }
        }

        return insertions + 2 * openCount;
    }
};