# 300-Longest Increasing Subsequence

[Problem](https://leetcode.com/problems/longest-increasing-subsequence/)

## Approach 1: Recursion, Take 1

Idea: find all increasing subsequences and then returning the maximum length of longest increasing subsequence. In order to do this, we make use of a recursive function lengthofLISHelper(nums, prev, curr) which returns the max length of the LIS possible from the current element onwards (inclusive), with each element larger than prev.

Recursive structure of lengthOfLISHelper(nums, int prev, int curr):

* Base Case: if curr == n, return 0.
* Recursive Step:
  * The current element <= the previous element included in the LIS. In this case, we can't include the current element in the LIS. So we skip the current element and return lengthOfLISHelper(nums, prev, curr + 1);
  * The current element > the previous element included in the LIS. In this case, we can choose whether or not to include the current element in the LIS. So return max(lengthOfLISHelper(nums, prev, curr + 1), lengthOfLISHelper(nums, nums[curr], curr + 1) + 1);

### Naive Recursion

Time complexity: T(n) = 2T(n - 1) + O(1) = O(2^n), same as that of computing Fibonacci number.

Space complexity: O(2^n).

```c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return lengthOfLISHelper(nums, numeric_limits<int>::min(), 0);
    }
private:
    int lengthOfLISHelper(vector<int>& nums, int prev, int curr) {
        if (curr == nums.size()) {
            return 0;
        } else if (prev >= nums[curr]) {
            return lengthOfLISHelper(nums, prev, curr + 1);
        } else {
            int skip = lengthOfLISHelper(nums, prev, curr + 1);
            int take = lengthOfLISHelper(nums, nums[curr], curr + 1) + 1;
            return max(skip, take);
        }
    }
};
```

## Memoization

We are doing a lot of redundant computation before. We first reformulate the recursive structure a bit by using the index of the previous element in the subsequence intead of its value:

* lengthOfLISHelper(prev, curr) = 0, if curr = n;
* lengthOfLISHelper(prev, curr) = lengthOfLISHelper(prev, curr + 1), if curr < n and nums[prev] > nums[curr];
* lengthOfLISHelper(prev, curr) = max(lengthOfLISHelper(prev, curr + 1), lengthOfLISHelper(curr, curr + 1) + 1), otherwise.

This redundancy can be eliminated by storing the results obtained for a particular call in a 2-d memoization array mem. mem[i][j] represents the length of the longest increasing subsequence of nums[j .. n] in which every element is larger than nums[i]. Note that we'll need to add a dummy minus infinity number as nums[-1]. to simplify the implementation, we'll let mem[i][j] represents the length of the longest increasing subsequence of nums[j .. n] in which every element is larger than nums[i - 1].

Time complexity: O(n^2).

Space complexity: O(n^2).

```c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> mem(nums.size() + 1, vector<int>(nums.size(), -1));
        return lengthOfLISHelper(nums, -1, 0, mem);
    }
private:
    int lengthOfLISHelper(vector<int>& nums, int prev, int curr, vector<vector<int>>& mem) {
        if (curr == nums.size()) {
            return 0;
        };

        if (mem[prev + 1][curr] >= 0) {
            return mem[prev + 1][curr];
        }

        if (prev >= 0 && nums[prev] >= nums[curr]) {
            mem[prev + 1][curr] = lengthOfLISHelper(nums, prev, curr + 1, mem);
        } else {
            int skip = lengthOfLISHelper(nums, prev, curr + 1, mem);
            int take = lengthOfLISHelper(nums, curr, curr + 1, mem) + 1;
            mem[prev + 1][curr] = max(skip, take);
        }
        return mem[prev + 1][curr];
    }
};
```

### Dynamic Programming

Note that dp[i + 1][j] represents the length of the longest increasing subsequence of nums[j .. n] in which every element is larger than nums[i], and nums[-1] is considered as -∞.

Time complexity: O(n^2).

Space complexity: O(n^2).

```c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, 0));
        for (int j = nums.size() - 1; j >= 0; j--) {
            for (int i = -1; i < j; i++) {
                int take = 1 + dp[j + 1][j + 1];
                int skip = dp[i + 1][j + 1];
                if (i == -1 || nums[i] < nums[j]) {
                    dp[i + 1][j] = max(take, skip);
                } else {
                    dp[i + 1][j] = skip;
                }
            }
        }
        return dp[0][0];
    }
};
```

## Approach 2: Recursion, Take 2

There's an alternative recursive formulation for LIS. We make use a recursive function LISlast, where LISlast(i) computes the LIS that ends with nums[i].

Recursive structure for LISlast(i):

* LISlast(0) = 1
* LISlast(i) = 1 + max(LISlast(j) with j < i and nums[j] < nums[i])

Finally, we need to reconnect this recursive algorithm to our original problem—finding the longest increasing subsequence without knowing its last element. One natural approach that works is to try all possible last elements ments by brute force. Equivalently, we can add a sentinel element +∞ to the end of the array, find the longest increasing subsequence that starts with the sentinel, and finally ignore the sentinel.

We can also formulate it with LISfirst where LISfirst(i) computes the LIS that starts with nums[i] in a similar way.

### Naive Recursion

Let's first analyze the time complexity for LISlast. We have:

* T(1) = O(1);
* T(n) = (T(1) + ... + T(n - 1)) + O(n), n >= 2.

So T(n) = O(n x 2^n).

Finally, we need to call LSTlast n times to find max(LISlast(i) with 0 <= i < nums.length). So the final time complexity is n x O(n x 2^n) = O(n^2 x 2^n).

Space complexity: O(2^n).

```c++
class Solution1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int best = 0;
        for (int i = 0; i < nums.size(); i++) {
            best = max(best, LISlast(nums, i));
        }
        return best;
    }
private:
    int LISlast(vector<int>& nums, int end) {
        int best = 0;
        for (int i = 0; i < end; i++) {
            if (nums[i] < nums[end]) {
                best = max(best, LISlast(nums, i));
            }
        }
        return best + 1;
    }
};

// with dummy plus infinity element at the end of the array
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        return LISlast(nums, nums.size()) - 1;
    }
private:
    int LISlast(vector<int>& nums, int end) {
        int best = 0;
        for (int i = 0; i < end; i++) {
            if (end == nums.size() || nums[i] < nums[end]) {
                best = max(best, LISlast(nums, i));
            }
        }
        return best + 1;
    }
};
```

### Memoization

Time complexity: There are n distinctive subproblems, each takes O(n) to solve with memoization. So O(n^2).

Space complexity: O(n).

```c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> mem(nums.size() + 1, -1);
        return LISLast(nums, nums.size(), mem) - 1;
    }
private:
    int LISLast(vector<int>& nums, int end, vector<int>& mem) {
        int best = 0;
        for (int i = 0; i < end; i++) {
            if (end == nums.size() || nums[i] < nums[end]) {
                if (mem[i] == -1) {
                    mem[i] = LISLast(nums, i, mem);
                }
                best = max(best, mem[i]);
            }
        }
        mem[end] = best + 1;
        return mem[end];
    }
};
```

### Dynamic Programming

Time complexity: O(n^2).

Space complexity: O(n).

```c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 1);
        for (int i = 0; i <= nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (i == nums.size() || nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp.back() - 1;
    }
};
```

## Approach 3: Binary Search

Let tails be an array storing the smallest tail of all increasing subsequences with length i+1 in tails[i].
For example, say we have nums = [4,5,6,3], then all the available increasing subsequences are:

* len = 1   :      [4], [5], [6], [3]   => tails[0] = 3
* len = 2   :      [4, 5], [5, 6]       => tails[1] = 5
* len = 3   :      [4, 5, 6]            => tails[2] = 6

We can easily prove that tails is a increasing array. Therefore it is possible to do a binary search in tails array to find the one needs update.

Each time we only do one of the two:

1. if x is larger than all tails, append it, increase the size by 1.
2. if tails[i-1] < x <= tails[i], update tails[i] (because we can append x to the subseq of len i with its tail being tails[i-1] to form a new subseq of len (i + 1) with a smaller tail).

The result for LIS is just the size of tails.

Time complexity: O(nlogn).

Space complexity: O(n).

```c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = 0;
        vector<int> tails(nums.size(), 0);

        for (auto num : nums) {
            int lo = 0;
            int hi = size;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (tails[mid] < num) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }
            tails[lo] = num;
            if (lo == size) {
                ++size;
            }
        }

        return size;
    }
};
```
