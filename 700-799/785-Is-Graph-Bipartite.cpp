// DFS coloring
// Time complexity: O(n).
// Space complexity: O(n).

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        enum Color { UNCOLORED, RED, GREEN };
        const int N = graph.size();
        vector<Color> color(N, UNCOLORED);
        
        for (int i = 0; i < N; i++) {
            if (color[i] == UNCOLORED) {
                stack<int> stk;
                stk.push(i);
                color[i] = RED;
                
                while (!stk.empty()) {
                    int node = stk.top();
                    stk.pop();
                    for (int neighbor : graph[node]) {
                        if (color[neighbor] == UNCOLORED) {
                            stk.push(neighbor);
                            color[neighbor] = (color[node] == RED ? GREEN : RED);
                        } else if (color[neighbor] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};
