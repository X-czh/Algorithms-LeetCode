class Solution {
    public int[][] generateMatrix(int n) {
        assert(n > 0);
        int[][] matrix = new int[n][n];
        
        int num = 1;
        int i = 0;
        int j = -1;
        int step = 1;
        for (int level = n; level > 0; level--) {
            for (int k = 0; k < level; k++) {
                j += step;
                matrix[i][j] = num++;
            }
            for (int k = 1; k < level; k++) {
                i += step;
                matrix[i][j] = num++;
            }
            step *= -1;
        }
        
        return matrix;
    }
}