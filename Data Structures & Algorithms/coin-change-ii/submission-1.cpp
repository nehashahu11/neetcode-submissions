class Solution {
    int n;

    int fun(int idx, int amount, vector<int>& coins,
            vector<vector<int>>& dp) {

        // One valid way: use no more coins
        if (amount == 0)
            return 1;

        // No coins left, but amount is still remaining
        if (idx >= n)
            return 0;

        // Already calculated
        if (dp[idx][amount] != -1)
            return dp[idx][amount];

        int paths = 0;

        // Take current coin again
        if (amount >= coins[idx]) {
            paths += fun(idx, amount - coins[idx], coins, dp);
        }

        // Don't take current coin, move to next coin
        paths += fun(idx + 1, amount, coins, dp);

        return dp[idx][amount] = paths;
    }

public:
    int change(int amount, vector<int>& coins) {
        n = coins.size();

        vector<vector<int>> dp(
            n, vector<int>(amount + 1, -1)
        );

        return fun(0, amount, coins, dp);
    }
};