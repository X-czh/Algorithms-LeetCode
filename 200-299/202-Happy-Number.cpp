// Hash Set Cycle-Finding
// Time complexity: O(logn).
// Space complexity: O(logn).
class Solution1 {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = get_next(n);
        }
        return n == 1;
    }
private:
    int get_next(int n) {
        int total_sum = 0;
        while (n > 0) {
            int d = n % 10;
            n /= 10;
            total_sum += d * d;
        }
        return total_sum;
    }
};

// Floyd's Cycle-Finding Algorithm
// Time complexity: O(logn).
// Space complexity: O(1).
class Solution2 {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = get_next(n);
        while (fast != 1 && slow != fast) {
            slow = get_next(slow);
            fast = get_next(get_next(fast));
        }
        return fast == 1;
    }
private:
    int get_next(int n) {
        int total_sum = 0;
        while (n > 0) {
            int d = n % 10;
            n /= 10;
            total_sum += d * d;
        }
        return total_sum;
    }
};

