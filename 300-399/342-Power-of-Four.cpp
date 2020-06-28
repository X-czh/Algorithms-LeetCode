// Time complexity: O(logn).
// Space complexity: O(1).

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num == 1) return true;
        if (num % 4 != 0) return false;
        
        int one_fourth_num = num / 4; // avoid overflow
        int power_of_four = 1;
        while (power_of_four < one_fourth_num) {
            power_of_four *= 4;
        }
        return (power_of_four == one_fourth_num);
    }
};
