class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> maxheap;
        for (int c : nums) {
            maxheap.push(c);
        }
        for (int j=0 ; j< k-1; j++) {
            maxheap.pop();
        }
        int res = maxheap.top();
    return res;     
    }
};
