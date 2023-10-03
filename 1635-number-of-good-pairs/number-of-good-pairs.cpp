class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> mp;
        for(int i : nums)   res += mp[i]++;
        return res;
    }
};