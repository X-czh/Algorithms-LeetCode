// Time complexity: O(Sum(W_i)), where W_i is the length of words[i]. 
//      This is the complexity to build the trie and to search it.
// Space complexity: O(Sum(W_i)) extra space for the trie.

class TrieNode {
public:
    int end; // a nice trick: stores the index of the word in the words vector

    TrieNode() : end(-1) {
        children = vector<TrieNode*>(alphabet_size);
    }

    ~TrieNode() {
        for (auto child : children)
            delete child;
    }

    TrieNode* get(char ch) {
        return children[ch - 'a'];
    }

    void put(char ch, TrieNode* node) {
        children[ch - 'a'] = node;
    }
private:
    static constexpr int alphabet_size = 26;
    vector<TrieNode*> children;
};

class Trie {
public:
    Trie() {
        root = new TrieNode{};
    }

    ~Trie() {
        delete root;
    }

    void insert(string word, int index) {
        TrieNode* curr = root;
        for (auto ch : word) {
            if (!curr->get(ch)) {
                curr->put(ch, new TrieNode{});
            }
            curr = curr->get(ch);
        }
        curr->end = index;
    }
    
    string DFS(vector<string>& words) {
        string ans = "";

        stack<TrieNode*> s;
        for (int i = 25; i >= 0; i--) {
            char ch = 'a' + i;
            TrieNode* next = root->get(ch);
            if (next)
                s.push(next);
        }

        while (!s.empty()) {
            TrieNode* node = s.top();
            s.pop();
            if (node->end >= 0) {
                string word = words[node->end];
                if (word.size() > ans.size())
                    ans = word;
                for (int i = 25; i >= 0; i--) {
                    char ch = 'a' + i;
                    TrieNode* next = node->get(ch);
                    if (next)
                        s.push(next);
                }
            }
        }

        return ans;
    }

private:
    TrieNode* root;
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        int index = 0;
        for (auto &word: words) {
            trie.insert(word, index++);
        }
        return trie.DFS(words);
    }
};
