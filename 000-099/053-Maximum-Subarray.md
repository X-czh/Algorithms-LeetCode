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

## Approach 2: Divide and Conquer

Base Case: array size = 1, return the value of the single element

Divide and Conquer: compute max subarray sum for the left/right half of the array (left_sum and right_sum) recursively, compute cross_sum = maximum sum of the subarray containing elements from both left and right subarrays and hence crossing the middle element at index (left + right) / 2; the answer is max(left_sum, right_sum, cross_sum).

Time complexity: O(nlogn).

Space complexity: O(logn) extra space.

```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
private:
    int helper(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }

        int mid = left + (right - left) / 2;
        int left_sum = helper(nums, left, mid);
        int right_sum = helper(nums, mid + 1, right);
        int cross_sum = compute_cross_sum(nums, left, right, mid);

        return max(max(left_sum, right_sum), cross_sum);
    }

    int compute_cross_sum(vector<int>& nums, int left, int right, int mid) {
        int left_sum = 0;
        int max_left_sum = nums[mid];
        for (int i = mid; i >= left; i--) {
            left_sum += nums[i];
            max_left_sum = max(max_left_sum, left_sum);
        }
        int right_sum = 0;
        int max_right_sum = numeric_limits<int>::min();
        for (int i = mid + 1; i <= right; i++) {
            right_sum += nums[i];
            max_right_sum = max(max_right_sum, right_sum);
        }
        return max_left_sum + max_right_sum;
    }
};
```
