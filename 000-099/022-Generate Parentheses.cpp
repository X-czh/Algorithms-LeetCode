"""
We can start an opening bracket if we still have one (of n) left to place.
We can start a closing bracket if it would not exceed the number of opening brackets.
"""

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans, "", 0, 0, n);
        return ans;
    }
private:
    void backtrack(vector<string>& ans, string curr, int open, int close, int n) {
        if (curr.size() == n * 2) {
            ans.push_back(curr);
            return;
        }
        
        if (open < n)
            backtrack(ans, curr + "(", open+1, close, n);
        if (close < open)
            backtrack(ans, curr + ")", open, close+1, n);
    }
};
