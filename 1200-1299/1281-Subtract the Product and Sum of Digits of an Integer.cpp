// Time complexity: O(logn).
// Space complexity: O(1) extra space.

class Solution {
public:
    int subtractProductAndSum(int n) {
        if (n == 0)
            return 0;

        int prod = 1;
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            prod *= digit;
            sum += digit;
            n /= 10;       
        }
        return prod - sum;
    }
};
