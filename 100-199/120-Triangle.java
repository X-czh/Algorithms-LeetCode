class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        if (triangle == null || triangle.get(0) == null || 
            triangle.get(0).size() == 0)
            return -1;
        
        int size = triangle.size();
        int[] triangle_mem = new int[size];
        triangle_mem[0] = triangle.get(0).get(0);
        for (int i = 1; i < size; i++) {
            List<Integer> row = triangle.get(i);
            triangle_mem[i] = triangle_mem[i - 1] + row.get(i);
            for (int j = i - 1; j > 0; j--) {
                if (triangle_mem[j - 1] > triangle_mem[j])
                    triangle_mem[j] = triangle_mem[j] + row.get(j);
                else
                    triangle_mem[j] = triangle_mem[j - 1] + row.get(j);
            }
            triangle_mem[0] += row.get(0);
        }
        
        int min = triangle_mem[0];
        for (int i = 1; i < size; i++) {
            if (triangle_mem[i] < min)
                min = triangle_mem[i];
        }
        
        return min;
    }
}