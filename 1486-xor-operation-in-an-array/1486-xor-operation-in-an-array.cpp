class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> nums(n);
        int ans = 0;

        for(int i = 0; i < nums.size(); i++){
            nums[i] = start + 2 * i;
            ans ^= nums[i];
        }

        return ans;
    }
};