class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
    
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<int> dp(n + 1, 0);
        sort(offers.begin(), offers.end(), comp);
        int j = 0;
        for(int i = 1 ; i <= n ; i++){
            while(j < offers.size() && offers[j][1] < i){
                dp[i] = max(dp[i], dp[offers[j][0]] + offers[j][2]);
                j++;
            }
            dp[i] = max(dp[i], dp[i - 1]);
        }

        return dp[n];
    }
};