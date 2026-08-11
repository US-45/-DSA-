class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int count = 0;
        int index = 0;

        for (int i = 0; i < s.size() && index < g.size(); i++) {
            if (s[i] >= g[index]) {
                count++;
                index++;
            }
        }

        return count;
    }
};