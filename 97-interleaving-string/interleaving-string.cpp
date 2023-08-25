class Solution {
public:
    bool helper(int i, int j, int k, string &s1, string &s2, string &s3, vector<vector<vector<bool>>> &dp){
        if(k == s3.size())
            return true;

        if(dp[i][j][k])
            return false;

        dp[i][j][k] = true;

        if(i < s1.size() && s1[i] == s3[k]){
            if(helper(i + 1, j, k + 1, s1, s2, s3, dp))
                return true;
        }

        if(j < s2.size() && s2[j] == s3[k]){
            if(helper(i, j + 1, k + 1, s1, s2, s3, dp))
                return true;
        }

        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        vector dp(s1.size() + 1, vector (s2.size() + 1, vector<bool> (s3.size(), false)));
        return helper(0, 0, 0, s1, s2, s3, dp);
    }
};