# 547-Friend Circles

[Problem](https://leetcode.com/problems/find-bottom-left-tree-value/)

This problems = finding # connected components in graph.

## Approach 1: DFS

Time complexity: O(n^2).

Space complexity: O(n) extra space.

```c++
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        vector<int> visited(N, 0);
        
        int count = 0;
        for (int i = 0; i < N; ++i) {
            if (visited[i] == 0) {
                dfs(M, visited, i);
                ++count;
            }
        }
        return count;
    }
private:
    void dfs(vector<vector<int>>& M, vector<int>& visited, int i) {
        for (int j = 0; j < M.size(); ++j) {
            if (M[i][j] == 1 & visited[j] == 0) {
                visited[j] = 1;
                dfs(M, visited, j);
            }
        }
    }
};
```

## Approach 2: BFS

Time complexity: O(n^2).

Space complexity: O(n) extra space.

```c++
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        queue<int> q;
        vector<int> visited(N, 0);
        
        int count = 0;
        for (int i = 0; i < N; ++i) {
            if (visited[i] == 0) {
                q.push(i);
                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    for (int j = 0; j < N; ++j) {
                        if (M[curr][j] == 1 && visited[j] == 0) {
                            visited[j] = 1;
                            q.push(j);
                        }
                    }
                }
                ++count;
            }
        }
        return count;
    }
};
```

## Approach 3: Union-Find

Time complexity: O(n^3), amortized time complexity of O(n^2) with path compression and union by rank.

Space complexity: O(n) extra space.

```c++
class UnionFind {
public:
    UnionFind(int N)
        : parent(N, 0), rank(N, 0), count{0}
    {
        for (int i = 0; i < N; ++i) {
            makeSet(i);
        }
    }
    
    void makeSet(int x) {
        parent[x] = x;
        ++count;
    }
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void merge(int x, int y) {
        int xroot = find(x);
        int yroot = find(y);
        
        if (xroot == yroot)
            return;
        
        if (rank[xroot] < rank[yroot]) {
            swap(xroot, yroot);
        }
        parent[yroot] = xroot;
        if (rank[xroot] == rank[yroot])
             ++rank[xroot];
        --count;
    }
    
    int getCount() const {
        return count;
    }

private:
    vector<int> parent;
    vector<int> rank;
    int count;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        UnionFind uf(N);
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (M[i][j] == 1)
                    uf.merge(i, j);
            }
        }
        return uf.getCount();
    }
};
```