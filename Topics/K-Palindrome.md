# K-Palindrome

Can a given string be transformed into a palindrome by removing at most k characters from it?

* [125-Valid Palindrome](../100-199/125-Valid-Palindrome.cpp)
* [680-Valid Palindrome II](../600-699/680-Valid-Palindrome-II.cpp).
* [1216-Valid Palindrome III](../1200-1299/1216-Valid-Palindrome-III.md).

## 0-Palindrome: Two Pointers

Time complexity: O(n).

Space complexity: O(1) auxiliary space.

```c++
bool isPalindrome(string s) { {
    int left = 0;
    int right = s.size() - 1;
    while (left <= right) {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}
```

## 1-Palindrome: Reduce to 0-Palindrome

Time complexity: O(n).

Space complexity: O(1) auxiliary space.

```c++
bool isPalindromeRange(const string& s, int left, int right) {
    while (left <= right) {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}

bool validOnePalindrome(string s) {
    int left = 0;
    int right = s.size() - 1;

    while (left <= right) {
        if (s[left] != s[right])
            return isPalindromeRange(s, left + 1, right) ||
                isPalindromeRange(s, left, right - 1);
        left++;
        right--;
    }

    return true;
}
```

## K-Palindrome

Time complexity: O(n^2).

Space complexity: O(n^2).

```c++
bool validKPalindrome(string s) {
}
```
