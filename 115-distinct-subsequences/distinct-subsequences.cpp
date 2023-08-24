class Solution {
public:
    int helper(string &s, string &t, int i, int j, vector<vector<int>> &dp){
        if(j == t.size())
            return 1;
        if(i == s.size())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int notPick = helper(s, t, i + 1, j, dp);
        int pick = 0;
        if(s[i] == t[j]){
            pick = helper(s, t, i + 1, j + 1, dp);
        }

        return dp[i][j] = pick + notPick;
    }
    int numDistinct(string s, string t) {
        vector dp(s.size(), vector<int> (t.size(), -1));
        return helper(s, t, 0, 0, dp);
    }
};