// Recursive structure:
//  Base Case:
//      n = 0 => [""]
//      n = 1 => ["0", "1", "8"]
//  Recursive Step for n:
//      For each str in findStrobogrammatic(n - 2), add "1" + str + "1", "6" + str + "9",
//      "9" + str + "6", "8" + str + "8" in the result list. If n is not the the target n,
//      also add "0" + str + "0". 


// Recursive
// Time complexity: O(N * 4^N).
// Spacce complexity: O(N) extra space.
class Solution1 {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> res;
        findStrobogrammaticRec(n, n, res);
        return res;
    }
private:
    void findStrobogrammaticRec(int n, int target_n, vector<string>& res) {
        if (n == 0) {
            res.push_back("");
            return;
        }

        if (n == 1) {
            res.push_back("0");
            res.push_back("1");
            res.push_back("8");
            return;
        }

        findStrobogrammaticRec(n - 2, target_n, res);
        int res_size = res.size();
        for (int i = 0; i < res_size; i++) {
            if (n < target_n) {
                res.push_back(res[i]);
                res.back() = "0" + res.back() + "0";
            }
            res.push_back(res[i]);
            res.back() = "6" + res.back() + "9";
            res.push_back(res[i]);
            res.back() = "8" + res.back() + "8";
            res.push_back(res[i]);
            res.back() = "9" + res.back() + "6";
            res[i] = "1" + res[i] + "1";
        }
    }
};

// Iterative
// Time complexity : O(N * 4^N).
// Spacce complexity: O(1) extra space.
class Solution2 {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> res;
        
        if (n % 2 == 0) {
            res.push_back("");
        } else {
            res.push_back("0");
            res.push_back("1");
            res.push_back("8");
        }

        for (int i = n % 2 + 2; i <= n; i += 2) {
            int res_size = res.size();
            for (int j = 0; j < res_size; j++) {
                if (i < n) {
                    res.push_back(res[j]);
                    res.back() = "0" + res.back() + "0";
                }
                res.push_back(res[j]);
                res.back() = "6" + res.back() + "9";
                res.push_back(res[j]);
                res.back() = "8" + res.back() + "8";
                res.push_back(res[j]);
                res.back() = "9" + res.back() + "6";
                res[j] = "1" + res[j] + "1";
            }
        }

        return res;
    }
};
