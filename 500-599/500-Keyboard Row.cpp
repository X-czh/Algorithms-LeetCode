// Time complexity: O(N) (N is total number of chars).
// Space complexity: O(1) auxiliary space.

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int> dict(26);
        string row0 = "qwertyuiop";
        string row1 = "asdfghjkl";
        string row2 = "zxcvbnm";
        for (auto c : row0) {
            dict[c - 'a'] = 0;
        }
        for (auto c : row1) {
            dict[c - 'a'] = 1;
        }
        for (auto c : row2) {
            dict[c - 'a'] = 2;
        }
        
        vector<string> result;
        for (auto& word : words) {
            bool flag = true;
            int row = dict[tolower(word[0]) - 'a'];
            for (auto c : word) {
                if (dict[tolower(c) - 'a'] != row) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                result.push_back(word);
            }
        }
        return result;
    }
};
