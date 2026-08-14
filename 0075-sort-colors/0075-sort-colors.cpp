class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroIndex = 0;
        int oneIndex = 0;
        int twoIndex = nums.size() - 1;

        while (oneIndex <= twoIndex) {
            if (nums[oneIndex] == 0) {
                swap(nums[zeroIndex], nums[oneIndex]);
                zeroIndex++;
                oneIndex++;
            }
            else if (nums[oneIndex] == 1) {
                oneIndex++;
            }
            else { // nums[oneIndex] == 2
                swap(nums[oneIndex], nums[twoIndex]);
                twoIndex--;
            }
        }
    }
};