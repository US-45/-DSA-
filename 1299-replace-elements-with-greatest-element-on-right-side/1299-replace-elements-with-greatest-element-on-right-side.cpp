class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int largest = -1;

        for (int i = arr.size() - 1; i >= 0; i--) {
            int current = arr[i];

            arr[i] = largest;

            largest = max(largest, current);
        }

        return arr;
    }
};
