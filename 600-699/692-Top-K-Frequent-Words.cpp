// Time complexity: O(nlogk).
// Space complexity: O(n).

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> counts;
        unordered_set<string> wordsSet;
        for (string& word : words) {
            counts[word]++;
            wordsSet.insert(word);
        }
        
        auto cmp = [&](const string& left, const string& right) {
            if (counts[left] == counts[right]) {
                return left > right;
            }
            return counts[left] < counts[right];
        };
        priority_queue<string, vector<string>, decltype(cmp)> heap(cmp);
        for (const string& word : wordsSet) {
            heap.push(word);
        }
        
        vector<string> res;
        for (int i = 0; i < k; i++) {
            res.push_back(heap.top());
            heap.pop();
        }
        return res;
    }
};
