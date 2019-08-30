# 389-Find the Difference

[Problem](https://leetcode.com/problems/find-the-difference/)

## Approach 1: Hash Map

Time complexity: O(n + m).

Space complexity: O(n + m) extra space.

### First Attempt

```c++
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> m;

        for (char ch : s) {
            if (m.find(ch) != m.end()) {
                ++m[ch];
            } else {
                m.insert({ch, 1});
            }
        }

        for (char ch : t) {
            if (m.find(ch) != m.end()) {
                --m[ch];
                if (m[ch] == -1) {
                    return ch;
                }
            } else {
                return ch;
            }
        }

        return 'w';
    }
};
```

### Better Solution

*Take away:* [] operator of map<K, T> inserts value_type(key, T{}) if such key does not exist.

```c++
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> m;
        for (char ch : s) ++m[ch];
        for (char ch : t) {
            if (--m[ch] < 0) return ch;
        }
        return 0;
    }
};
```

## Approach 2: Bit Manipulation

a ^ a = 0, 0 ^ a = a.

Time complexity: O(n + m).

Space complexity: O(1) extra space.

```c++
class Solution {
public:
    char findTheDifference(string s, string t) {
        char c = 0;
        for (char ch : s) c ^= ch;
        for (char ch : t) c ^= ch;
        return c;
    }
};
```
