// Time complexity: O(n!)
// Space complexity: O(n)

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> config(n, 0);
        placeQueen(result, config, 0, n);
        return result;
    }
private:
    void placeQueen(vector<vector<string>>& result, vector<int>& config, int r, int n) {
        if (r == n) {
            vector<string> config_str;
            for (auto queen_col : config) {
                string str(n, '.');
                str[queen_col] = 'Q';
                config_str.push_back(str);
            }
            result.push_back(config_str);
        } else {
            for (auto j = 0; j < n; ++j) {
                bool legal = true;
                for (auto i = 0; i < r; ++i) {
                    if (config[i] == j ||
                        config[i] + (r - i) == j ||
                        config[i] - (r - i) == j) {
                        legal = false;
                        break;
                    }
                }
                if (legal) {
                    config[r] = j;
                    placeQueen(result, config, r + 1, n);
                }
            }
        }
    } 
};
