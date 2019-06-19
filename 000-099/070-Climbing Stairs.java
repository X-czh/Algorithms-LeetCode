/** 
 * Climbing Stairs
 * - Fibonacci Number problem
 * - Also a Dynamic Programming problem
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
class Solution {
    public int climbStairs(int n) {
        // n should be positive
        if (n < 1)
            return -1;
        
        // base case
        if (n == 1)
            return 1;
        
        // num_ways[i] = num_ways[i-1] + num_ways[i-2]
        int result = 2;
        int prev_one_step = 2, prev_two_step = 1;
        for (int i = 2; i < n; i++) {
            result = prev_one_step + prev_two_step;
            prev_two_step = prev_one_step;
            prev_one_step = result;
        }
        return result;
    }
}