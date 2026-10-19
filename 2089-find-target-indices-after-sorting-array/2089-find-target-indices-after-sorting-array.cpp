class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int low = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int high = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        vector<int> ans;

        for (int i = low; i < high; i++) {
            ans.push_back(i);
        }

        return ans;
    }
};