class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> que;
        vector<int> dp(n);
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

            que.push({dp[i], i});
        }

        return *max_element(dp.begin(), dp.end());
    }
};