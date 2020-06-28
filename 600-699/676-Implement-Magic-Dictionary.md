# 673-Implement Magic Dictionary

[Problem](https://leetcode.com/problems/implement-magic-dictionary/)

## Approach 1: Trie -- First Attempt, Complex

Time complexity: O(S) to build and O(K^2) to search, where S is the total number of letters in dict, and K is the length of the search word.

Space complexity: O(S).

```c++
class TrieNode {
public:
    TrieNode() : word_end(false) {
        children = vector<TrieNode*>(26);
    }

    ~TrieNode() {
        for (auto child : children) {
            if (child)
                delete child;
        }
    }

    TrieNode* get(char ch) {
        return children[ch - 'a'];
    }

    void put(char ch, TrieNode* node) {
        children[ch - 'a'] = node;
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
        root = new TrieNode{};
    }

    ~Trie() {
        delete root;
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (auto ch : word) {
            if (!node->get(ch)) {
                node->put(ch, new TrieNode{});
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool modifyExactlyOnceSearch(const string& word) {
        TrieNode* node = root;

        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];

            for (int j = 0; j < 26; j++) {
                char c = 'a' + j;
                if (c == ch)
                    continue;

                TrieNode* curr = node->get(c);
                if (curr && searchHelper(word, i+1, curr))
                    return true;
            }

            node = node->get(ch);
            if (!node)
                return false;
        }

        return false;
    }

private:
    TrieNode* root;

    bool searchHelper(const string& word, int idx, TrieNode* node) {
        for (int i = idx; i < word.size(); i++) {
            node = node->get(word[i]);
            if (!node)
                return false;
        }
        return node->isEnd();
    }
};

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() { }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (auto &word : dict)
            trie.insert(word);
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return trie.modifyExactlyOnceSearch(word);
    }

private:
    Trie trie;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
```

## Appraoch 2: Brute Force with Bucket-By-Length

Time complexity: O(S) to build and O(N * K) to search, where N is the number of words in our magic dictionary, S is the total number of letters in dict, and K is the length of the search word.

Space complexity: O(S).

```c++
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() { }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        v = dict;
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for (auto &w : v) {
            if (isModifiedExactlyOnce(w, word))
                return true;
        }
        return false;
    }

private:
    vector<string> v;

    bool isModifiedExactlyOnce(const string& s1, const string& s2) {
        if (s1.size() != s2.size())
            return false;

        int numDiffs = 0;
        for(int i = 0; i < s2.size(); i++)
        {
            if (s1[i] != s2[i]) {
                numDiffs++;
                if (numDiffs > 1)
                    break;
            }
        }
        return numDiffs == 1;
    }
};
```
