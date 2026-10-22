class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;

        // Find the position of 0
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zero = i;
                break;
            }
        }

        bool forward = true;
        bool backward = true;

        // Check increasing order in both directions
        for (int i = 0; i < n - 1; i++) {
            int a = (zero + i) % n;
            int b = (zero + i + 1) % n;

            if (nums[a] > nums[b])
                forward = false;

            int c = (zero - i + n) % n;
            int d = (zero - i - 1 + n) % n;

            if (nums[c] > nums[d])
                backward = false;
        }

        int ans = INT_MAX;

        if (forward) {
            ans = min(ans, zero);
            ans = min(ans, n - zero + 2);
        }

        if (backward) {
            ans = min(ans, zero + 2);
            ans = min(ans, n - zero);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};