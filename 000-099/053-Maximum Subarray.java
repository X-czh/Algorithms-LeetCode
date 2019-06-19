class Solution {
    public int maxSubArray(int[] nums) {
        if (nums == null)
            return -1;
        
        int maxSum = Integer.MIN_VALUE, currentSum = Integer.MIN_VALUE;
        for (int num: nums) {
            currentSum = (currentSum < 0) ? num : currentSum + num;
            maxSum = (maxSum < currentSum) ? currentSum : maxSum;
        }
        return maxSum;
    }
}