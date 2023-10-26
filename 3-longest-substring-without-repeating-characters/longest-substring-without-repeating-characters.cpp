class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, n = s.size();
        if(n == 0 || n == 1)
            return n;
        unordered_map<char, int> mp;
        mp[s[i]] = i;
        int res = 1;
        for(int j = 1 ; j < n ; j++){
            if(mp.find(s[j]) != mp.end() && mp[s[j]] >= i){
                i = mp[s[j]] + 1;
            }mp[s[j]] = j;
            res = max(res, j - i + 1);
        }
        return res;
    }
};