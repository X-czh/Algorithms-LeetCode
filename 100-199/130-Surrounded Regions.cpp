// DFS
// Time complexity: O(M * N).
// Space complexity: O(M * N).

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int M = board.size();
        if (M == 0) return;
        int N = board[0].size();
        
        for (int i = 0; i < M; i++) {
            if (board[i][0] == 'O')
                dfs(i, 0, board);
            if (board[i][N - 1] == 'O')
                dfs(i, N - 1, board);
        }
        for (int j = 1; j < N - 1; j++) {
            if (board[0][j] == 'O')
                dfs(0, j, board);
            if (board[M - 1][j] == 'O')
                dfs(M - 1, j, board);
        }
        
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 'R')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
private:
    void dfs(int i, int j, vector<vector<char>>& board) {
        board[i][j] = 'R'; // reserved
        if (i - 1 >= 0 && board[i - 1][j] == 'O')
            dfs(i - 1, j, board);
        if (j + 1 < board[0].size() && board[i][j + 1] == 'O')
            dfs(i, j + 1, board);
        if (i + 1 < board.size() && board[i + 1][j] == 'O')
            dfs(i + 1, j, board);
        if (j - 1 >= 0 && board[i][j - 1] == 'O')
            dfs(i, j - 1, board);
    }
};
