# 780-Reaching Points

[Problem](https://leetcode.com/problems/reaching-points/)

A move consists of taking a point (x, y) and transforming it to either (x, x+y) or (x+y, y).

Given a starting point (sx, sy) and a target point (tx, ty), return True if and only if a sequence of moves exists to transform the point (sx, sy) to (tx, ty). Otherwise, return False.

sx, sy, tx, ty will all be integers in the range [1, 10^9].

## Approach 1: Forward Search (Stack Overflow)

Time complexity: O(2^(tx+ty)), a loose bound by considering every move as (x, y) -> (x+1, y) or (x, y) -> (x, y+1) instead.

Space complexity: O(tx*ty).

```c++
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (sx == tx && sy == ty)
            return true;
        if (sx > tx || sy > ty)
            return false;
        return reachingPoints(sx, sx+sy, tx, ty) || reachingPoints(sx+sy, sy, tx, ty);
    }
};
```

## Approach 2: Forward Search - Dynamic Programming (Stack Overflow)

Time complexity: O(tx∗ty).

Space complexity: O(tx∗ty).

```c++
struct pair_hash {
    std::size_t operator()(const std::pair<int, int>& pair) const {
        std::size_t h1 = std::hash<int>()(pair.first);
        std::size_t h2 = std::hash<int>()(pair.second);
        return h1 ^ h2;
    }
};

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        unordered_set<pair<int, int>, pair_hash> seen;
        search(sx, sy, tx, ty, seen);
        return seen.find({tx, ty}) != seen.end();
    }
private:
    void search(int sx, int sy, int tx, int ty, unordered_set<pair<int, int>, pair_hash>& seen) {
        if (seen.find({sx, sy}) != seen.end())
            return;
        if (sx > tx || sy > ty)
            return;
        seen.insert({sx, sy});
        search(sx, sx+sy, tx, ty, seen);
        search(sx+sy, sy, tx, ty, seen);
    }
};
```

## Approach 3: Backward Search (Time Limit Exceeded)

Idea: Every point (x, y) has two possible children, (x, x+y) and (x+y, y). However, every point (x, y) only has one parent candidate (x-y, y) if x >= y, else (x, y-x). This is because we never have points with negative coordinates. Therefore, it is more efficient to search backwards from target point (tx, ty).

Time complexity: O(max(tx,ty)). If say ty = 1, we could be subtracting tx times.

Space complexity: O(1).

```c++
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (sx == tx && sy == ty)
                return true;
            if (tx > ty)
                tx -= ty;
            else
                ty -= tx;
        }
        return false;
    }
};
```

## Approach 4: Backward Search (Modulo Variant)

We can speed up this transformation by bundling together parent operations: (x, y) -> (x-y, y) or (x, y-x) depending on which one doesn't have negative coordinates.

Say tx > ty. We know that the next parent operations will be to subtract ty from tx, until such time that tx = tx % ty. When both tx > ty and ty > sy, we can perform all these parent operations in one step, replacing while tx > ty: tx -= ty with tx %= ty.

Otherwise, if say tx > ty and ty <= sy, then we know ty will not be changing (it can only decrease). Thus, only tx will change, and it can only change by subtracting by ty. Hence, (tx - sx) % ty == 0 is a necessary and sufficient condition for the problem's answer to be True.

The analysis above was for the case tx > ty, but the case ty > tx is similar. When tx == ty, no more moves can be made.

Time complexity: O(log(max(tx,ty))).

Space complexity: O(1).

```c++
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx == ty) break;
            if (tx > ty) {
                if (ty > sy)
                    tx %= ty;
                else
                    return (tx - sx) % ty == 0;
            } else {
                if (tx > sx)
                    ty %= tx;
                else
                    return (ty - sy) % tx == 0;
            }
        }
        return (tx == sx && ty == sy);
    }
};
```
