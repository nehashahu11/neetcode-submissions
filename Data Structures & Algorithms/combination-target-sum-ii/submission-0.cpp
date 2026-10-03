class Solution {
    vector<vector<int>> res;
    int n;
public:
    void backtrack(int idx,vector<int>& candidates,vector<int>& curr, int target){
        if(target == 0){
            res.push_back(curr);
            return;
        }
        if(target<0 || idx >= n){
            return;
        }
        //pick
        curr.push_back(candidates[idx]);
        backtrack(idx+1,candidates,curr,target-candidates[idx]);
        curr.pop_back();

        //not pick
        while(idx+1 < n && candidates[idx] == candidates[idx+1]){
            idx +=1;
        }
        backtrack(idx+1, candidates,curr, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        n = candidates.size();
        sort(candidates.begin(), candidates.end());
        backtrack(0,candidates,curr, target);
        return res;

    }
};
