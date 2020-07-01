// Time complexity: O(n).
// Space complexity: O(1).

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        const int NS = s.size();
        const int NT = t.size();
        
        if (NS > NT) {
            return isOneEditDistance(t, s);
        }
        
        if (NS - NT > 1) {
            return false;
        }
        
        for (int i = 0; i < NS; i++) {
            if (s[i] != t[i]) {
                if (NS == NT) {
                    return s.substr(i + 1) == t.substr(i + 1);
                } else {
                    return s.substr(i) == t.substr(i + 1);
                }
            }
        }

        // If there is no diffs on ns distance
        // the strings are one edit away only if
        // t has one more character.
        return (NS + 1 == NT);
    }
};
