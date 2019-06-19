class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> lst = new ArrayList<Integer>();
        int m = matrix.length;
        int n = 0;
        if (m > 0)
            n = matrix[0].length;
        if (m * n == 0) // empty matrix
            return lst;
        
        int i = 0;
        int j = -1;
        int step = 1;
        
        while (m > 0 && n > 0) {
            for (int k = 0; k < n; k++) {
                j += step;
                lst.add(matrix[i][j]);
            }
            for (int k = 1; k < m; k++) {
                i += step;
                lst.add(matrix[i][j]);
            }
            n--;
            m--;
            step *= -1;
        }
        
        return lst;
    }
}