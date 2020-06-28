class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        // corner case
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0)
            return false;
        
        // start searching at the top-right corner
        int m = matrix.length, n = matrix[0].length;
        int r = 0, c = n - 1;
        while (r <= m - 1 && c >= 0) {
            if (target > matrix[r][c])
                r++;
            else if (target < matrix[r][c])
                c--;
            else
                return true;
        }
        return false;
    }
}