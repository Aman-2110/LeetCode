class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        int mod = 1e9 + 7;
        vector dp(goal + 1, vector<int> (n + 1, 0));
        dp[0][0] = 1;
        for(int i = 1 ; i <= goal ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(j > k)
                    dp[i][j] = (dp[i][j] + (j - k - 0ll)*dp[i - 1][j])%mod;
                
                dp[i][j] = (dp[i][j] + (n - (j - 1ll))*dp[i - 1][j - 1])%mod;
            }
        }

        return dp[goal][n];
    }
};