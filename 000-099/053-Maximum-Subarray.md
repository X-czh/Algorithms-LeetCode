# 053-Maximum Subarray

## Approach 1: Dynamic Programming (Kadane’s Algorithm)

Let A[0..L] denote an array.

We approach the problem by first finding out the maximum sum of any contiguous subarray that ends at A[i] for each i in 0..L. Denote that maximum sum Sum[i]. We can derive Sum[i] from Sum[i - 1] as follows: Sum[i] = max(Sum[i - 1] + A[i], A[i]). The base case, Sum[0] = A[0]. The maximum subarray sum is then the maximum of all Sum[i]s.

Time complexity: O(n).

Space complexity: O(1) extra space.

```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum = nums[0];
        int max_sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            curr_sum = (curr_sum < 0) ? nums[i] : curr_sum + nums[i];
                // or curr_sum = max(nums[i], curr_sum + nums[i]);
            max_sum = max(curr_sum, max_sum);
        }
        return max_sum;
    }
};
```
