class Solution {
    int n;
    vector<vector<int>>res;
public:
    void backtrack(int idx,vector<int>& nums,vector<int>& curr){
        if(idx==n){
            res.push_back(curr);
            return;
        
        }
        //pick
        curr.push_back(nums[idx]);
        backtrack(idx+1,nums,curr);
        curr.pop_back();

        //not take
        while(idx+1 < n && nums[idx]==nums[idx+1]){
            idx +=1;
        }
        backtrack(idx+1,nums,curr);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n = nums.size();
        vector<int>curr;
        backtrack(0,nums,curr);
        return res;
    }
};
