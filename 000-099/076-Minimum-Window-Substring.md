# 076-Minimum Window Substring

[Problem](https://leetcode.com/problems/minimum-window-substring/)

## Approach: Two Pointers Sliding Window

Time complexity: O(S + T), each char in string s is visited at most twice.

Space complexity: O(S + T), O(T) extra space.

```c++
class Solution {
public:
    string minWindow(string s, string t) {
        // look_up table, stores (char, number of char to be found)
        unordered_map<char, int> look_up;
        for (auto ch : t) {
            auto found = look_up.find(ch);
            if (found == look_up.end()) {
                look_up.insert({ch, 1});
            } else {
                ++(found->second);
            }
        }

        int left = 0, right = 0;
        int count = t.size(); // number of char to be found
        int min_len = s.size() + 1;
        int min_window_start = 0;
        while (right < s.size()) {
            // expand the window
            auto found = look_up.find(s[right]);
            if (found != look_up.end()) {
                if (found->second > 0) {
                    --count;
                }
                --(found->second);
            }
            ++right;

            // contract the window if all chars found
            if (count == 0) {
                while (true) {
                    auto found = look_up.find(s[left]);
                    if (found != look_up.end()) {
                        ++(found->second);
                        if (found->second > 0) { // its removal leads to char missing
                            ++count;
                            break;
                        }
                    }
                    ++left;
                } // contraction finished

                // update minimum window
                int len = right - left;
                if (len < min_len) {
                    min_len = len;
                    min_window_start = left;
                }

                // prepare for next expansion
                ++left;
            }
        }

        return (min_len > s.size()) ? "" : s.substr(min_window_start, min_len);
    }
};
```
