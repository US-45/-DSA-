
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxim = 0;
        int sum = 0;

        for (int num : nums) {
            maxim = max(maxim, num);
            sum += num;
        }

        return (maxim * nums.size()) - sum;
    }
};
