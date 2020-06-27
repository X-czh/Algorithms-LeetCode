// Init: O(n).
// shortest: O(n).
// Space complexity: O(n).

class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            locations[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        auto loc1 = locations[word1];
        auto loc2 = locations[word2];
        
        int i = 0;
        int j = 0;
        int min_diff = numeric_limits<int>::max();
        while (i < loc1.size() && j < loc2.size()) {
            min_diff = min(min_diff, abs(loc1[i] - loc2[j]));
            if (loc1[i] < loc2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return min_diff;
    }
private:
    unordered_map<string, vector<int>> locations;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
