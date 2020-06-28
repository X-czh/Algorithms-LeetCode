// Time complexity: O(n).
// Space complexity: O(1).

class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> m{{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        for (int l = 0, r = num.size() - 1; l <= r; l++, r--) {
            if (m.find(num[l]) == m.end() || m[num[l]] != num[r]) {
                return false;
            }
        }
        return true;
    }
};
