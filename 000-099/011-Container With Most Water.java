class Solution {
    public int maxArea(int[] height) {
        if (height == null || height.length < 2)
            return -1;
        
        int left = 0, right = height.length - 1;
        int maxArea = (right - left) * Math.min(height[left], height[right]);
        while (left < right) {
            maxArea = Math.max(maxArea, (right - left) * Math.min(height[left], height[right]));
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxArea;
    }
}