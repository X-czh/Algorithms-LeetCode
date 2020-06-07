# 1354-Construct Target Array With Multiple Sums

[Problem](https://leetcode.com/problems/construct-target-array-with-multiple-sums/)

## Approach 1: Working Backward (Naive)

When n = 1, the sum of [1] is always 1.

When n >= 2, let's work backwards. The max number n_max in the target array must be produced by taking the sum of the previous array, and we can thus revert the target array one step back by substracting n_max by (sum(target_array) - n_max). Keep doing this, until any n_max after substraction in the process becomes less than 1 (return false) or we find n_max exactly 1 (return true). Why the latter case ensures that all numbers in the array are 1? Recall that an array element is >= 1 initially, and it can only be decreased if it is once n_max and got substracted. If we didn't see any n_max after substractionin the process becomes less than 1, then we would be sure that all numbers in the array >= 1. If further the largest number among them is 1, then all the array elements are 1.

Time complexity: O(n+klogn), where k is the maximum of the target array.

Space complexity: O(n).

```c++
class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1)
            return target[0] == 1;

        int sum = 0;
        for (auto n : target) {
            sum += n;
        }

        priority_queue<int> heap(target.begin(), target.end());

        while (heap.top() > 1) {
            int max = heap.top();
            heap.pop();
            int prev = max - (sum - max);
            if (prev < 1)
                return false;
            heap.push(prev);
            sum = sum - max + prev;
        }

        return true;
    }
};
```

## Approach 2: Working Backward (Modulo Variant)

### Idea

In the naive approach, if `n_max` is really large while the remaining array elements (say the sum of which is `rest`) are really small, we will end up with substracting `n_max` again and again until `n_max < 1` or `n_max` is no longer the largest number in the array.

How should we speed this up?

Let's first analyze in more detail the stop condition for substracting the same `n_max`. We first substract `n_max` by `rest` a few times until `n_max <= rest`. Now, if `n_max < rest`, if `n_max` is still the largest number, we will continue to substract `n_max` and got a negative number (return false), otherwise we stop. If `n_max` = `rest`, as long as `rest > 1`, we know `n_max` is still the largest number, we will continue to substract `n_max` and got a zero (return false) while if `rest = 1`, there are only two elements in the array, and we would return true.

With this observation, we can speed up the process using modulo operation. We update `n_max` by `n_max % rest`. If the modulo is 0, we return true only if `rest = 1`, otherwise return false. If the modulo is `n_max` itself, indicating that `n_max < rest` while `n_max` is still the largest number, we return false. In all other cases, we get a modulo < `rest` and we are not sure whether it is still the largest number, so we start a new iteration.

### Complexity Analysis

The core step of the algorithm is `n_max = n_max % rest`. For clarity, I'll rewrite it as `x = largest % rest`, where `x` and `largest` are the values of `n_max` after and before the update respectively. In order for the algorithm to continue, we must have `largest > rest`, we know that `x` is at most `largest - rest`, i.e. the modulus will cause rest to be subtracted at least once.

* If `rest` is at least half the size of `largest`, then this will clearly chop `largest` in half.
* If instead `rest` is less than half the size of `largest`, then `largest % rest` must be less than half of `largest`.

The original total sum is at most 2k, because k is the largest element, and we know that if the algorithm continues, then the rest can't add up to more than k. Therefore, at each step, we were removing at least the sum of at least 1/4 of the total sum. So, we need to take O(logk) steps to reduce the array down. This recudes the time complexity from O(n+k\*logn) to O(n+logk\*logn).

Time complexity: O(n+logk*logn).

Space complexity: O(n).

### Solution

```c++
class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1)
            return target[0] == 1;

        long sum = 0;
        for (auto n : target) {
            sum += n;
        }

        priority_queue<int> heap(target.begin(), target.end());

        while (heap.top() > 1) {
            int max = heap.top();
            heap.pop();

            long rest = sum - max;
            // This will only occur if n = 2.
            if (rest == 1)
                return true;

            int x = max % rest;
            if (x < 1 || x == max)
                return false;

            heap.push(x);
            sum = rest + x;
        }

        return true;
    }
};
```
