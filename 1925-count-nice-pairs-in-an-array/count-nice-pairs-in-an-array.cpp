class Solution {
public:
    int rev(int num){
        int res = 0;
        while(num != 0){
            res *= 10;
            res += (num % 10);
            num /= 10;
        }
        return res;
    }

    int countNicePairs(vector<int>& nums) {
        cin.tie(0)->sync_with_stdio(false);
        long res = 0, mod = 1e9 + 7, n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0 ; i < n ; i++){
            int num = nums[i] - rev(nums[i]);
            res = (res + mp[num]++)%mod;
        }
        return res;
    }
};