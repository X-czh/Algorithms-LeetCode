// Time complexity: O(n!)
// Space complexity: O(n)

class Solution {
public:
    int totalNQueens(int n) {
        vector<int> config(n, 0);
        return placeQueen(config, 0, n);
    }
private:
    int placeQueen(vector<int>& config, int r, int n) {
        int result = 0;
        
        if (r == n) {
            result = 1;
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
                    result += placeQueen(config, r + 1, n);
                }
            }
        }

        return result;
    }
};
