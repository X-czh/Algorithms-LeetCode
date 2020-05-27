# 703-Number of Matching Subsequences

[Problem](https://leetcode.com/problems/number-of-matching-subsequences/)

## Approach 1: Brute Force [Time Limit Exceeded]

Check separately whether each word words[i] is a subsequence of S.

Let N = words.length, L = S.length, L_i = words[i].length.

Time complexity: O(N * L + Sum(L_i)). For each word, our subseq check on word words[i] may take time complexity O(L + L_i).

Space complexity: O(1) auxiliary space.

```c++
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int ans = 0;

        for (auto &word : words) {
            bool isSubsequence = true;

            int idx = 0;
            for (auto ch : word) {
                bool found = false;
                while (idx < S.size()) {
                    if (ch == S[idx++]) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    isSubsequence = false;
                    break;
                }
            }

            if (isSubsequence)
                ans++;
        }

        return ans;
    }
};
```

A nicer implementaion of subseq check:

```c++
bool isSubseq(const string &word, const string &S) {
    int i = 0;
    for (char ch : S) {
        if (i < word.size() && ch == word[i])
            i++;
    }
    return (i == word.size());
}
```

## Appraoch 2: Next Letter List

With appraoch 1, one needs to go through S once for each word. To optimize that, we want to go through S once and only once, and move through all words accordingly. To implement that, I keep track of how much of each word has already appeared in S and which letter each word is waiting for by using index pairs (i,j) meaning word i is waiting for its letter j. With each letter of S, I advance the words waiting for that letter. Whenever we've done with a word, advance ans count by one.

Let N = words.length, L = S.length, L_i = words[i].length.

Time complexity: O(L + Sum(L_i)).

Space complexity: O(N) auxiliary space.

```c++
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int ans = 0;

        vector<pair<int, int>> waiting[26];
        for (int i = 0; i < words.size(); i++)
            waiting[words[i][0]-'a'].push_back({i, 0});

        for (char ch : S) {
            auto advances = waiting[ch-'a'];
            waiting[ch-'a'].clear();
            for (auto &p : advances) {
                int word_idx = p.first;
                int letter_idx = p.second;
                string word = words[word_idx];
                if (letter_idx == word.size() - 1) {
                    ans++;
                } else {
                    waiting[word[letter_idx+1]-'a'].push_back({word_idx, letter_idx+1});
                }
            }
        }

        return ans;
    }
};
```
