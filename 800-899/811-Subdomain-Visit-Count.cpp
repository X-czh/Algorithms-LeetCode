// Time complexity: O(N), where N is the length of cpdomains, and assuming the length of cpdomains[i] is fixed.
// Space complexity: O(number of subdomains) extra space.

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> subdomain_counts;
        for (const auto &str: cpdomains) {
            // Get the number
            size_t pos = str.find(' ');
            int count = stoi(str.substr(0, pos));
            
            // Get each subdomain
            while (pos != string::npos){
                string subdomain = str.substr(pos + 1, str.size() - pos);
                subdomain_counts[subdomain] += count;
                pos = str.find('.', pos + 1);
            }
        }
        
        vector<string> res;
        for (const auto &p : subdomain_counts) {
            res.push_back(to_string(p.second) + " " + p.first);
        }
        return res;
    }
};
