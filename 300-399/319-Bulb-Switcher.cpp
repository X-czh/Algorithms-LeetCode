// Simulation
// Time complexity: O(N^2).
// Space complexity: O(N).
class Solution1 {
public:
    int bulbSwitch(int n) {
        vector<int> bulbs(n, -1);
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j += i + 1) {
                bulbs[j] *= -1;
            }
        }
        return count(bulbs.begin(), bulbs.end(), 1);
    }
};

// Math
// Time complexity: O(logN) for computing sqrt.
// Space complexity: O(1).

/*
 * Explanation:
 * Bulb i is switched in round d if and only if d divides i. 
 * So bulb i ends up on if and only if it has an odd number of divisors.
 * Divisors come in pairs, a number n has an odd number of divisors i.f.f. n is a square number.
 * So bulb i ends up on if and only if i is a square.
 * So just count the square numbers, and result is int(sqrt(N)).
 */

class Solution2 {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};
