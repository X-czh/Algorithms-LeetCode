// Monotonic Stack
// Time complexity: O(N).
// Space complexity: O(N).

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> s;
        unordered_map<int, int> m;

        for (int num : nums2) {
            while (!s.empty() && num > s.top()) {
                m[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        
        while (!s.empty()) {
            m[s.top()] = -1;
            s.pop();
        }
        
        for (int num : nums1) {
            ans.push_back(m[num]);
        }
        
        return ans;
    }
};
