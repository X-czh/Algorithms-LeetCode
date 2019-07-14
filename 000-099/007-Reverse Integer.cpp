class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > numeric_limits<int>::max() / 10 || 
                (rev == numeric_limits<int>::max() / 10 && pop > 7)) return 0;
            if (rev < numeric_limits<int>::min() / 10 || 
                (rev == numeric_limits<int>::min() / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
