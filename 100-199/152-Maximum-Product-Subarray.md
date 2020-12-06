# 152-Maximum Product Subarray

[Problem](https://leetcode.com/problems/maximum-product-subarray/)

## Approach 1: Dynamic Programming

Time complexity: O(n).

Space complexity: O(n).

```c++
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        auto N = nums.size();
        assert(N > 0);

        int max_product = 0;
        vector<int> mem_max{nums};
        vector<int> mem_min{nums};

        for (auto i = 1; i < N; ++i) {
            int product_1 = mem_max[i - 1] * nums[i];
            int product_2 = mem_min[i - 1] * nums[i];
            int max_product = max(product_1, product_2);
            int min_product = min(product_1, product_2);
            if (max_product > mem_max[i]) {
                mem_max[i] = max_product;
            }
            if (min_product < mem_min[i]) {
                mem_min[i] = min_product;
            }
        }

        return *max_element(mem_max.begin(), mem_max.end());
    }
};
```
