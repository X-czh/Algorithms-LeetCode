// Time complexity: O(N x α(N)) ~= O(N).
// Space complexity: O(N).

class UnionFind {
public:
    UnionFind(int N) : parent(N, 0), rank(N, 0) {
        for (int i = 0; i < N; ++i) {
            make_set(i);
        }
    }
    
    void make_set(int x) {
        parent[x] = x;
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
    }
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind uf(edges.size());
        for (const auto& edge : edges) {
            if (uf.connected(edge[0] - 1, edge[1] - 1)) {
                return edge;   
            }
            uf.merge(edge[0] - 1, edge[1] - 1);
        }
        return {};
    }
};
