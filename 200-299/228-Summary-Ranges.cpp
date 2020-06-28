// Time complexity: O(n)
// Space complexity: O(n), no additional space overhead besides the return valus

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        const int N = nums.size();
        vector<string> ranges;
        
        int left = 0;
        int right = 0;
        while (right < N) {
            while (right + 1 < N && nums[right + 1] == nums[right] + 1) ++right;
            
            string range{to_string(nums[left])};
            if (left != right) {
                range += "->";
                range += to_string(nums[right]);
            }
            ranges.push_back(range);
            
            left = right + 1;
            right = left;
        }
        
        return ranges;
    }
};
