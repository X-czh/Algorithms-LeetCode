// Time complexity: O(nlogn)
// Space complexity: O(n) extra space

class Solution1 {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (auto c : s) {
            freq[c]++;
        }
        sort(s.begin(), s.end(), [&freq](char a, char b) 
             { 
                 if (freq[a] == freq[b]) {
                     return a > b;
                 } else {
                     return freq[a] > freq[b];
                 }
             }
        );
        return s;
    }
};

class Solution2 {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (auto c : s) {
            freq[c]++;
        }
        
        map<int, string> ascending_freq;
        for (auto& p : freq) {
            ascending_freq[p.second] += p.first;
        }
        
        string result;
        for (auto it = ascending_freq.rbegin(); it != ascending_freq.rend(); ++it) {
            for (auto c : it->second) {
                result += string(it->first, c); // fill string with arg1 (int) consecutive copies of arg2 (char)
            }
        }
        return result;
    }
};
