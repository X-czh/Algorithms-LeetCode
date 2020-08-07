// DFS
// Time complexity: O(mn).
// Space complexity: O(mn).

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> res(image);
        vector<vector<int>> visited(image.size(), vector<int>(image[0].size(), 0));
        dfs(image, res, visited, sr, sc, newColor);
        return res;
    }
private:
    void dfs(vector<vector<int>>& image, vector<vector<int>>& res, vector<vector<int>>& visited, int sr, int sc, int newColor) {
        if (visited[sr][sc] == 1) {
            return;
        }
        visited[sr][sc] = 1;
        res[sr][sc] = newColor;
        
        const int N = image.size();
        const int M = image[0].size();
        int color = image[sr][sc];
        if (sr + 1 < N && image[sr + 1][sc] == color) {
            dfs(image, res, visited, sr + 1, sc, newColor);
        }
        if (sr - 1 >= 0 && image[sr - 1][sc] == color) {
            dfs(image, res, visited, sr - 1, sc, newColor);
        }
        if (sc + 1 < M && image[sr][sc + 1] == color) {
            dfs(image, res, visited, sr, sc + 1, newColor);
        }
        if (sc - 1 >= 0 && image[sr][sc - 1] == color) {
            dfs(image, res, visited, sr, sc - 1, newColor);
        }
    }
};
