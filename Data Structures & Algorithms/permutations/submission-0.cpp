class Solution {
    vector<vector<int>> result;
public:
    void backtrack(vector<int>& nums,vector<int>& visited,vector<int>& curr){
        if(curr.size()==nums.size()){
            result.push_back(curr);
            return;
        }
        for(int i=0; i < nums.size(); i++){
            if(!visited[i]){
                curr.push_back(nums[i]);
                visited[i]=true;
                backtrack(nums,visited,curr);
                curr.pop_back();
                visited[i]=false;
            }

        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> visited(nums.size(),false);
        vector<int> curr;
        backtrack(nums,visited,curr);
        return result;
    }
};
