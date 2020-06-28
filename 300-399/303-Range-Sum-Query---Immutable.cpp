// Time complexity : O(1) time per query, O(n) time pre-computation (the cumulative sum is cached).
// Space complexity : O(n).

Space complexity : O(n)O(n).
class NumArray {
public:
    NumArray(vector<int>& nums) {
        accumulate.push_back(0);
        for (auto i = 1; i < nums.size() + 1; ++i) {
            accumulate.push_back(accumulate[i - 1] + nums[i - 1]);
        }
    }
    
    int sumRange(int i, int j) {
        return accumulate[j + 1] - accumulate[i];
    }
private:
    vector<int> accumulate;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
