// Time complexity : O(Sum_{k = 1 to N} P(N, k)})
// Space complexity: O(N!)

class Solution {
public:
    vector<vector<int>> permute(vector<int>& num) {
	    vector<vector<int>> result;
	    permuteRec(num, 0, result);
	    return result;
    }
private:
    // permute num[begin..end]
    // invariant: num[0..begin-1] is fixed
	void permuteRec(vector<int>& num, int begin, vector<vector<int>>& result)	{
		if (begin == num.size()) {
		    result.push_back(num);
		    return;
		}

		for (int i = begin; i < num.size(); i++) {
		    swap(num[begin], num[i]);
		    permuteRec(num, begin + 1, result);
		    swap(num[begin], num[i]);
		}
    }
};
