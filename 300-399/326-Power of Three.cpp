// Time complexity: O(log_3(n))
// Space complexity: O(1) (by tail call optimization)

class Solution1 {
public:
    bool isPowerOfThree(int n) {
        if (n == 1) return true;
        if (n < 1 || n % 3 > 0) return false;
        
        return isPowerOfThree(n / 3);
    }
};

// Another interesting solution

// n is 32-bit signed int. 
// Knowing the limitation of n, we can now deduce that the maximum value of n 
//    that is also a power of three is 116226146 = 3^19.
// All of its factors are power of three.

class Solution2 {
public:
    bool isPowerOfThree(int32_t n) {
        return n > 0 && 1162261467 % n == 0;
    }
};
