// Backtracking
// Time complexity: O(N * 4^L), N is number of cells, L is length of word.
// Space complexity: O(L) auxilary space.

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int N = board.size();
        int M = board[0].size();
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == word[0]) {
                    if (find(board, i, j, word, 0))
                        return true;
                }
            } 
        }
        return false;
    }
private:
    bool find(vector<vector<char>>& board, int i, int j, string& word, int idx) {
        if (idx + 1 == word.size()) {
            return true;
        }
        
        int N = board.size();
        int M = board[0].size();
        char saved = board[i][j];
        board[i][j] = '*';
        
        if (i + 1 < N && board[i+1][j] == word[idx+1]) {
            if (find(board, i+1, j, word, idx+1)) {
                board[i][j] = saved;
                return true;
            }
        }
        if (i - 1 >= 0 && board[i-1][j] == word[idx+1]) {
            if (find(board, i-1, j, word, idx+1)) {
                board[i][j] = saved;
                return true;
            }
        }
        if (j + 1 < M && board[i][j+1] == word[idx+1]) {
            if (find(board, i, j + 1, word, idx+1)) {
                board[i][j] = saved;
                return true;
            }
        }
        if (j - 1 >= 0 && board[i][j-1] == word[idx+1]) {
            if (find(board, i, j - 1, word, idx+1)) {
                board[i][j] = saved;
                return true;
            }
        }
        board[i][j] = saved;
        return false;
    }
};
