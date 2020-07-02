// Time complexity: O(logn).
// Space complexity: O(1).
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int ans = letters[0];
        int lo = 0;
        int hi = letters.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (letters[mid] == target) {
                lo = mid + 1;
            } else if (letters[mid] < target) {
                lo = mid + 1;
            } else {
                ans = letters[mid];
                hi = mid - 1;
            }
        }
        return ans;
    }
};
