# Trie (Prefix Tree)

## Overview

A trie (prefix tree) is a search tree tailored for efficient information re**Trie**val. Using Trie, search complexities can be brought to optimal limit (key length). Unlike a binary search tree, no node in the tree stores the key associated with that node; instead, a node stores the letters of an alphabet and the branch path from the root to the node defines the key with which it is associated. All the descendants of a node have a common prefix of the string associated with that node, and the root is associated with the empty string.

![trie](../img/trie.jpg)

## Complexity Analysis

Let M be the key/prefix length.

* Insert:
  * Time complexity: O(M)
  * Space complexity: O(M) to store Trie

* Search:
  * Time complexity: O(M)
  * Space complexity: O(1) extra space

* Prefix Search (startsWith):
  * Time complexity: O(M)
  * Space complexity: O(1) extra space

## Implementation

### Storage of the children of a node

* Use an array of child pointers
* Use a linked list of child nodes
* Use a hash map of child nodes

## Related Problems

* A vairant for the search routine that supports wildcard character: [211-Add and Search Word - Data structure design](./200-299/211-Add%20and%20Search%20Word%20-%20Data%20structure%20design.cpp)

* When the alphabet is simply {0, 1}, it is called a Bitwise Trie: [421-Maximum XOR of Two Numbers in an Array](../400-499/421-Maximum%20XOR%20of%20Two%20Numbers%20in%20an%20Array.md).

## Example: Trie with the lower-case Engligh alphabet

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
    vector<TrieNode*> children;
    bool word_end;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode{};
    }

    ~Trie() {
        delete root;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        for (auto ch : word) {
            if (!curr->get(ch)) {
                curr->put(ch, new TrieNode{});
            }
            curr = curr->get(ch);
        }
        curr->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (word.empty())
            return true;

        TrieNode* curr = root;
        for (auto ch : word) {
            curr = curr->get(ch);
            if (!curr) return false;
        }
        return curr->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (auto ch : prefix) {
            curr = curr->get(ch);
            if (!curr) return false;
        }
        return true;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```
