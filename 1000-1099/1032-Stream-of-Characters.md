# 1032-Stream of Characters

[Problem](https://leetcode.com/problems/stream-of-characters/)

## Approach 1: Prefix Tree

### Idea

Use a prefix tree to store the words, and perform a series of searches with different starting characters (from history queries) for each query. Maintain a history list of pointers to TrieNode that keeps the search trace resulted from history queries. For each query, you do one-step search for the query starting from each of TrieNode stored in the history list. If a search attempt fails, then we get rid of that history record. For example, suppose the words are ['cba', 'bca', 'abc'] and the queries are ['c', 'b', 'a']:

* when proessing the first query 'c', you do one-step search for 'c' from root, get an intenal node 'c_internal1' of the trie, put that into the history list;
* when proessing the second query 'b', you do one-step search for 'b' from root, get an intenal node 'b_internal1' of the trie, put that into the history list, and do another one-step search for 'b' from 'c_internal1', get an intenal node 'c_internal2' of the trie, put that into the history list;
* when proessing the third query 'a', you do one-step search for 'a' from root, do one-step search for 'a' from 'b_internal1', and do another one-step search for 'a' from 'c_internal2'.

### Complexity

N = words.length, M = words[i].length, Q = queries.length.

Time complexity: O(M * Q).

Space complexity: O(N * M) extra space to store the prefix tree. O(M) to store the history queries.

### Solution

```c++
class TrieNode {
public:
    TrieNode() : word_end(false) {
        children = vector<TrieNode*>(alphabet_size);
    }

    ~TrieNode() {
        for (auto child : children) {
            if (child)
                delete child;
        }
    }

    TrieNode* get(char ch) {
        int idx = ch - 'a';
        return children[idx];
    }

    void set(char ch) {
        int idx = ch - 'a';
        children[idx] = new TrieNode();
    }

    bool isEnd() {
        return word_end;
    }

    void setEnd() {
        word_end = true;
    }

private:
    static constexpr int alphabet_size = 26;
    bool word_end;
    vector<TrieNode*> children;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete root;
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->get(ch)) {
                node->set(ch);
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    pair<TrieNode*, bool> search(TrieNode* node, char ch) {
        bool found = false;
        TrieNode* next = node->get(ch);
        if (next && next->isEnd())
            found = true;
        return {next, found};
    }

    TrieNode* root;
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        for (string &word : words) {
            trie.insert(word);
        }
    }

    bool query(char letter) {
        bool answer = false;
        history.push_back(trie.root);
        for (auto i = history.begin(), e = history.end(); i != e;) {
            auto res = trie.search(*i, letter);
            if (res.first) {
                *i = res.first;
                ++i;
            } else {
                i = history.erase(i);
            }
            answer |= res.second;
        }
        return answer;
    }

private:
    Trie trie;
    list<TrieNode*> history;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
```

## Approach 2: Suffix Tree

Use suffix tree instead of prefix tree to allow efficient histroy search, since that works in a backward way.

N = words.length, M = max(words[i].length), M_min = min(words[i].length), Q = queries.length.

Time complexity: O(M * Q), Ω(M_min).

Space complexity: O(N * M) extra space to store the suffix tree. O(M) to store the history queries.

Note that the worst-case time complexity is the same as that of Appraoch 1. However, with Approach 1, you essentially perform a lot of redundant searches with different starting characters for each query, while with this appraoch, you search backwards only once for each query. In practice, this appraoch yields over 2x speed up.

```c++
class TrieNode {
public:
    TrieNode() : word_end(false) {
        children = vector<TrieNode*>(alphabet_size);
    }

    ~TrieNode() {
        for (auto child : children) {
            if (child)
                delete child;
        }
    }

    TrieNode* get(char ch) {
        int idx = ch - 'a';
        return children[idx];
    }

    void set(char ch) {
        int idx = ch - 'a';
        children[idx] = new TrieNode();
    }

    bool isEnd() {
        return word_end;
    }

    void setEnd() {
        word_end = true;
    }

private:
    static constexpr int alphabet_size = 26;
    bool word_end;
    vector<TrieNode*> children;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete root;
    }

    void reverseInsert(const string& word) {
        TrieNode* node = root;
        for (int i = word.size() - 1; i >= 0; i--) {
            char ch = word[i];
            if (!node->get(ch)) {
                node->set(ch);
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool historySearch(deque<char>& history) {
        TrieNode* node = root;
        for (int i = history.size() - 1; i >= 0; i--) {
            node = node->get(history[i]);
            if (!node)
                break;
            if (node->isEnd())
                return true;
        }
        return false;
    }

private:
    TrieNode* root;
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        for (string &word : words)
            trie.reverseInsert(word);
    }

    bool query(char letter) {
        history.push_back(letter);
        if (history.size() > wordLenLimit)
            history.pop_front();

        return trie.historySearch(history);
    }

private:
    Trie trie;
    const int wordLenLimit = 2000;
    deque<char> history;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
```
