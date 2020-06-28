// Time complexity: O(numRows^2)
// Space complexity: O(numRows^2)

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (auto i = 0; i < numRows; ++i) {
            vector<int> row{1};
            for (auto j = 1; j < i; ++j) {
                row.push_back(triangle[i - 1][j - 1] + triangle[i - 1][j]);
            }
            if (i > 0) {
                row.push_back(1);
            }
            triangle.push_back(row);
        }
        
        return triangle;
    }
};
