# 310-Minimum Height Trees

[Problem](https://leetcode.com/problems/minimum-height-trees/)

## Approach 1: Brute Force BFS

For each vertice, pick it as the root, run BFS to find the height of the tree. Select vertices with the smallest resulting height.

Time complexity: O(V * (V + E)).

Space complexity: O(V + E).

```c++
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        int min_height = n - 1;
        vector<int> height_trees(n);

        // construct adjacency lists of graph
        vector<vector<int>> succ(n);
        for (const auto& pair : edges) {
            succ[pair[0]].push_back(pair[1]);
            succ[pair[1]].push_back(pair[0]);
        }

        // compute height of trees with roots from 0 to n - 1
        for (int i = 0; i < n; ++i) {
            queue<int> q;
            q.push(i);
            vector<bool> visited(n, false);
            vector<int> heights(n, 0);
            int height_tree = 0;

            while (!q.empty()) {
                int curr = q.front();
                visited[curr] = true;
                q.pop();
                for (int child : succ[curr]) {
                    if (!visited[child]) {
                        q.push(child);
                        heights[child] = heights[curr] + 1;
                        if (heights[child] > height_tree) {
                            height_tree = heights[child];
                        }
                    }
                }
            }

            if (height_tree < min_height) {
                min_height = height_tree;
            }
            height_trees[i] = height_tree;
        }

        // output roots
        vector<int> roots;
        for (int i = 0; i < n; ++i) {
            if (height_trees[i] == min_height) roots.push_back(i);
        }

        return roots;
    }
};
```

## Appraoch 2: Smart BFS, iteratively remove leaves until there are <=2 nodes

The root of the minimum height tree locates at the geometric center of the tree (the lengths of the paths from the root to all leaves are roughly the same). Therefore, we can remove the leaves of trees to get a new tree, and iterately do this until there are less than or equal to 2 nodes, which are the roots of the minimum height tree.

Time complexity: O(V + E).

Space complexity: O(V + E).

```c++
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // handles special cases
        if (n == 0) return {};
        if (n == 1) return {0};

        // construct degrees and adjacency lists of graph
        vector<int> deg(n, 0);
        vector<vector<int>> neighbor(n);
        for (const auto& pair : edges) {
            ++deg[pair[0]];
            ++deg[pair[1]];
            neighbor[pair[0]].push_back(pair[1]);
            neighbor[pair[1]].push_back(pair[0]);
        }

        // push leaves in queue
        queue<int> q;
        for (int v = 0; v < n; ++v) {
            if (deg[v] == 1) q.push(v);
        }

        // iteratively remove leaves until there are <=2 nodes
        int nodes_left = n;
        while (nodes_left > 2) {
            int num_leaves = q.size();
            nodes_left -= num_leaves;

            for (int i = 0; i < num_leaves; ++i) {
                int leaf = q.front();
                q.pop();
                --deg[leaf];

                for (int parent : neighbor[leaf]) {
                    if (deg[parent] > 1) {
                        if (--deg[parent] == 1) {
                            q.push(parent); // leaf in the new reduced tree, push in queue
                        }
                    }
                }
            }
        }

        // generate roots of MHT
        vector<int> roots;
        while (!q.empty()) {
            roots.push_back(q.front());
            q.pop();
        }

        return roots;
    }
};
```
