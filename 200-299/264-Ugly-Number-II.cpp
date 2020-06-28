// Time complexity: O(nlogn).
// Space complexity: O(n).

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 6) {
            return n;
        }

        long curr = 0;
        set<long> s;
        s.insert(1);
        for (int i = 0; i < n; i++) {
            curr = *(s.begin());
            s.erase(s.begin());
            s.insert(curr * 2);
            s.insert(curr * 3);
            s.insert(curr * 5);
        }
        return curr;
    }
};
