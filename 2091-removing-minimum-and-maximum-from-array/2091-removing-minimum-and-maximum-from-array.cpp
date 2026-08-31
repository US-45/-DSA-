class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minValue = INT_MAX, minIndex;
        int maxValue = INT_MIN, maxIndex;

        for(int i = 0; i< nums.size(); i++){\
            if(nums[i] < minValue){
                minValue = nums[i];
                minIndex = i;
            }

            if(nums[i] > maxValue){
                maxValue = nums[i];
                maxIndex = i;
            }
        }
        // case 1 both from left
        int c1 = max(minIndex, maxIndex) + 1;

        // case 2 both from right
        int c2 = n - min(minIndex, maxIndex);

        // case 3 both the sides
        int c3 = min(minIndex, maxIndex) + 1 + n - max(minIndex, maxIndex);

        return min({c1,c2,c3});
    }
};