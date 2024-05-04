class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), sum = 0, maxi = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0)
                sum--;
            else
                sum++;

            if(mp.find(sum) == mp.end())
                mp[sum] = i;
            else
                maxi = max(maxi, i - mp[sum]);
        }
        return maxi;
    }
};