// Observation: the prefix of encode(num) = encode((n - 1) / 2).

// Time complexity: O(logn).
// Space complexity: O(logn).

class Solution {
public:
    string encode(int num) {
        if (num == 0)
            return "";
        return encode((num - 1) / 2) + "10"[num % 2];
    }
};
