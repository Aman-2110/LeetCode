class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> que;
        vector<int> dp(n);
        int ans = nums[0];
        for(int i = 0 ; i < n ; i++){
            int t = 0;
            while(!que.empty()){
                if(i - que.top().second <= k){
                    t = max(t, que.top().first);
                    break;
                }else
                    que.pop();
            }

            dp[i] = nums[i] + t;
            ans = max(dp[i], ans);
            que.push({dp[i], i});
        }

        return ans;
    }
};