// DFS
// Time complexity: O(mn).
// Space complexity: O(mn).

class Solution {
public:    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) { 
        vector<vector<int>> visited(maze.size(), vector<int>(maze[0].size(), 0));
        return dfs(maze, start, destination, visited);
    }
private:
    bool dfs(vector<vector<int>>& maze, vector<int> start, vector<int>& destination, vector<vector<int>>& visited) {
        const int N = maze.size();
        const int M = maze[0].size();
        int start_x = start[0];
        int start_y = start[1];
        if (visited[start_x][start_y] == 1)
            return false;
        visited[start_x][start_y] = 1;
        if (start == destination) {
            return true;
        }
        
        int x, y;
        
        // up
        x = start_x;
        while (x >= 0 && maze[x][start_y] == 0)
            x--;
        if (dfs(maze, {x + 1, start_y}, destination, visited))
            return true;
        
        // down
        x = start_x;
        while (x < N && maze[x][start_y] == 0)
            x++;
        if (dfs(maze, {x - 1, start_y}, destination, visited))
            return true;
        
        // left
        y = start_y;
        while (y >= 0 && maze[start_x][y] == 0)
            y--;
        if (dfs(maze, {start_x, y + 1}, destination, visited))
            return true;
        
        // right
        y = start_y;
        while (y < M && maze[start_x][y] == 0)
            y++;
        if (dfs(maze, {start_x, y - 1}, destination, visited))
            return true;
        
        return false;
    }
};
