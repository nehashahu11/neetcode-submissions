class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n ==0) return 0;
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }
        sort(nums.begin(), nums.end());
        int j = 0;
        int count = 1;
        int maxcount = 0;
        int m =0;
        while (m < (n - 1) && (j = m + freq[nums[m]]) <= (n-1)) {
            j = m + freq[nums[m]];
            if (nums[j] - nums[m] == 1) {
                count++;
                m = j;
            } else {
                m = j;
                maxcount = max(maxcount, count);
                count = 1;
            };
        }

      return max(maxcount, count);    
    }
};
