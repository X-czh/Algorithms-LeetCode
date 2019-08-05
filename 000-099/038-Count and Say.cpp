// Time complexity: O(n * 2^n) for each digit can be expanded to at most two digits in the next count_and_say seq
// Space complexity: O(2^n)

class Solution {
public:
    string countAndSay(int n) {
        assert(n >= 1 && n <= 30);

        string str = "1";
        for (auto i = 1; i < n; ++i) {
            string tmp;
            int j = 0;
            while (j < str.size()) {
                int cnt = 1;
                while (j + 1 < str.size() && str[j] == str[j + 1]) {
                    ++cnt;
                    ++j;
                }
                tmp += to_string(cnt) + str[j];
                ++j;
            }
            str = move(tmp);
        }

        return str;
    }
};
