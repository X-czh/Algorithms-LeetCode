// Time complexity: O(1)
// Space complexity: O(1)

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long total = long{C-A} * long{D-B} + long{G-E} * long{H-F};

        if (C <= E || A >= G || B >= H || D <= F) {
            return total;
        } else {
            vector<int> h{A, C, E, G};
            vector<int> v{B, D, F, H};
            sort(h.begin(), h.end());
            sort(v.begin(), v.end());
            total -= long{h[2] - h [1]} * long{v[2] - v[1]};
            return total;
        }
    }
};
