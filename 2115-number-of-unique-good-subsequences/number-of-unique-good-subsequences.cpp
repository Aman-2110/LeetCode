class Solution {
public:
    long mod = 1e9 + 7;

    int dfs(int i, vector<unordered_map<char, int>> &uniqRight, vector<int> &dp, string &s){
        if(dp[i] != -1)
            return dp[i];

        long res = 1;           // ADDING SUBSEBSEQ WITH LENGTH 1

        for(auto p : uniqRight[i]){             // JUMPING TO NEXT UNIQUE ELEMENTS
            res = (res + dfs(p.second, uniqRight, dp, s))%mod;
        }

        return dp[i] = res;
    }

    int numberOfUniqueGoodSubsequences(string s) {
        int n = s.size();
        
        vector<unordered_map<char, int>> uniqRight(n);      
        unordered_map<char, int> mp;
        bool flag = false;

        for(int i = n - 1 ; i >= 0 ; i--){
            uniqRight[i] = mp;
            mp[s[i]] = i;
            if(s[i] == '0')
                flag = true;
        }

        vector<int> dp(n, -1);
        long res = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '1'){
                res = (res + dfs(i, uniqRight, dp, s))%mod;
                break;
            }
        }

        return res + (flag ? 1 : 0);  
    }
};