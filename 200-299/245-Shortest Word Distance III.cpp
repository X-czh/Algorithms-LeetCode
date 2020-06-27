// Time complexity: O(n).
// Space complexity: O(1).

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        if (word1 == word2) {
            int prev = -1;
            int curr = -1;
            int min_diff = words.size();
            for (int i = 0; i < words.size(); i++) {
                if (words[i] == word1) {
                    if (curr == -1) {
                        curr = i;
                    } else {
                        prev = curr;
                        curr = i;
                        min_diff = min(min_diff, curr - prev);
                    }
                }
            }
            return min_diff;
        }

        int ans = words.size();
        int pos1 = -1;
        int pos2 = -1;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                pos1 = i;
                if (pos2 >= 0) {
                    ans = min(ans, pos1 - pos2);
                }
            } else if (words[i] == word2) {
                pos2 = i;
                if (pos1 >= 0) {
                     ans = min(ans, pos2 - pos1);
                }
            }
        }
        
        return ans;
    }
};
