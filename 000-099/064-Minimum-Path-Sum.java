class Solution {
    public int minPathSum(int[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length == 0)
            return -1;
        
        int m = grid.length;
        int n = grid[0].length;
        int[][] grid_mem = new int[m][n];
        grid_mem[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            grid_mem[i][0] = grid_mem[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            grid_mem[0][j] = grid_mem[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid_mem[i][j - 1] < grid_mem[i - 1][j])
                    grid_mem[i][j] = grid_mem[i][j - 1] + grid[i][j];
                else
                    grid_mem[i][j] = grid_mem[i - 1][j] + grid[i][j];
            }
        }
        
        return grid_mem[m - 1][n - 1];
    }
}