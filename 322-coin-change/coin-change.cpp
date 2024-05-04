class Solution {
public:
    int helper(int i, vector<int> &coins, int amount, vector<vector<int>> &dp){
        if(amount == 0)
            return 0;

        if(i == coins.size())
            return 1e4 + 1;

        if(dp[i][amount] != -1)
            return dp[i][amount];

        int notPick = helper(i + 1, coins, amount, dp);
        
        if(amount < coins[i])
            return dp[i][amount] = notPick;
        
        return dp[i][amount] = min(notPick, 1 + helper(i, coins, amount - coins[i], dp));
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        vector<vector<int>> dp(coins.size(), vector<int> (amount + 1, -1));
        int ans = helper(0, coins, amount, dp);
        return ans > 1e4 ? -1 : ans;
    }
};