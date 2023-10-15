class Solution {
public:
    long mod = 1e9 + 7;
    int helper(int index, int remaining_steps, int arrLen, vector<vector<int>> &dp){
        if(index == arrLen || index < 0)
            return 0;

        if(remaining_steps == 0){
            if(index == 0)
                return 1;
            return 0;
        }

        if(dp[index][remaining_steps - 1] != -1)
            return dp[index][remaining_steps - 1];

        long stay = helper(index, remaining_steps - 1, arrLen, dp);
        long right = helper(index + 1, remaining_steps - 1, arrLen, dp);
        long left = helper(index - 1, remaining_steps - 1, arrLen, dp);

        return dp[index][remaining_steps - 1] = (stay + right + left)%mod;
    }
    int numWays(int steps, int arrLen) {
        vector dp(steps, vector<int> (steps, -1));
        return helper(0, steps, arrLen, dp);
    }
};

// steps % 2 == 1 then atleast one stay and left == right;
// steps % 2 == 0 then 


