# 677-Map Sum Pairs

[Problem](https://leetcode.com/problems/map-sum-pairs/)

## Approach: Trie + Hash Map

Since we are dealing with prefixes, a Trie is a natural data structure to approach this problem. For every node of the trie corresponding to some prefix, we will remember the desired answer (score) and store it at this node. To support override existing key-value pairs, this involves modifying each node by val_diff = val - map[key].

Time complexity: Every insert and sum operation is O(K), where K is the length of the key.

Space complexity: Linear in the size of the total input.

```c++
class Node {
public:
    Node() : prefixSum(0) { }

    ~Node() {
        for (auto p : children) {
            delete p.second;
        }
    }

    int prefixSum;
    unordered_map<char, Node*> children;
};

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new Node{};
    }

    ~MapSum() {
        delete root;
    }

    void insert(string key, int val) {
        int val_diff;
        val_diff = val - dict[key];
        dict[key] = val;

        root->prefixSum += val_diff;
        Node* curr = root;
        for (char ch : key) {
            auto found = curr->children.find(ch);
            if (found == curr->children.end()) {
                curr->children.insert({ch, new Node{}});
            }
            curr = curr->children[ch];
            curr->prefixSum += val_diff;
        }
    }

    int sum(string prefix) {
        Node* curr = root;
        for (char ch : prefix) {
            auto found = curr->children.find(ch);
            if (found == curr->children.end()) {
                return 0; // prefix not found
            }
            curr = found->second;
        }
        return curr->prefixSum;
    }

private:
    Node* root;
    unordered_map<string, int> dict;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
```
