class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size(), last = pref[0], curr;
        for(int i = 1 ; i < n ; i++){
            curr = pref[i] ^ pref[i - 1];
            pref[i - 1] = last;
            last = curr;
        }
        pref[n - 1] = last;
        return pref;
    }
};