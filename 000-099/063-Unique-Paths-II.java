class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if (obstacleGrid == null)
            return -1;
        
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        int[][] num_paths_mem = new int[m][n];
        
        for (int i = 0, num_paths = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 1)
                num_paths = 0;
            num_paths_mem[i][0] = num_paths;
        }
        for (int j = 0, num_paths = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 1)
                num_paths = 0;
            num_paths_mem[0][j] = num_paths;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0)
                    num_paths_mem[i][j] = num_paths_mem[i - 1][j] + 
                        num_paths_mem[i][j - 1];
                else
                    num_paths_mem[i][j] = 0;
            }
        }
        
        return num_paths_mem[m - 1][n - 1];
    }
}