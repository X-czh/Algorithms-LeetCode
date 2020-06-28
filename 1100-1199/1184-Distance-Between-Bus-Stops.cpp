// Time complexity: O(n).
// Space complexity: O(1).

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        const int N = distance.size();

        int d1 = 0;
        for (int i = start; i != destination; i = (i + 1) % N) {
            d1 += distance[i];
        }
        
        int d2 = 0;
        for (int i = destination; i != start; i = (i + 1) % N) {
            d2 += distance[i];
        }

        return min(d1, d2);
    }
};
