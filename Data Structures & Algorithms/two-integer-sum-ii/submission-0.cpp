class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> mp;
        int n = numbers.size();
        int j=0;
        for(int i =0;i<n; i++){
            j = target - numbers[i];
            if( mp.find(j) != mp.end())
                return {mp[j]+1,i+1};
            else mp[numbers[i]]=i;
        }
        
    }
};
