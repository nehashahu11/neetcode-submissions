class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int n = nums.size();
        for(i=0;i<n-1;i++){
            if(nums[i] == nums[i+1])return true;
        }
        return false;
    }
};