class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int start = 0, end = arr.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] > arr[mid + 1]) {
                // We are on the decreasing side.
                // A peak exists at mid or to the left.
                end = mid;
            } 
            else {
                // We are on the increasing side.
                // A peak must exist to the right.
                start = mid + 1;
            }
        }

        return start;
    }
};
