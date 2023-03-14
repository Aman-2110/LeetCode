class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, int> mp;
        int curr = 0;
        long count = 0;
        for(int i : nums){
            curr = curr ^ i;
            
            if(curr == 0)
                count++;
            
            count += mp[curr];
            mp[curr]++;
        }
        return count;
    }
};