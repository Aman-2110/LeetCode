class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        int mod = 1e9 + 7;
        vector<int> curr(n + 1, 0), prev(n + 1, 0);
        prev[0] = 1;
        for(int i = 1 ; i <= goal ; i++){
            for(int j = 1 ; j <= n ; j++){
                curr[j] = ((n - (j - 1ll))*prev[j - 1])%mod;

                if(j > k)
                    curr[j] = (curr[j] + (j - k - 0ll)*prev[j])%mod;
            }
            prev = curr;
        }

        return prev[n];
    }
};