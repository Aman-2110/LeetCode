class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = 1e5 + 2;
        vector<int> vec(n, 0);
        for(auto v : requests){
            vec[v[0]]++;
            vec[v[1] + 1]--;
        }
        
        for(int i = 1 ; i < n ; i++)
            vec[i] += vec[i - 1];

        sort(nums.begin(), nums.end(), greater<int> ());
        sort(vec.begin(), vec.end(), greater<int> ());

        long res = 0, mod = 1e9 + 7;

        for(int i = 0 ; i < n ; i++){
            if(vec[i] == 0)
                break;

            res = (res + (nums[i] * 1ll * vec[i]) % mod) % mod;
        }

        return res;
    }
};