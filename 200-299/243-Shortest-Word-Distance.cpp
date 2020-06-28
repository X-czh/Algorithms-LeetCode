// Time complexity: O(n).
// Space complexity: O(1).

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
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
