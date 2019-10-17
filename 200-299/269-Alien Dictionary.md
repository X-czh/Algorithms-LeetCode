# 269-Alien Dictionary

[Problem](https://leetcode.com/problems/alien-dictionary/)

## Approach: Topological Sort

We first build a directed graph out of the given words list, where an edge w->v represents that v is lexicographically larger than w in the alien langauge. We then apply toplogical sort on the graph.

Let N be the number of words, L be the max length of the words, V be the size of the alphabet of the alien langauge (only include those appeard in the words list).

Time complexity: O(N * L) (O(N * L) for building the graph, O(V) for topological sort, V \< N * L).

Space complexity: O(V^2) auxiliary space (O(V^2) for graph, O(V) for indegree/queue).

```c++
class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.size() == 0) return "";
        unordered_map<char, int> indegree;
        unordered_map<char, unordered_set<char>> succ;
        
        // initialize
        for (auto& word : words) {
            for (auto c : word) {
                indegree[c] = 0;
            }
        }
        
        // build graph and record indegree
        for (int i = 0; i < words.size() - 1; i++) {
            string curr = words[i];
            string next = words[i + 1];
            int len = min(curr.size(), next.size());
            for (int j = 0; j < len; j++) {
                if (curr[j] != next[j]) {
                    unordered_set<char>& links = succ[curr[j]];
                    if (links.find(next[j]) == links.end()) {
                        links.insert(next[j]); // build graph
                        indegree[next[j]]++; // add indegree
                    }
                    break;
                }
            }
        }
        
        // topological sort
        string alien_order;
        queue<char> q;
        for (auto& e : indegree) {
            if (e.second == 0) {
                q.push(e.first);
            }
        }
        
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            alien_order += c;
            for (auto d : succ[c]) {
                if (--indegree[d] == 0) q.push(d);
            }
        }
        
        // tell if it is cyclic
        if (alien_order.size() != indegree.size()) return "";
        
        return alien_order;
    }
};
```
