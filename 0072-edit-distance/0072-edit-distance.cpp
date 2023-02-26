class Solution {
public:
    int helper(string &word1, string &word2, int i, int j, vector<vector<int>> &dp){
        if(i == -1)
            return j + 1;
        else if(j == -1)
            return i + 1;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(word1[i] == word2[j])
            return dp[i][j] = helper(word1, word2, i - 1, j - 1, dp);
        else{
            int ins = helper(word1, word2, i - 1, j, dp);
            int rep = helper(word1, word2, i - 1, j - 1, dp);
            int del = helper(word1, word2, i, j - 1, dp);
            
            return dp[i][j] = 1 + min(ins, min(rep, del));
        }
        
        return -1;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int> (word2.size() , -1));
        return helper(word1, word2, word1.size() - 1, word2.size() - 1, dp);
    }
};