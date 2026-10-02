class Solution {
    vector<vector<int>> res;
    int n;

   public:
    int sumofcurr(vector<int>& curr){
        int sum =0;
        for(int num : curr){
             sum += num;
        }
        return sum;
    }
    void backtrack(int idx, vector<int>& nums, int target, vector<int>& curr) {
        if(target==0){
            res.push_back(curr);
            return;
        }
        if(target<0 || idx >= nums.size()){
            return;
        }
        //include
        if(nums[idx] <= target){
            curr.push_back(nums[idx]);
            backtrack(idx,nums,target-nums[idx],curr);
            curr.pop_back();

        }
        // exclude
        backtrack(idx+1,nums,target,curr);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        n = nums.size();
        vector<int> curr;
        backtrack(0, nums, target, curr);
        return res;
    }
};
