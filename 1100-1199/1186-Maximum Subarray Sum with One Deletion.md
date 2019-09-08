# 1186-Maximum Subarray Sum with One Deletion

[Problem](https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/)

## Approach 1: Dynamic Programming

The problem differs from [053-Maximum Subarray](../000-099/053-Maximum%21Subarray.md) in that deletion of at most 1 element is allowed here (but the subarray must have at least one element left). The problem can be divided into two parts: does not delete element, and delete 1 element. The first part degrades to 053, and we can solve it easily in O(n) time. For the second part, we just iterate the whole array, each time mark an element (say A[i]) as deleted, and compute the maximum subarray sum that ends at A[i - 1] (say front_sum[i]) and that starts at A[i + 1] (say back_sum[i]). Then the maximum subarray sum with one deletion at A[i] is front_sum[i] + back_sum[i]. Then we simply combine the two parts together and return the max sum.

```c++
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        const int N = arr.size();
        
        int max_sum = arr[0];
        
        vector<int> front_sum(N);
        front_sum[0] = arr[0];
        for (int i = 1; i < N; i++) {
            front_sum[i] = max(arr[i], front_sum[i - 1] + arr[i]);
            max_sum = max(front_sum[i], max_sum);
        }
        
        vector<int> back_sum(N);
        back_sum[N - 1] = arr[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            back_sum[i] = max(arr[i], back_sum[i + 1] + arr[i]);
        }
        
        for (int i = 1; i <= N - 2; ++i) {
            max_sum = max(front_sum[i - 1] + back_sum[i + 1], max_sum);
        }
        
        return max_sum;
    }
};
```
