class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        cin.tie(0)->sync_with_stdio(false);
        int n = nums.size(), pre = nums[0], suf = nums[n - 1];
        vector<int> pref(n), suff(n), res(n);
        for(int i = 1 ; i < n ; i++){
            pref[i] = pre;
            suff[n - i - 1] = suf;
            suf += nums[n - i - 1];
            pre += nums[i];
        }

        for(int i = 0 ; i < n ; i++){
            // res[i] = nums[i] * i - pref[i] + suff[i] - nums[i] * (n - i - 1);
            res[i] = nums[i] * (2*i - n +  1) + suff[i] - pref[i];
        }

        return res;
    }
};