class Solution {
    vector<vector<int>> dir = {{0,1},{1,0}};
    int path;
public:
    int dfs(int i, int j, int m, int n,vector<vector<int>>& dp){
        if(i== m-1 && j == n-1){
            return dp[i][j] = 1;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int count = 0;
        for(auto& it : dir ){
            int i_ = i + it[0];
            int j_ = j + it[1];
            if(i_<0 || i_ >= m || j_ <0 || j_ >=n) continue;
            count += dfs(i_, j_, m, n, dp);
        }
        return dp[i][j] = count;
    }
    int uniquePaths(int m, int n) {
        path =0;
        vector<vector<int>> dp(m,vector<int>(n,-1));

        path = dfs(0,0,m,n,dp);
        return dp[0][0];
        
    }
};
