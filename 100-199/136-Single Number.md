# 136-Single Number

[Problem](https://leetcode.com/problems/single-number/)

## Approach 1: Hash Table

Time complexity: O(n).

Space complexity: O(n).

```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto num : nums) {
            if (m.find(num) == m.end()) {
                m.insert({num, 1});
            } else {
                m[num]++;
            }
        }

        int output = 0;
        for (const auto& p : m) {
            if (p.second == 1) {
                output = p.first;
                break;
            }
        }
        return output;
    }
};
```

## Approach 2: Bit Manipulation

Utilize XOR(^). 0^a = a, a^0 = a, a^a = 0. So, a^a^b = b.

Time complexity: O(n).

Space complexity: O(1).

```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result {0};
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }
};
```
