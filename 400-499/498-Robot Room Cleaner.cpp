// N - number of cells in the room, M - number of obstacles
// Time complexity:  O(N - M).
// Space complexity: O(N - M).

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
struct hash_pair {
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    }
};

class Solution {
public:
    void cleanRoom(Robot& robot) {
        int direction = 0; // facing up
        pair<int, int> pos = {0, 0}; // relative coordinate
        unordered_map<pair<int, int>, bool, hash_pair> cleaned(false);
        cleanRoomDFS(robot, direction, pos, cleaned);
    }

private:
    void cleanRoomDFS(Robot& robot, int direction, pair<int, int> pos, unordered_map<pair<int, int>, bool, hash_pair>& cleaned) {
        robot.clean();
        cleaned[pos] = true;
        
        for (int i = 0; i < 4; i++) {
            pair<int, int> new_pos = next_pos(direction, pos);
            if (!cleaned[new_pos] && robot.move()) {
                cleanRoomDFS(robot, direction, new_pos, cleaned);
                go_back(robot);
            }
            robot.turnRight();
            direction = (direction + 1) % 4;
        }
    }
    
    void go_back(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
    
    pair<int, int> next_pos(int direction, pair<int, int> pos) {
        switch (direction) {
            case 0: // facing up
                pos.first--;
                break;
            case 1: // facing right
                pos.second++;
                break;
            case 2: // facing bottom
                pos.first++;
                break;
            case 3: // facing left
                pos.second--;
                break;
        }
        return pos;
    }
};
