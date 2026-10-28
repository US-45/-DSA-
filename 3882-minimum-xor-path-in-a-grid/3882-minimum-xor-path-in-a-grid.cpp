
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // dp[i][j][x] tells whether XOR x can reach cell (i, j).
        vector<vector<bitset<1024>>> dp(
            m, vector<bitset<1024>>(n)
        );

        // Starting cell contributes its own value.
        dp[0][0][grid[0][0]] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                int val = grid[i][j];

                // Come from above.
                if (i > 0) {
                    for (int x = 0; x < 1024; x++) {
                        if (dp[i - 1][j][x]) {
                            dp[i][j][x ^ val] = 1;
                        }
                    }
                }

                // Come from the left.
                if (j > 0) {
                    for (int x = 0; x < 1024; x++) {
                        if (dp[i][j - 1][x]) {
                            dp[i][j][x ^ val] = 1;
                        }
                    }
                }
            }
        }

        // Find the smallest reachable XOR at the destination.
        for (int x = 0; x < 1024; x++) {
            if (dp[m - 1][n - 1][x]) {
                return x;
            }
        }

        return -1;
    }
};
