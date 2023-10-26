class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        long mod = 1e9 + 7;
        unordered_map<int, int> mp;
        for(int i = 0 ; i < n  ; i++){
            mp[arr[i]] = i;
        }
        unordered_set<int> st(arr.begin(), arr.end());
        vector<long> dp(arr.size(), 1);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(arr[i] % arr[j] == 0 && st.find(arr[i] / arr[j]) != st.end()){
                    dp[i] = (dp[i] + (dp[j]*dp[mp[arr[i]/arr[j]]])%mod)%mod;
                }
            }
        }

        long res = 0;
        for(long i : dp)
            res = (res + i)%mod;

        return res;
    }
};

// 2, 4, 8, 16

// 2, 2 = 4
// 2, 4 = 8
// 4, 2 = 8
// 2, 8 = 16
// 4, 4 = 16
// 8, 2 = 16


// 2 = 1
// 4 = 1 + 1 = 2
// 8 = 1 + 1*2 + 1*2 = 5
// 16 = 1 + 1*5 + 2*2 + 5*1 = 15