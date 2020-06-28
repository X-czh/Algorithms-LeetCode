// Time complexity: O(logn)
// Space complexity: O(1)

class Solution {
public:
    bool isPalindrome(int x) {
        // if x is neg or x ends with 0 but is not 0, it can't be palindrome
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int rev = 0;
        while(x > rev) { // terminates when rev has more digits than x
            rev = rev * 10 + x % 10;
            x /= 10;
        }

        return x == rev       // if the palindrome number has even number of digits
            || x == rev / 10; // if the palindrome number has odd number of digits
    }
};
