# 345-Reverse Vowels of a String

[Problem](https://leetcode.com/problems/reverse-vowels-of-a-string/)

## Approach 1: Count Vowels First

Count the number of vowels first, which is an O(n) pass. Then iteratively swap the first and last half.

```c++
// Time complexity: O(n).
// Space complexity: O(n) extra space.
class Solution1 {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels;
        vowels.insert('a');
        vowels.insert('A');
        vowels.insert('e');
        vowels.insert('E');
        vowels.insert('i');
        vowels.insert('I');
        vowels.insert('o');
        vowels.insert('O');
        vowels.insert('u');
        vowels.insert('U');

        int cnt_vowels = 0;
        for (char ch : s) {
            if (vowels.find(ch) != vowels.end()) ++cnt_vowels;
        }

        int forward = 0;
        int backward = s.size() - 1;
        for (int i = 0; i < cnt_vowels / 2; ++i, ++forward, --backward) {
            while (vowels.find(s[forward]) == vowels.end()) ++forward;
            while (vowels.find(s[backward]) == vowels.end()) --backward;
            swap(s[forward], s[backward]);
        }

        return s;
    }
};

// Time complexity: O(n).
// Space complexity: O(1) extra space.
class Solution2 {
public:
    string reverseVowels(string s) {
        int cnt_vowels = 0;
        for (char ch : s) {
            if (isVowel(ch)) ++cnt_vowels;
        }

        int forward = 0;
        int backward = s.size() - 1;
        for (int i = 0; i < cnt_vowels / 2; ++i, ++forward, --backward) {
            while (!isVowel(s[forward])) ++forward;
            while (!isVowel(s[backward])) --backward;
            swap(s[forward], s[backward]);
        }

        return s;
    }
private:
    bool isVowel(char c) {
        return (c == 'a' || c == 'A' ||
               c == 'e' || c == 'E' ||
               c == 'i' || c == 'I' ||
               c == 'o' || c == 'O' ||
               c == 'u' || c == 'U');
    }
};
```

## Approach 2: Two Pointers (!!!)

Keep swapping vowels found from the beginning and ending of the string, one pair a time. When the two pointers cross each other, stop swapping. No extra O(n) pass to count the number of vowels.

Time complexity: O(n).

Space complexity: O(1) extra space.

```c++
class Solution {
public:
    string reverseVowels(string s) {
        int cnt_vowels = 0;
        for (char ch : s) {
            if (isVowel(ch)) ++cnt_vowels;
        }

        int forward = 0;
        int backward = s.size() - 1;
        for (int i = 0; i < cnt_vowels / 2; ++i, ++forward, --backward) {
            while (!isVowel(s[forward])) ++forward;
            while (!isVowel(s[backward])) --backward;
            swap(s[forward], s[backward]);
        }

        return s;
    }
private:
    bool isVowel(char c) {
        return (c == 'a' || c == 'A' ||
               c == 'e' || c == 'E' ||
               c == 'i' || c == 'I' ||
               c == 'o' || c == 'O' ||
               c == 'u' || c == 'U');
    }
};
```
