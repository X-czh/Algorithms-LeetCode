# 1136-Parallel Courses

[Problem](https://leetcode.com/problems/parallel-courses/)

## Approach: Topological Sort

Define the level of a DAG to be the length of the longest path from a node with in-degree 0 to another node in the graph. This question is equivalent to finding the level of the dependency graph (you must take courses of different levels in different semesters).

Time complexity: O(V + E).

Space complexity: O(V + E).

```c++
class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        int min_semesters = 0;

        // read relations
        vector<vector<int>> succ(N);
        for (const auto& dep : relations) {
            succ[dep[0] - 1].push_back(dep[1] - 1);
        }

        // initialize in-degree
        vector<int> deg(N, 0);
        for (int v = 0; v < N; v++) {
            for (int w : succ[v]) deg[w]++;
        }

        // initialize q to all nodes of in-degree 0
        queue<int> q;
        for (int v = 0; v < N; v++) {
            if (deg[v] == 0) q.push(v);
        }

        // main loop
        vector<int> order;
        while (!q.empty()) {
            min_semesters++;
            vector<int> taken;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                order.push_back(v);
                taken.push_back(v);
            }
            for (int v : taken) {
                for (int w : succ[v]) {
                    if (--deg[w] == 0) q.push(w);
                }
            }
        }

        if (order.size() != N) return -1;
        return min_semesters;
    }
};
```
