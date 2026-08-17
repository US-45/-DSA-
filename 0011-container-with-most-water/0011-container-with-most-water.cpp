class Solution {
public:
    int maxArea(vector<int>& arr) {
        int left = 0, right = arr.size() - 1, maxWater = 0;

        while (left < right) {
            int width = right - left;
            int hight = min(arr[left], arr[right]);
            int area = width * hight;
            maxWater = max(maxWater, area);
            if (arr[left] < arr[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxWater;
    }
};