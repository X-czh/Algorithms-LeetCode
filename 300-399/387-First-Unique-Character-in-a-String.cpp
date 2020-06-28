// Time complexity: O(n).
// Space complexity: O(n) extra space.

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> occurrences;
        for (auto ch : s) {
            occurrences[ch]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (occurrences[s[i]] == 1)
                return i;
        }
        return -1;
    }
};
