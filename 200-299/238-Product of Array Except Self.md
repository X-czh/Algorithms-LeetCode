# 238-Product of Array Except Self

[Problem](https://leetcode.com/problems/product-of-array-except-self/)

## Approach 1: Left and right product lists

Compute two lists, left_prod and right_prod. right_prod[i] is the cumulative product computed from the rightmost element to the i-th element. left_prod[i] is the cumulative product computed from the leftmost element to the i-th element. The "Product of Array Except Self" now follows.

Time complexity: O(n).

Extra space complexity: O(n).

```c++
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        auto n = nums.size();
        assert(n > 1);

        vector<int> left_prod(n);
        vector<int> right_prod(n);
        vector<int> output(n);

        // calculate cumulative product from the right side
        right_prod[n - 1] = nums[n - 1];
        for (auto i = n - 2; i > 0; --i) {
            right_prod[i] = nums[i] * right_prod[i + 1];
        }

        // calculate cumulative product from the left side
        left_prod[0] = nums[0];
        for (auto i = 1; i < n - 1; ++i) {
            left_prod[i] = nums[i] * left_prod[i - 1];
        }

        // calculate product of array except self
        output[0] = right_prod[1];
        for (auto i = 1; i < n - 1; ++i) {
            output[i] = left_prod[i - 1] * right_prod[i + 1];
        }
        output[n - 1] = left_prod[n - 2];

        return output;
    }
};
```

## Approach 2: No extra space used

We can eliminate the extra space used in approach 1 by computing right_prod in place in the output list and computing left_prod in place iteratively. The key is that after we have computed output[i], all right_prod[j] (j <= i + 1) and left_prod[k] (k <= i - 1) are no longer needed.

Time complexity: O(n).

Extra space complexity: O(1).

```c++
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        auto n = nums.size();
        assert(n > 1);

        vector<int> output(n);

        // calculate cumulative product from the right side
        output[n - 1] = nums[n - 1];
        for (auto i = n - 2; i > 0; --i) {
            output[i] = nums[i] * output[i + 1];
        }

        // holds cumulative product from the right side
        int left_prod = nums[0];

        // calculate product of array except self
        output[0] = output[1];
        for (auto i = 1; i < n - 1; ++i) {
            output[i] = left_prod * output[i + 1];
            left_prod *= nums[i];
        }
        output[n - 1] = left_prod;

        return output;
    }
};
```
