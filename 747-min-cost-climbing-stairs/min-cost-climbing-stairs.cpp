class Solution {
public:
    int helper(int i, vector<int> &cost, vector<int> &dp){
        if(i >= cost.size())
            return 0;

        if(dp[i] != -1)
            return dp[i];

        return dp[i] = cost[i] + min(helper(i + 1, cost, dp), helper(i + 2, cost, dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        return min(helper(0, cost, dp), helper(1, cost, dp));
    }
};