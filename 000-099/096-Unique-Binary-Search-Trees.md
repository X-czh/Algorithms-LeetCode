# 096-Unique Binary Search Trees

[Problem](https://leetcode.com/problems/unique-binary-search-trees/)

## Algorithm: Dynamic Programming

To construct a binary search tree with numbers 1 ... n, first select a number x to be the root, then construct the left child tree with numbers 1 ... x-1 and the right child tree with numbers x+1 ... n. Note that the unique binary search trees constructed with x+1 ... n are as many as those constructed with 1 ... n-x. Let C(x) denote the number of unique binary search trees constructed with 1 ... x, we have C(x) = C(0)C(n) \* C(1)C(n - 1) \* ... \* C(n - 1)C(1) \* C(n)C(0) (Catalan Number!).

Time complexity: O(n^2).

Space complexity: O(n).

```c++
// Time complexity: O(1/2 n(n+1)).
class Solution1 {
public:
    int numTrees(int n) {
        vector<int> mem(n + 1, 1);

        for (int i{1}; i <= n; ++i){
            int num{0};
            for (int j{1}; j <= i; ++j) {
                num += mem[j - 1] * mem[i - j];
            }
            mem[i] = num;
        }

        return mem[n];
    }
};

// An optimized solution
// Time complexity: O(1/4 n(n+1)).
class Solution2 {
public:
    int numTrees(int n) {
        vector<int> mem(n + 1, 1);

        for (int i{1}; i <= n; ++i){
            int num{0};
            for (int j{1}; j < i / 2 + 1; ++j) {
                num += mem[j - 1] * mem[i - j];
            }
            num *= 2;
            if (i % 2 != 0) {
                num += mem[i / 2] * mem[i / 2];
            }
            mem[i] = num;
        }

        return mem[n];
    }
};
```
