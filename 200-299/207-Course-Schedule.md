# 207-Course Schedule

[Problem](https://leetcode.com/problems/course-schedule/)

Determine whether the given graph is a DAG (Directed Acyclic Graph).

## Approach 1: Kahn's Algorithm

Chooses vertices in the same order as the eventual topological sort.

First, find a list of "start nodes" which have no incoming edges and insert them into a set S; at least one such node must exist in a non-empty acyclic graph. Then, pick one from S, place it in a output list L, update the in-degrees of its successors, and insert those which have no incoming edges into S. Keep doing this until S is empty.

If the size of L equals the number of the vertices, then the graph is acyclic.

Time complexity: O(V + E).

Space complexity: O(V + E).

```c++
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<int> order;

        // read relations
        vector<vector<int>> succ(numCourses);
        for (const auto& pair : prerequisites) {
            succ[pair[1]].push_back(pair[0]);
        }

        // initialize in-degree
        vector<int> deg(numCourses, 0);
        for (int v = 0; v < numCourses; ++v) {
            for (int w : succ[v]) ++deg[w];
        }

        // initialize q to all nodes of in-degree 0
        for (int v = 0; v < numCourses; ++v) {
            if (deg[v] == 0) q.push(v);
        }

        // main loop
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            order.push_back(v);
            for (int w : succ[v]) {
                if (--deg[w] == 0) q.push(w);
            }
        }

        return (order.size() == numCourses);
    }
};
```

## Approach 2: Tarjan’s Algorithm (DFS)

Chooses vertices in the reverse order as the eventual topological sort.

If during DFS, an active node is visited (a node is active since we first visit it, and it only become finished when all of the nodes reachable from it have been visited), then the graph contains a cycle.

Time complexity: O(V + E).

Space complexity: O(V + E).

### Solution 1: Recusive

```c++
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<status_t> status(numCourses, NEW);

        // construct adjacency lists of graph
        vector<vector<int>> graph(numCourses);
        for (const auto& pair : prerequisites) {
            graph[pair[1]].push_back(pair[0]);
        }

        // for each vertice v
        for (int v = 0; v < numCourses; ++v) {
            if (status[v] == NEW) {
                if (isAcyclicDFS(v, graph, status) == false) {
                    return false;
                }
            }
        }

        return true;
    }
private:
    enum status_t { NEW, ACTIVE, FINISHED };

    bool isAcyclicDFS(int v, vector<vector<int>>& graph, vector<status_t>& status) {
        status[v] = ACTIVE;

        // for each edge v->w
        for (int i = 0; i < graph[v].size(); ++i) {
            int w = graph[v][i];
            if (status[w] == ACTIVE) {
                return false;
            } else if (status[w] == NEW) {
                if (isAcyclicDFS(w, graph, status) == false) {
                    return false;
                }
            }
        }

        status[v] = FINISHED;

        return true;
    }
};
```

### Solution 2: Iterative

Kind of tricky to turning recursion to iteration as there are post-steps after the recursice call.

```c++
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<status_t> status(numCourses, NEW);

        // construct adjacency lists of graph
        vector<vector<int>> graph(numCourses);
        for (const auto& pair:prerequisites) {
            graph[pair[1]].push_back(pair[0]);
        }

        // for each vertice i
        for (int i = 0; i < numCourses; ++i) {
            if (status[i] == NEW) {
                stack<int> s;
                s.push(i);

                while (!s.empty()) {
                    int v = s.top();
                    if (status[v] == FINISHED) {
                        s.pop();
                        continue;
                    }

                    status[v] = ACTIVE;

                    // for each edge v->w
                    for (int j = 0; j < graph[v].size(); ++j) {
                        int w = graph[v][j];
                        if (status[w] == ACTIVE) {
                            return false;
                        } else if (status[w] == NEW) {
                            s.push(w);
                        }
                    }

                    if (v == s.top()) { // no neighbor visited
                        status[v] = FINISHED;
                        s.pop();
                    }
                }
            }
        }

        return true;
    }
private:
    enum status_t { NEW, ACTIVE, FINISHED };
};
```
