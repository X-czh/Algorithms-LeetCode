// Dynamic Programming
// Time complexity: O(n^2).

// In-place solution
// Time complexity in this implementation: O(n * nlogn).
// Space complexity: O(1) extra space.
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int ans = 0;

        for (int i = 1; i < arr.size(); i++) {
            // not sure why I cannot create minHeap directly from a vector,
            // otherwise the time complexity would be O(n^2)
            priority_queue<int, std::vector<int>, std::greater<int>> pq;
            for (int n : arr[i-1]) {
                pq.push(n);
            }
            int smallest = pq.top();
            pq.pop();
            int second_smallest = pq.top();

            for (int j = 0; j < arr[i].size(); j++) { 
                int minPathSum = arr[i-1][j] == smallest ?
                    second_smallest : smallest;
                arr[i][j] += minPathSum;
            }
        }

        return *min_element(arr.back().begin(), arr.back().end());
    }
};
