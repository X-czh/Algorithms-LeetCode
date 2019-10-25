// Time complexity: O(M*N).
// Space complexity: O(M*N) extra space due to recursion.

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        
        int max_area = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1) {
                    int area = dfs(i, j, grid);
                    max_area = max(area, max_area);
                }
            }
        }
        return max_area;
    }
private:
    int dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || 
                grid[i][j] == 0) {
            return 0;
        }
        
        int area = 1;
        grid[i][j] = 0;
        area += dfs(i - 1, j, grid);
        area += dfs(i + 1, j, grid);
        area += dfs(i, j - 1, grid);
        area += dfs(i, j + 1, grid);
        return area;
    }
};
