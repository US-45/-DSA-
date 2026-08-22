class Solution {
public:
    bool checkDivisibility(int n) {
        int dup = n;
        int product = 1;
        int sum = 0;

        while (dup > 0) {
            int digit = dup % 10;
            sum += digit;
            product *= digit;
            dup /= 10;
        }

        return n % (sum + product) == 0;
    }
};