// Time complexity: O(n).
// Space complexity: O(1) extra space (at most 26 letters).

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        
        for (char ch : magazine) ++m[ch];
        for (char ch : ransomNote) {
            if (--m[ch] < 0) {
                return false;
            }
        }
        
        return true;
    }
};
