class Solution {
    int n;
    vector<vector<string>> res;

   public:
    bool isValid(string s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void backtrack(int idx, vector<string>& curr, string& s) {
        if (idx == n) {
            res.push_back(curr);
            return;
        }
        for (int i = idx; i < n; i++) {
            if (isValid(s, idx, i)) {
                curr.push_back(s.substr(idx, i - idx + 1));
                backtrack(i + 1, curr, s);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.size();
        vector<string> curr;
        backtrack(0, curr, s);
        return res;
    }
};
