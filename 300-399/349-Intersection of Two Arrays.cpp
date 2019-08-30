// Time complexity: O(n + m).
// Space complexity: O(n + m).

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1;
        for (int num : nums1) s1.insert(num);
        unordered_set<int> s2;
        for (int num : nums2) s2.insert(num);
        
        return set_intersection(s1, s2);
    }
private:
    vector<int> set_intersection(unordered_set<int> s1, unordered_set<int> s2) {
        vector<int> intersection;

        for (int e : s1) {
            auto found = find(s2.begin(), s2.end(), e);
            if (found != s2.end()) {
                intersection.push_back(e);
            }
        }

        return intersection;
    }
};
