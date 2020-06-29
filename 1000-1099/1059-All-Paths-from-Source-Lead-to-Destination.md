# 1059-All Paths from Source Lead to Destination

[Problem](https://leetcode.com/problems/all-paths-from-source-lead-to-destination/)

## Approach: DFS

Return true only if both:

1. We cannot reach a cycle from source node.

2. From all visited nodes from source the unique node with out-degree = 0 is the destination node.

We can check the two conditions recursively using DFS.

Time complexity: O(V + E).

Space complexity: O(V + E).

```c++
class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        // construct adjacency list of graph
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }

        vector<status_t> status(n, NEW);
        return dfs(source, destination, graph, status);
    }
private:
    enum status_t { NEW, ACTIVE, FINISHED };

    bool dfs(int v, int destination, vector<vector<int>>& graph, vector<status_t>& status) {
        status[v] = ACTIVE;

        // check if from all visited nodes from source the unique node with indegree = 0 is the destination node
        if (v != destination && graph[v].size() == 0) {
            return false;
        }

        // for each edge v->w
        for (int w : graph[v]) {
            // check cycle
            if (status[w] == ACTIVE) {
                return false;
            }

            // recursive checking
            if (status[w] == NEW) {
                if (dfs(w, destination, graph, status) == false) {
                    return false;
                }
            }
        }

        status[v] = FINISHED;

        return true;
    }
};
```
