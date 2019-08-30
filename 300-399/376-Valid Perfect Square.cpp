// Time complexity: O(logn).
// Space complexity: O(1).

class Solution {
public:
    bool isPerfectSquare(int num) {
        assert (num > 0);
        if (num == 1) return true;
        
        int min = 1;
        int max = std::min(num / 2, 46340); // 46340 is the largest sqrt possible for int32_t
        
        while (min <= max) {
            int mid = min + (max - min) / 2;
            int res = mid * mid;
            if (res < num) {
                min = mid + 1;
            } else if (res > num){
                max = mid - 1;
            } else {
                return true;
            }
        }
        
        return false;
    }
};
