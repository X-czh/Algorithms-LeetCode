// Time complexity: O(n)
// Space complexity: O(1) extra space.

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> cnt(5, 0); // "balon"
        for (char c : text) {
            switch (c) {
                case 'b':
                    ++cnt[0];
                    break;
                case 'a':
                    ++cnt[1];
                    break;
                case 'l':
                    ++cnt[2];
                    break;
                case 'o':
                    ++cnt[3];
                    break;
                case 'n':
                    ++cnt[4];
                    break;
            }
        }
        
        cnt[2] /= 2;
        cnt[3] /= 2;
        
        int min_cnt = cnt[0];
        for (int n : cnt) {
            min_cnt = min(n, min_cnt);
        }
        
        return min_cnt;
    }
};
