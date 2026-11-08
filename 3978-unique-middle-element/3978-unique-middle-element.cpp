class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int mid = nums.size() / 2;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == nums[mid] && i != mid)  return false;
        }

        return true;
    }
};