class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> suff(n, nums[n - 1]), pre(n, nums[0]);
        for(int i = 1 ; i < n ; i++){
            suff[n - i - 1] = max(nums[n - i - 1], suff[n - i]);
            pre[i] = max(pre[i - 1], nums[i]);
        }

        long long maxi = 0;
        for(int j = 1 ; j < n-1 ; j++)
            maxi = max((pre[j - 1] + 0ll - nums[j])*suff[j + 1], maxi);

        return maxi;
    }
};