// Time complexity: O(s.length).
// Space complexity: O(1) auxiliary space.

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left <= right) {
            if (s[left] != s[right])
                return isPalindromeRange(s, left + 1, right) ||
                    isPalindromeRange(s, left, right - 1);
            left++;
            right--;
        }

        return true;
    }
private:
    bool isPalindromeRange(const string& s, int left, int right) {
        while (left <= right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};
