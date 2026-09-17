class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int size = nums.size();

        vector<int> leftSum(size, 0);
        vector<int> rightSum(size, 0);
        vector<int> answer(size, 0);

        for (int i = 1; i < size; i++) {
            leftSum[i] = leftSum[i - 1] + nums[i - 1];
        }

        for (int i = size - 2; i >= 0; i--) {
            rightSum[i] = rightSum[i + 1] + nums[i + 1];
        }
        for (int i = 0; i < size; i++) {
            answer[i] = abs(leftSum[i] - rightSum[i]);
        }

        return answer;
    }
};