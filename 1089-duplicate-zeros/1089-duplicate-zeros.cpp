class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int size = arr.size();
        vector<int> nums(arr);
        int idx = 0;

        for (int i = 0; i < size && idx < size; i++) {
            arr[idx++] = nums[i];

            if (nums[i] == 0 && idx < size) {
                arr[idx++] = 0;
            }
        }
    }
};
