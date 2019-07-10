// Time complexity: O(n^2)
// Space complexity: O(n)

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);

        for (auto i = 1; i < rowIndex + 1; ++i) {
            for (auto j = i - 1; j > 0; --j) {
                row[j] += row[j - 1]; // Key: backward processing for memory saving
            }
        }
        
        return row;
    }
};
