// Union-Find

// Time complexit: O(N) (amortized).
// Space complexity: O(N).

class DisjointSet {
public:
    DisjointSet(int N)
        : parent(N, -1), rank(N, 0), count{N}
    {
        for (int i = 0; i < N; i++)
            parent[i] = i;
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
        
        if (rank[xroot] < rank[yroot])
            swap(xroot, yroot);
        parent[yroot] = xroot;
        if (rank[xroot] == rank[yroot])
            rank[xroot]++;
        count--;
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
    int earliestAcq(vector<vector<int>>& logs, int N) {
        DisjointSet ds(N);
        sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
        for (auto& log : logs) {
            ds.merge(log[1], log[2]);
            if (ds.getCount() == 1)
                return log[0];
        }
        return -1;
    }
};
