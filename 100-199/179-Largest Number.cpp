// Time complexity: O(nlogn)
// Space complexity: O(n)

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        assert(nums.size() > 0);
        
        // convert num to string
        vector<string> str_nums;
        for (auto i = 0; i < nums.size(); ++i) {
            str_nums.push_back(to_string(nums[i]));
        }
        
        // KEY: sort with custom comparator
        sort(str_nums.begin(), str_nums.end(), [](string x, string y) {
            return (x + y) > (y + x); // e.g. "3" + "30" > "30" + "3"
        });
        
        // handle special case: all 0s
        if (str_nums.front() == "0") {
            return "0";
        }
        
        // concatenate strings to return
        string s = "";
        for (const auto& str_num : str_nums) {
            s += str_num;
        }
        return s;
    }
};
