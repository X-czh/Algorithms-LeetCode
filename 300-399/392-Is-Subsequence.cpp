// Time complexity: O(t.size()).
// Space complexity: O(1) extra space.

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (auto ch : s) {
            while (i < t.size() && t[i] != ch) {
                ++i;
            }
            if (i == t.size()) {
                return false; // ch not found in t subsequently
            } else {
                ++i; // ch found, move to next one for future searching
            }
        }
        
        return true;
    }
};
