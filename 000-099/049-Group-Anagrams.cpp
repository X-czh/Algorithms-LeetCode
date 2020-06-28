// Time complexity: O(n * k log(k)).
//   n is the length of strs, and k is the maximum length of a string in strs
// Space complexity: O(n k).

// Intuition: 
// Two strings are anagrams if and only if their sorted strings are equal.
// could use counts as well.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        
        unordered_map<string, vector<string>> group;
        for (string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            group[key].push_back(s);
        }
        
        for (auto& elem : group) {
            res.push_back(elem.second);
        }
        return res;
    }
};
