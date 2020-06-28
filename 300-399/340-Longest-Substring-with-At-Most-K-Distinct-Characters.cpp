// Sliding Window

// Time complexity: O(N).
// Extra space complexity: O(K) if we erase the element when shrinking the sliding window, otherwise O(N)

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size();
        if (n * k == 0) return 0;
        
        int max_len = 0;
        int cnt_distinct = 0;
        int left = 0, right = 0;
        unordered_map<char, int> m;
        
        while (right < n) {
            if (++m[s[right]] == 1) ++cnt_distinct;
            ++right;
            
            while (cnt_distinct > k) {
                if (--m[s[left]] == 0) --cnt_distinct;
                ++left;
            }
            
            max_len = max(right - left, max_len);
        }
        
        return max_len;
    }
};
