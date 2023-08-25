class Solution {
public:
    long mod = 1e9 + 7;
    int dfs(int i, vector<unordered_map<char, int>> &uniqRight, vector<int> &dp, string &s){
        if(dp[i] != -1)
            return dp[i];

        long res = 1;

        for(auto p : uniqRight[i]){
            res = (res + dfs(p.second, uniqRight, dp, s))%mod;
        }

        return dp[i] = res;
    }
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<unordered_map<char, int>> uniqRight(n);
        unordered_map<char, int> mp;
        for(int i = n - 1 ; i >= 0 ; i--){
            uniqRight[i] = mp;
            mp[s[i]] = i;
        }

        vector<bool> vis(26, false);
        vector<int> dp(n, -1);
        long res = 0;
        for(int i = 0 ; i < n ; i++){
            if(!vis[s[i] - 'a']){
                vis[s[i] - 'a'] = true;
                res = (res + dfs(i, uniqRight, dp, s))%mod;
            }
        }

        return res;
        
    }
};