// This problems = finding # connected components in graph, can also use DFS/BFS

// Time complexity: O(M*N).
// Note that Union operation takes essentially constant time[1] when UnionFind is implemented with both path compression and union by rank.

// Space complexity: O(M*N) extra space.

class UnionFind {
 public:
    UnionFind(vector<vector<char>>& grid)
        : parent{}, rank{}, count{0} 
    {
        int M = grid.size();
        int N = grid[0].size();
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * N + j);
                    rank.push_back(0);
                    ++count;
                } else {
                    parent.push_back(-1);
                    rank.push_back(0);
                }
            }
        }
    }
    
    int find(int x) { // path compression
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void merge(int x, int y) { // union by rank
        int xroot = find(x);
        int yroot = find(y);
        
        // x and y are already in the same set
        if (xroot == yroot)            
            return;
        
        // x and y are not in same set, so we merge them
        // merge smaller-rank tree into larger-rank tree
        if (rank[xroot] < rank[yroot])
            swap(xroot, yroot);
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
    int count; // num of trees, i.e. connected components
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int M = grid.size();
        if (M == 0) return 0;
        int N = grid[0].size();
        
        UnionFind uf(grid);
        int num_islands = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == '1') {
                    grid[i][j] == '0'; // avoid redundant merging
                    if (i - 1 >= 0 && grid[i - 1][j] == '1') uf.merge(i * N + j, (i - 1) * N + j);
                    if (i + 1 < M && grid[i + 1][j] == '1') uf.merge(i * N + j, (i + 1) * N + j);
                    if (j - 1 >= 0 && grid[i][j - 1] == '1') uf.merge(i * N + j, i * N + j - 1);
                    if (j + 1 < N && grid[i][j + 1] == '1') uf.merge(i * N + j, i * N + j + 1);
                }
            }
        }
        
        return uf.getCount();
    }
};
```
