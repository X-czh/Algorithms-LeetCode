// Use variant of Trie

// insert:
// Time complexity: O(m), m is max str len

// search:
// Time complexity: O(n*m), n is alphabet size

class TrieNode {
public:
    TrieNode() : word_end(false) {
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

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode{};
    }
    
    ~WordDictionary() {
        delete root;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *curr = root;
        for (auto ch : word) {
            if (!curr->get(ch)) 
                curr->put(ch, new TrieNode{}); 
            curr = curr->get(ch);
        }
        curr->setEnd();
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        if (word.empty())
            return true;
        return searchHelper(word, 0, root);
    }
private:
    TrieNode* root;

    bool searchHelper(const string& word, int idx, TrieNode* curr) {
        if (!curr)
            return false;

        if (idx == word.size())
            return curr->isEnd();        

        char ch = word[idx];
        if (ch != '.') {
            return searchHelper(word, idx+1, curr->get(ch));
        } else {
            for (auto j = 0; j < 26; j++) {
                char letter = 'a' + j;
                if (searchHelper(word, idx+1, curr->get(letter)))
                    return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
