# 137-Single Number II

[Problem](https://leetcode.com/problems/single-number-ii/)

## Approach 1: Hash Table

Time complexity: O(n).

Space complexity: O(n).

```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int num : nums) {
            m[num]++;
        }

        for (auto& p : m) {
            if (p.second == 1) {
                return p.first;
            }
        }
        return -1;
    }
};
```

## Approach 2: Bit Manipulation

To separate number that appears once from a number that appears three times let's use two bitmasks instead of one: seen_once and seen_twice.

The idea is to

* change seen_once only if seen_twice is unchanged

* change seen_twice only if seen_once is unchanged

Time complexity: O(n).

Space complexity: O(1).

```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int seenOnce = 0, seenTwice = 0;

        for (int num : nums) {
            seenOnce = ~seenTwice & (seenOnce ^ num);
            seenTwice = ~seenOnce & (seenTwice ^ num);
        }

        return seenOnce;
    }
};
```
