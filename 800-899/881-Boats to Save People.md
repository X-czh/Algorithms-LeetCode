# 881-Boats to Save People

[Problem](https://leetcode.com/problems/boats-to-save-people/)

## Approach: Sort + Two Pointer

If the heaviest person can share a boat with the lightest person, then do so. Otherwise, the heaviest person can't pair with anyone, so they get their own boat.

Time complexity: O(nlogn).

Space complexity: O(1) extra space.

```c++
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int lo = 0, hi = people.size() - 1;
        int ans = 0;
        
        while (lo <= hi) {
            ans++;
            if (people[lo] + people[hi] <= limit) {
                lo++;
            }
            hi--;
        }
        
        return ans;
    }
};
```
