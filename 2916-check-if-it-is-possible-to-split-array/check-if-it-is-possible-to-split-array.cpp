class Solution {
public:
    bool helper(int i, int j, vector<int> &nums, int m, vector<int> &pre, vector<vector<bool>> &dp){
        if((j - i + 1) <= 2)
            return true;

        if(dp[i][j])
            return false;
        
        dp[i][j] = true;

        if(pre[j] - pre[i] >= m){
            if(helper(i + 1, j, nums, m, pre, dp))
                return true;
        }

        if((i == 0 && pre[j - 1] >= m) || (i != 0 && pre[j - 1] - pre[i - 1] >= m)){
            if(helper(i, j - 1, nums, m, pre, dp))
                return true;
        }

        return false;
    }

    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if(n <= 2)
            return true;
        vector<int> pre(n, nums[0]);
        for(int i = 1 ; i < n ; i++)
            pre[i] = pre[i - 1] + nums[i];

        vector<vector<bool>> dp(n, vector<bool> (n, false));
        return helper(0, n - 1, nums, m, pre, dp);
    }
};