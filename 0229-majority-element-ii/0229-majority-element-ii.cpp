class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size(), threshold = n/3;
        int count1 = 0, count2 = 0;
        int val1 = 0, val2 = 0;

        for(auto current : nums){
            if(count1 == 0 && val2 != current){
                val1 = current;
                count1 = 1;
            }else if(count2 == 0 && val1 != current){
                val2 = current;
                count2 = 1;
            }else if(val1 == current){
                count1++;
            }else if(val2 == current){
                count2++;
            }else{
                count1--;
                count2--;
            }
        }

        count1 = 0, count2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (val1 == nums[i]) {
                count1++;
            } else if (val2 == nums[i]) {
                count2++;
            }
        }

        if(count1 > threshold ){
            ans.push_back(val1);
        }
        if(count2 > threshold ){
            ans.push_back(val2);
        }

        return ans;
    }
};