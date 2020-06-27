// Time complexity: O(n).
// Space complexity: O(1). Depends on the size of character set, but it is a constant.

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;
        for (auto c : s) {
            m[c]++;
        }
        int cnt_of_odds = 0;
        for (auto p : m) {
            if (m[p.first] % 2 == 1) {
                cnt_of_odds++;
            }
        }
        return cnt_of_odds <= 1;
    }
};
