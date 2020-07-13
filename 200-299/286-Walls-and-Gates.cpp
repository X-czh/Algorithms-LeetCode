// BFS
// Time complexity: O(mn).
// Space complexity: O(mn).

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        const int M = rooms.size();
        if (M == 0) return;
        const int N = rooms[0].size();
        
        const int GATE = 0;
        const int EMPTY = numeric_limits<int>::max();
        const vector<vector<int>> DIRECTIONS{
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };
        
        queue<vector<int>> q;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (rooms[i][j] == GATE) {
                    q.push({i, j});
                }
            }
        }
        
        while (!q.empty()) {
            auto pos = q.front();
            q.pop();
            int row = pos[0];
            int col = pos[1];
            for (const auto& dir : DIRECTIONS) {
                int r = row + dir[0];
                int c = col + dir[1];
                if (r >= 0  && c >= 0 && r < M && c < N && rooms[r][c] == EMPTY) {
                    rooms[r][c] = rooms[row][col] + 1;
                    q.push({r, c});
                }
            }
        }
    }
};
