# 005-Longest Palindromic Substring

[Problem](https://leetcode.com/problems/longest-palindromic-substring/)

## Approach 1: Brute Force

Pick all possible starting and ending positions for a substring (O(N^2)), and verify if it is a palindrome (O(N)).

Time complexity: O(N^3).

Space complexity: O(1).

```c++
class Solution {
public:
    string longestPalindrome(string s) {
        int start_idx = 0;
        int max_len = 0;

        for (auto i = 0; i < s.size(); ++i) {
            for (auto j = i; j < s.size(); ++j) {
                if (isPalindrome(s, i, j) && j - i + 1 > max_len) {
                    start_idx = i;
                    max_len = j - i + 1;
                }
            }
        }

        return s.substr(start_idx, max_len);
    }
private:
    bool isPalindrome(const string& s, int begin, int end) {
        int len = end - begin + 1;
        for (int i = 0; i < len / 2; i++) {
            if (s[begin + i] != s[end - i])
                return false;
        }
        return true;
    }
};
```

## Approach 2: Dynamic Programming

Let P(i, j) to be the indicator of whether the substring from index i to j is a palindrome.

Observe the recurrence structure to determine P(i, j):

1. Base Case: P(i, i) = true, P(i, i + 1) = s[i] == s[i + 1].

2. Recursive Step: P(i, j) == P(i + 1, j - 1) && s[i] == s[j].

Time complexity: O(N^2).

Space complexity: O(N^2).

```c++
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";

        int start_idx = 0;
        int len = 1;
        const int n = s.size();

        // Note: vector<bool> saves space, but is much slower than vector<int>!
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n - 1; i++) {
            dp[i][i] = true;
            dp[i][i + 1] = (s[i] == s[i + 1]);
            if (dp[i][i + 1]) {
                start_idx = i;
                len = 2;
            }
        }
        dp[n - 1][n - 1] = true;

        // The order of iteration is important, need to make sure dp[i + 1][j - 1] is computed before computing dp[i][j]
        // Here: the outer loop iterates length from 3 to n
        // Alternative: the outer loop iterates starting idx i from n - 3 down to 0
        for (int l = 3; l <= n; l++) {
            for (int i = 0; i < n - l + 1; i++) {
                int j = i + l - 1;
                dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
                if (dp[i][j]) {
                    start_idx = i;
                    len = l;
                }
            }
        }

        return s.substr(start_idx, len);
    }
};
```

## Approach 3: Expand Around Center

Observe that a palindrome mirrors around its center. Therefore, a palindrome can be expanded from its center, and there are only 2n - 1 such centers.

Time complexity: O(N^2).

Space complexity: O(1).

```c++
class Solution {
public:
    string longestPalindrome(string s) {
        int start_idx = 0;
        int max_len = 0;

        for (auto i = 0; i < s.size(); ++i) {
            int half_len;

            // length is odd
            half_len = 1;
            while (i - half_len > -1 && i + half_len < s.size() &&
                   s[i - half_len] == s[i + half_len]) {
                ++half_len;
            }
            --half_len;
            if (int len = half_len * 2 + 1; len > max_len) {
                start_idx = i - half_len;
                max_len = len;
            }

            // length is even
            half_len = 1;
            while (i - half_len + 1 > -1 && i + half_len < s.size() &&
                   s[i - half_len + 1] == s[i + half_len]) {
                ++half_len;
            }
            --half_len;
            if (int len = half_len * 2; len > max_len) {
                start_idx = i - half_len + 1;
                max_len = len;
            }
        }

        return s.substr(start_idx, max_len);
    }
};
```
