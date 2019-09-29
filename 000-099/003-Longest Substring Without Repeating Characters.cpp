// Sliding Window

// Time complexity: O(N).
// Extra space complexity: O(N).

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> lookup;
        int max_len = 0;
        int left = 0;
        int right = 0;
        while (right < s.size()) {
            if (lookup.find(s[right]) == lookup.end()) {
                lookup.insert(s[right]);
            } else {
                while (s[left] != s[right]) {
                    lookup.erase(s[left]);
                    ++left;
                }
                ++left;
            }
            ++right;
            max_len = max(right - left, max_len);
        }
        return max_len;
    }
};
