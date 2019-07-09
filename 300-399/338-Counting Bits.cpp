// Time complexity: O(n)
// Space complexity: O(n)

// Key observation: 
// whenever one more "1" is added in the front, the rest of the bits restart from all zeros to all ones

class Solution {
public:
    vector<int> countBits(int num) {
        assert(num >= 0);
        
        vector<int> result;
        result.reserve(num);
        result.push_back(0);
        
        int exp = 1;
        while (exp <= num) {
            for (auto i = 0; i < exp && exp + i <= num; ++i) {
                result.push_back(1 + result[i]);
            }
            exp *= 2;
        }
        
        return result;
    }
};
