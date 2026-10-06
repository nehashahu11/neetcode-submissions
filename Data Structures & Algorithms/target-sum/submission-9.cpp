class Solution {
    int n;
    int total;
    int fun(int idx,int target,vector<int>& nums, vector<vector<int>>& dp){
        if(idx == n){
            return target == 0;
        }
        // target cannot be represented in our DP table
        if (target < -total || target > total) {
            return 0;
        }
        
        if(dp[idx][target + total] != -1) {
            return dp[idx][target + total];
        }
        int paths = 0;
        
        //take -i
        
        paths += fun(idx+1,target-nums[idx],nums, dp);

        //take +i
        paths += fun(idx+1,target + nums[idx],nums, dp);

        return dp[idx][target + total] = paths;

    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        total = 0;
        for (int x : nums)
            total += x;
        vector<vector<int>> dp(nums.size()+1,vector<int>(2*total + 1,-1));
        return fun(0,target,nums,dp);
    }
};
