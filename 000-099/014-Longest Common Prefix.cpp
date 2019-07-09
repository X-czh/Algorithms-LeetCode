// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty() || strs[0].empty()) return "";
        
        for (auto i = 0; i < strs[0].size(); ++i) {
            char c = strs[0][i];
            for (auto j = 1; j < strs.size(); ++j) {
                if (i == strs[j].size() || strs[j][i] != c)
                    return strs[0].substr(0, i);             
            }
        }
        
        return strs[0]; // when strs.size() == 1
    }
};
