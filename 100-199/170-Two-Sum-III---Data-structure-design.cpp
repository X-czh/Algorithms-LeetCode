// Hash Map
// Time Complexity:
//  add(number): O(1)
//  find(value): O(N) (if use sort + two pointer, then O(NlogN))
// Space Complexity: O(N)

class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        freq_map[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto p : freq_map) {
            int complement = value - p.first;
            if (complement == p.first) {
                if (p.second >= 2)
                    return true;
            } else {
                auto found = freq_map.find(complement);
                if (found != freq_map.end())
                    return true;
            }
        }
        return false;
    }
private:
    unordered_map<int, int> freq_map;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
