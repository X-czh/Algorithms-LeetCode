// Time complexity: O(n), n = #chars in strings.
// Space complexity: O(n).

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> m;
        for (const auto& str : strings)
            m[shift(str)].push_back(str);

        vector<vector<string>> groups;
        for (auto p : m) {
            groups.push_back(p.second);
        }
        return groups;
    }
private:
    string shift(const string& str) {
        string res;
        char c = str[0];
        for (int i = 1; i < str.length(); i++) {
            int diff = str[i] - c;
            if (diff < 0) diff += 26;
            res += 'a' + diff;
        }
        return res;
    }
};
