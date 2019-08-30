// Time complexity: O(n).
// Space complexity: O(1) extra space.

class Solution {
public:
    bool isPalindrome(string s) {
        int cnt_alnum = 0;
        for (char ch : s) {
            if (isalnum(ch)) cnt_alnum++;
        }
        
        int forward = 0;
        int backward = s.size() - 1;
        for (int i = 0; i < cnt_alnum / 2; ++i, ++forward, --backward) {
            while (!isalnum(s[forward])) ++forward;
            while (!isalnum(s[backward])) --backward;
            if (tolower(s[forward]) != tolower(s[backward])) {
               return false;
            }
        }
        return true;
    }
};
