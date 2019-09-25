class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int M = board.size();
        int N = board[0].size();
        int x = click[0];
        int y = click[1];
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
        } else {
            int cnt = 0;
            if (x - 1 >= 0) {
                if (y - 1 >= 0 && board[x - 1][y - 1] == 'M') ++cnt;
                if (board[x - 1][y] == 'M') ++cnt;
                if (y + 1 < N && board[x - 1][y + 1] == 'M') ++cnt;
            }
            if (x + 1 < M) {
                if (y - 1 >= 0 && board[x + 1][y - 1] == 'M') ++cnt;
                if (board[x + 1][y] == 'M') ++cnt;
                if (y + 1 < N && board[x + 1][y + 1] == 'M') ++cnt;
            }
            if (y - 1 >= 0 && board[x][y - 1] == 'M') ++cnt;
            if (y + 1 < N && board[x][y + 1] == 'M') ++cnt;

            if (cnt > 0) {
                board[x][y] = cnt + '0';
            } else {
                board[x][y] = 'B';
                if (x - 1 >= 0) {
                    if (y - 1 >= 0) updateBoardHelper(board, {x - 1, y - 1});
                    updateBoardHelper(board, {x - 1, y});
                    if (y + 1 < N) updateBoardHelper(board, {x - 1, y + 1});
                }
                if (x + 1 < M) {
                    if (y - 1 >= 0) updateBoardHelper(board, {x + 1, y - 1});
                    updateBoardHelper(board, {x + 1, y});
                    if (y + 1 < N) updateBoardHelper(board, {x + 1, y + 1});
                }
                if (y - 1 >= 0) updateBoardHelper(board, {x, y - 1});
                if (y + 1 < N) updateBoardHelper(board, {x, y + 1});
            }
        }
        return board;
    }
private:
    void updateBoardHelper(vector<vector<char>>& board, vector<int> click) {
        int M = board.size();
        int N = board[0].size();
        int x = click[0];
        int y = click[1];
        
        if (board[x][y] != 'E') return;
        
        int cnt = 0;
        if (x - 1 >= 0) {
            if (y - 1 >= 0 && board[x - 1][y - 1] == 'M') ++cnt;
            if (board[x - 1][y] == 'M') ++cnt;
            if (y + 1 < N && board[x - 1][y + 1] == 'M') ++cnt;
        }
        if (x + 1 < M) {
            if (y - 1 >= 0 && board[x + 1][y - 1] == 'M') ++cnt;
            if (board[x + 1][y] == 'M') ++cnt;
            if (y + 1 < N && board[x + 1][y + 1] == 'M') ++cnt;
        }
        if (y - 1 >= 0 && board[x][y - 1] == 'M') ++cnt;
        if (y + 1 < N && board[x][y + 1] == 'M') ++cnt;
        
        if (cnt > 0) {
            board[x][y] = cnt + '0';
        } else {
            board[x][y] = 'B';
            if (x - 1 >= 0) {
                if (y - 1 >= 0) updateBoardHelper(board, {x - 1, y - 1});
                updateBoardHelper(board, {x - 1, y});
                if (y + 1 < N) updateBoardHelper(board, {x - 1, y + 1});
            }
            if (x + 1 < M) {
                if (y - 1 >= 0) updateBoardHelper(board, {x + 1, y - 1});
                updateBoardHelper(board, {x + 1, y});
                if (y + 1 < N) updateBoardHelper(board, {x + 1, y + 1});
            }
            if (y - 1 >= 0) updateBoardHelper(board, {x, y - 1});
            if (y + 1 < N) updateBoardHelper(board, {x, y + 1});
        }
    }
};
