class Solution {
public:
    using size_type = string::size_type;

    vector<string> letterCombinations(string digits) {
        if (digits.size() != 0)
            backtrack("", digits, 0);
        return output;
    }
private:
    vector<string> output;
    vector<string> phone = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void backtrack(const string& combination, const string& digits, size_type i) {
        if (i == digits.size()) {
            output.push_back(combination);
        } else {
            char digit = digits[i];
            string letters = phone[size_type{digit - '2'}];
            for (auto letter : letters) {
                backtrack(combination + letter, digits, i + 1);
            }
        }
    }
};
