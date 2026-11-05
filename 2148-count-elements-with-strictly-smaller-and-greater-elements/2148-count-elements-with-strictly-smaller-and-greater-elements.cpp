class Solution {
public:
    int countElements(vector<int>& nums) {
        int Max = INT_MIN, Min = INT_MAX, count = 0;

        for(auto val: nums){
            if(val > Max){
                Max = val;
            }
            
            if (val < Min){
                Min = val;
            }
        }

        for(auto num : nums){
            if(num > Min && num < Max){
                count++;
            }
        }

        return count;
    }
};