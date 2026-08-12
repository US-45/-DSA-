class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            bool leftCheck = (i == 0 || nums[i - 1] == 0);
            bool rightCheck = (i == nums.size() - 1 || nums[i + 1] == 0);

            if (nums[i] == 0 && leftCheck && rightCheck) {
                count++;
                nums[i] = 1;
            }
        }

        return count >= n;
    }
};