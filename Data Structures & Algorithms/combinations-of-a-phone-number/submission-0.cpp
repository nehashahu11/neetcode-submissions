class Solution {
    int n;
public:
    void backtrack(int idx,vector<string>& res,string curr,vector<vector<char>>& mp, string& digits){
        if(curr.size() == n){
            res.push_back(curr);
            return;
        }
        char d = digits[idx];

        for(char c : mp[d-'0']) {
            curr.push_back(c);
            backtrack(idx+1, res, curr, mp, digits);
            curr.pop_back();
        }

        return;

    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        vector<vector<char>> mp{
            {},
            {},
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j','k','l'},
            {'m', 'n', 'o'},
            {'p','q','r','s'},
            {'t', 'u', 'v'},
            {'w','x','y','z'}
        };

        string curr;
        n = digits.size();
        if(n == 0) return {};
        backtrack(0,res,curr,mp,digits);
        return res;

    }
};
