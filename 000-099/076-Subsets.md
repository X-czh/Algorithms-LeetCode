# 076-Subsets

[Problem](https://leetcode.com/problems/subsets/)

## Approach

Recursive structure: to compute subset(nums[begin..end]), you just need to compute subset(nums[begin..end-1]) first, then duplicate them and insert nums[end] into each of the duplicates.

Time complexity : O(N * 2^N).

### Recursive

Space complexity: O(N) extra space.

```c++
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        subsetsRec(nums, nums.size() - 1, res);
        return res;
    }
private:
    void subsetsRec(vector<int>& nums, int end, vector<vector<int>>& res) {
        if (end == -1) {
            res.push_back({});
            return;
        }

        subsetsRec(nums, end - 1, res);
        int n = res.size();
        for (int i = 0; i < n; i++) {
            res.push_back(res[i]);
            res.back().push_back(nums[end]);
        }
    }
};
```

### Iterative

Space complexity: O(1) extra space.

```c++
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        for (int num : nums) {
            int n = res.size();
            for (int i = 0; i < n; i++) {
                res.push_back(res[i]);
                res.back().push_back(num);
            }
        }
        return res;
    }
};
```
