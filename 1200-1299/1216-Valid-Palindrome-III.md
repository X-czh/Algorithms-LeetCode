# 1216-Valid Palindrome III

[Problem](https://leetcode.com/problems/valid-palindrome-iii/)

A string is K-Palindrome if it can be transformed into a palindrome by removing at most k characters from it.

## Approach 1: Recursion: Reduce K-Palindrome to (K-1)-Palindrome (Time Limit Exceeded)

Time complexity: O(2^k * n), k <= n.

Space complexity: O(2^k) extra space.

```c++
class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int left = 0;
        int right = s.size() - 1;
        return isPalindromeRange(s, left, right, k);
    }
private:
    bool isPalindromeRange(const string& s, int left, int right, int k) {
        while (left <= right) {
            if (s[left] != s[right]) {
                return (k < 1) ? false :
                    isPalindromeRange(s, left + 1, right, k - 1) ||
                    isPalindromeRange(s, left, right - 1, k - 1);
            }
            left++;
            right--;
        }
        return true;
    }
};
```

## Approach 2: Dynamic Programming

The problem differs from [053-Maximum Subarray](../000-099/053-Maximum%20Subarray.md) in that deletion of at most 1 element is allowed here (but the subarray must have at least one element left). The problem can be divided into two parts: does not delete element, and delete 1 element. The first part degrades to 053, and we can solve it easily in O(n) time. For the second part, we just iterate the whole array, each time mark an element (say A[i]) as deleted, and compute the maximum subarray sum that ends at A[i - 1] (say front_sum[i]) and that starts at A[i + 1] (say back_sum[i]). Then the maximum subarray sum with one deletion at A[i] is front_sum[i] + back_sum[i]. Then we simply combine the two parts together and return the max sum.
