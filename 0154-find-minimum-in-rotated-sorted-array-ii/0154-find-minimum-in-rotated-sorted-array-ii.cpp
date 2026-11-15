class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX;

        while (low <= high) {

            // Already sorted search space
            if (nums[low] < nums[high]) {
                ans = min(ans, nums[low]);
                break;
            }

            int mid = low + (high - low) / 2;

            // Handle duplicates
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                ans = min(ans, nums[mid]);
                low++;
                high--;
                continue;
            }

            // Left half is sorted
            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            // Right half contains minimum
            else {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }
};