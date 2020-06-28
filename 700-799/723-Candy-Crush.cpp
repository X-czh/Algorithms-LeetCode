class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        while (crush(board)) {
            gravity(board);
        }
        return board;
    }
private:
    enum Orientation { ROW, COL };
    
    bool crush(vector<vector<int>>& board) {
        int M = board.size();
        int N = board[0].size();
        vector<vector<int>> crush_list;
        
        for (int i = 0; i < M; i++) {
            int j = 1;
            int cnt = 1;
            while (j < N) {
                if (board[i][j] != 0 && board[i][j] == board[i][j - 1]) {
                    cnt++;
                } else {
                    if (cnt >= 3)
                        crush_list.push_back({i, j - 1, cnt, ROW});
                    cnt = 1;
                }
                j++;
            }
            if (cnt >= 3)
                crush_list.push_back({i, j - 1, cnt, ROW});
        }
        for (int j = 0; j < N; j++) {
            int i = 1;
            int cnt = 1;
            while (i < M) {
                if (board[i][j] != 0 && board[i][j] == board[i - 1][j]) {
                    cnt++;
                } else {
                    if (cnt >= 3)
                        crush_list.push_back({i - 1, j, cnt, COL});
                    cnt = 1;
                }
                i++;
            }
            if (cnt >= 3)
                crush_list.push_back({i - 1, j, cnt, COL});
        }
        
        for (auto& crush_cmd : crush_list) {
            int row = crush_cmd[0], col = crush_cmd[1], cnt = crush_cmd[2];
            if (crush_cmd[3] == ROW) {
                for (int i = 0; i < cnt; i++) {
                    board[row][col - i] = 0;
                }
            } else {
                for (int i = 0; i < cnt; i++) {
                    board[row - i][col] = 0;
                }
            }
        }
        
        return !crush_list.empty();
    }
    
    void gravity(vector<vector<int>>& board) {
        int M = board.size();
        int N = board[0].size();
        
        for (int i = M - 1; i >= 0; i--) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 0) {
                    int row = i - 1;
                    while (row >= 0 && board[row][j] == 0) {
                        row--;
                    }
                    for (int k = row; k >= 0; k--) {
                        board[i - (row - k)][j] = board[k][j];
                        board[k][j] = 0;
                    }
                }
            }
        }
    }
};
