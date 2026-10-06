class Solution {
    vector<vector<int>> dir = {{0,1},{1,0}};

public:
    int dfs(int i, int j, int m, int n,vector<vector<int>>& dp){
        if(i== m-1 && j == n-1){
            return 1;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int paths = 0;
        for(auto& it : dir ){
            int i_ = i + it[0];
            int j_ = j + it[1];
            if(i_<0 || i_ >= m || j_ <0 || j_ >=n) continue;
            paths += dfs(i_, j_, m, n, dp);
        }
        return dp[i][j] = paths;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return dfs(0,0,m,n,dp);
        
    }
};
