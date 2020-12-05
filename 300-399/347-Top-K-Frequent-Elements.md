# 347-Top K Frequent Elements

## Approach 1: Heap

Time complexity: O(nlogk).

Space complexity: O(n + k).

```c++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int n : nums) {
            m[n]++;
        }

        auto cmp = [&m](const pair<int, int>& a, const pair<int, int>& b) { return a.second > b.second; };
        priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        for (const auto& entry : m) {
            pq.push(entry);
            if (pq.size() > k) pq.pop();
        }

        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
```

## Approach 2: Quick Select

TODO
