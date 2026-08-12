class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& nums, int extraCandies) {
        vector<bool> ans;
        int max = INT_MIN;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] > max) max = nums[i];
        }


        for(int i = 0; i< nums.size(); i++){
            if(nums[i] + extraCandies >= max){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};