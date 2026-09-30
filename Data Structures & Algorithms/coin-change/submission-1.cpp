#include <cstring>

class Solution {
public:

    int memo[11][100000];

    int solve(vector<int>& coins, int amount, int idx) {
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
            take = 1 + solve(coins, amount-coins[idx], idx);
        }

        // skip
        int skip = solve(coins, amount, idx+1);

        return memo[idx][amount] = min(take, skip);
    }


    int coinChange(vector<int>& coins, int amount) {
        memset(memo, -1, sizeof(memo));

        int res = solve(coins, amount, 0);
        return res == 1e9 ? -1 : res;
    }
};
