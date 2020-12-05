# 1494-Parallel Courses II

[Problem](https://leetcode.com/problems/parallel-courses-ii/)

## (Wrong!!!) Appraoch: Largest Out Degree First Topological Sort

Variant of [1136-Parallel Courses](../1100-1199/1136-Parallel%20Courses.md) with a limit on the maximum number of courses that can be taken in one semester. To deal with the new limit, we must incorprate some sort of priority in taking the courses. A natural idea is to take the course that have the most successor courses (i.e. nodes with the largest out-degrees in prerequisite graph) first, and we can easily implement it with a priority queue.

Now let's prove the optimality of this greedy appraoch (and I got stuck :)

Thanks to this [post](https://leetcode.com/problems/parallel-courses-ii/discuss/708445/Weak-test-case-most-solutions-posted-using-depth-or-outdgree-are-wrong), this appraoch failes on

```
9
[[1,4],[1,5],[3,5],[3,6],[2,6],[2,7],[8,4],[8,5],[9,6],[9,7]]
3
```

It produces 4 but the correct answer is 3.

**A greedy algorithm without proof is simply wrong!**

Time complexity: O(V + E).

Space complexity: O(V + E).

```c++
class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        int min_semesters = 0;

        // read relations
        vector<vector<int>> succ(n);
        for (const auto& dep : dependencies) {
            succ[dep[0] - 1].push_back(dep[1] - 1);
        }

        // initialize in-degree, out_degree
        vector<int> in_deg(n, 0);
        vector<int> out_deg(n, 0);
        for (int v = 0; v < n; v++) {
            for (int w : succ[v]) in_deg[w]++;
            out_deg[v] = succ[v].size();
        }

        // initialize pq to all nodes of in-degree 0
        auto cmp = [&out_deg](int a, int b) { return out_deg[a] < out_deg[b]; };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int v = 0; v < n; v++) {
            if (in_deg[v] == 0) pq.push(v);
        }

        // main loop
        while (!pq.empty()) {
            min_semesters++;
            vector<int> taken;
            for (int i = 0; i < k && !pq.empty(); i++) {
                int v = pq.top();
                pq.pop();
                taken.push_back(v);
            }
            for (int v : taken) {
                for (int w : succ[v]) {
                    if (--in_deg[w] == 0) pq.push(w);
                }
            }
        }

        return min_semesters;
    }
};
```
