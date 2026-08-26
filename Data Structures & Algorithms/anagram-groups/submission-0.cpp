class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> temp = strs;
        int n= temp.size();
        for( string& s : temp){
            sort(s.begin(),s.end());
        }
        // sort(temp.begin(), temp.end());
        unordered_map<string,vector<string>> mp;
        for(int i =0; i <n; i++){
            mp[temp[i]].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for(auto& [key,value]:mp){
            result.push_back(value);

        }
        return result;
    }
};
