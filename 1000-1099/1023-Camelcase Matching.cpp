// Time complexity: O(n * m), where n is the number of queries, m is the max length of a query.
// Space complexity: O(1) extra space.

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> answer;
        for (string &query : queries) {
            bool ans = true;
            int idx = 0;
            for (char ch : query) {
                if (idx < pattern.size() && ch == pattern[idx]) {
                    idx++;
                } else if (isupper(ch)) {
                    ans = false;
                    break;
                }
            }
            if (idx < pattern.size()) {
                ans = false;
            }
            answer.push_back(ans);
        }
        return answer;
    }
};
