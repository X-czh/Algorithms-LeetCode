class Solution {
    public void rotate(int[][] matrix) {
        if (matrix == null)
            return;
        
        int n = matrix.length;
        
        for (int i = 0; i < n / 2; i++) { // ith ring
            for (int j = 0; j < n - 1 - 2 * i; j++) { // jth element on the ring
                
                // save top
                int tmp = matrix[i][i + j];
                
                // left to top
                matrix[i][i + j] = matrix[n - 1 - i - j][i];
                
                // bottom to left
                matrix[n - 1 - i - j][i] = matrix[n - 1 - i][n - 1 - i - j];
                
                // right to bottom
                matrix[n - 1 - i][n - 1 - i - j] = matrix[i + j][n - 1 - i];
                
                // top to right
                matrix[i + j][n - 1 - i] = tmp;
                
            }
        }
    }
}