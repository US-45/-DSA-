class Solution {
public:
    int minAddToMakeValid(string s) {
        int openCount = 0;
        int ans = 0;

        for (char ch : s) {
            if (ch == '(') {
                openCount++;
            } else {
                if (openCount > 0) {
                    openCount--;
                } else {
                    ans++;
                }
            }
        }

        return ans + openCount;
    }
};
