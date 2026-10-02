class Solution {
    vector<vector<int>> res;
    int n;
public:
    void backtrack(int idx,vector<int>& nums,vector<int>& curr){
        if(idx == n){
            res.push_back(curr);
            return;
        }
        
            //pick element
            curr.push_back(nums[idx]);
            backtrack(idx+1,nums,curr);
            curr.pop_back();

            //not pick
            backtrack(idx+1,nums,curr);
        
    }    
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> curr;
        backtrack(0,nums,curr);
        return res;
    }
};
