#include <cstring>

class Solution {
public:

    // int memo[11][100000];

    int solve(vector<int>& coins, int amount, int idx, vector<vector<int>>& memo) {
        if(amount == 0) {
            return 0;
        }

        if(idx >= coins.size()) {
            return 1e9;
        }

        if(memo[idx][amount] != -1) {
            return memo[idx][amount];
        }

        // take
        int take = 1e9;
        if(coins[idx] <= amount) {
            take = 1 + solve(coins, amount-coins[idx], idx, memo);
        }

        // skip
        int skip = solve(coins, amount, idx+1, memo);

        return memo[idx][amount] = min(take, skip);
    }


    int coinChange(vector<int>& coins, int amount) {
        // memset(memo, -1, sizeof(memo));
        vector<vector<int>> memo(coins.size()+1, vector<int>(amount+1, -1));
        sort(coins.begin(), coins.end(), greater());

        int res = solve(coins, amount, 0, memo);
        return res == 1e9 ? -1 : res;
    }
};
