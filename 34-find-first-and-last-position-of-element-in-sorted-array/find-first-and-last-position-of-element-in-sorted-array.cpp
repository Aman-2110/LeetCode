class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        if(l == n || nums[l] != target)
            return {-1, -1};
        
        int u = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        return {l, u - 1};
    }
};