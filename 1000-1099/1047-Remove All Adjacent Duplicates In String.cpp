// Stack
// Time complexity: O(n).
// Space complexity: O(n).

class Solution {
public:
    string removeDuplicates(string S) {
        string res;
        for (auto c : S) {
            if (res.empty() || res.back() != c) {
                res.push_back(c);
            } else {
                res.pop_back();
            }
        }
        return res;
    }
};
