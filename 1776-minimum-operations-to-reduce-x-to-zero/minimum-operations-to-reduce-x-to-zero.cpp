class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> pre(n + 1, 0), suff(n + 1, 0);
        for(int i = 0 ; i < n ; i++){
            pre[i + 1] = pre[i] + nums[i];
            suff[i + 1] = suff[i] + nums[n - 1 - i];
        }

        if(pre[n] < x) 
            return -1;

        int i = 0, mini = INT_MAX;
        while(i <= n && pre[i] <= x){
            int target = x - pre[i];
            auto it = lower_bound(suff.begin(), suff.end(), target);
            if(it != suff.end() && *it == target){
                int ind = it - suff.begin();
                mini = min(i + ind, mini);
            }
            i++;
        }

        return mini == INT_MAX ? -1 : mini;
    }
};