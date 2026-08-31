class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int n = nums.size();

        for (auto& val : nums) {
            mp[val]++;
        }

        // <freq, val>
        priority_queue<pair<int, int>> pq;

        for(auto& [val, freq] : mp) {
            pq.push({freq, val});
        }
        vector<int> result;
        while(k > 0) {
            auto [freq, val] = pq.top();
            pq.pop();

            result.push_back(val);
            k--;


            // auto x = pq.pop();
            // int freq = x.first;
            // int val = x.second;
        }

        return result;


    }
};
