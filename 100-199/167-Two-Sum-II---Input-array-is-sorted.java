class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int sum;
        int left = 0;
        int right = numbers.length - 1;
        
        while (left < right) {
            sum = numbers[left] + numbers[right]; 
            if (sum == target)
                return new int[] {left + 1, right + 1};
            else if (sum > target)
                right--;
            else
                left++;
        }
        
        throw new IllegalArgumentException("No two sum solution");
    }
}