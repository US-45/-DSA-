class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest = INT_MIN, secLargest = INT_MIN;

        for(auto i : nums){
            if(i > largest){
                secLargest = largest;
                largest = i;
            }else if(i > secLargest){
                secLargest = i;
            }
        }

        return (secLargest - 1) * (largest - 1) ;
    }
};