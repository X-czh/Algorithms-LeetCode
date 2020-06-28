// Time complexity: O(n + m).
// Space complexity: O(n).

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> s;
        for (auto c : J) {
            s.insert(c);
        }
        
        int num = 0;
        for (auto c : S) {
            if (s.find(c) != s.end()) {
                num++;
            }
        }
        return num;
    }
};
