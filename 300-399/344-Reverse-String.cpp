// Time complexity: O(n).
// Space complexity: O(1) extra space.

class Solution {
public:
    void reverseString(vector<char>& s) {
        const int N = s.size();
        for (int i = 0; i < N / 2; ++i) {
            swap(s[i], s[N - 1 - i]);
        }
    }
};
