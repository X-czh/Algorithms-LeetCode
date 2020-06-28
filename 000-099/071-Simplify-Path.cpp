// Stack
// Time complexity: O(n).
// Space complexity: O(n).

vector<string> toTokenVector(string str, char delim) {
    vector<string> out;
    istringstream tokenStream(str);
    string token;
    while (getline(tokenStream, token, delim)) {
        out.push_back(token);
    }
    return out;
}

class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty()) {
            return "";
        }

        vector<string> stk;
        for (const auto& directory : toTokenVector(path, '/')) {
            if (directory.empty() || directory == ".") {
                continue;
            } else if (directory == "..") {
                if (!stk.empty()) {
                    stk.pop_back();
                }
            } else {
                stk.push_back(directory);
            }
        }

        string res;
        for (const auto& directory : stk) {
            res += "/";
            res += directory;
        }

        return res.empty() ? "/" : res;
    }
};
